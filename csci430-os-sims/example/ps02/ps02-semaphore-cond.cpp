/** @file ps02-semaphore-cond.cpp
 * @brief Problem Set 02 Problem #2.
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Example of a strong semaphore.  Since posix semaphores are not strong
 * semaphores, we show example of creating our own using posix mutex
 * mechanism and an STL queue.  Windows doesn't really have posix signals.
 * So instead of using signals, use posix condition variables instead to perform
 * the blocking and signaling.
 *
 * Example of using posix semaphore to fix the concurrency issues with
 * the problem set 02 posix threads example.  It doesn't seem that there is
 * a strong semaphore easily available in posix semaphores.  But we can use
 * a semaphore and an STL queue with some condition variables to implement our
 * own strong queueing discipline.
 *
 * Example of using posix threads. Possible concurrency issue with
 * code implementation. Program executes 2 threads concurrently
 * using POSIX pthread library.  The original main() function
 * executes in the initial thread created when the process is
 * executed.  The pthread_create() function from the pthread library
 * causes a second thread to be created within the process.
 * This second thread runs the code found in the thread_function().
 */
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;


// global variables and constants, accessible by and shared by all threads
int myglobal = 0;
const int NUM_LOOPS = 20;


// global array of thread structs
const int NUM_THREADS = 2;
pthread_t threads[NUM_THREADS];


/** roll our own counting semaphore with a queue so we can enforce a strong
 * queueing discipline
 */
struct strong_sem_t
{
  // semaphore count, if negative the abs(count) is number of
  // processes waiting on queue
  int count;

  // Use a mutex to enforce mutual exclusion of the wait and signal functions
  // for our strong counting semaphore
  pthread_mutex_t mutex;

  // Use a posix condition variable for signaling.  If we have the mutex locked,
  // then we can wait on the condition variable.  Thus unlocks the mutex and
  // blocks the process that waits on the condition variable instead.
  pthread_cond_t condition[NUM_THREADS];

  // use STL queue to keep queue of threads waiting on semaphore
  queue<int> waitQueue;
};


// The global semaphore structure we will use to manage our threads
strong_sem_t sem;


/** semaphore init
 * Initialize our hand made semaphore.
 *
 * @param sem A pointer to a strong_sem_t structure that we
 *   are to initialize.
 * @param count The initial value for the semaphore count we should
 *   set.  Normally set to 1 to indicate an unlocked semaphore that only
 *   allows 1 process at a time into the critical section it guards.
 */
void semInit(strong_sem_t* sem, int count)
{
  // initialize the count
  sem->count = count;

  // initialize the mutex
  if (pthread_mutex_init(&sem->mutex, NULL) != 0)
  {
    cerr << "Error: mutex init has failed" << endl;
    exit(1);
  }

  // initialize the condition variable
  for (int threadId = 0; threadId < NUM_THREADS; threadId++)
  {
    sem->condition[threadId] = PTHREAD_COND_INITIALIZER;
  }
}


/** semaphore wait
 * Implementation of our own semaphore wait function to implement a strong
 * strict queuing discipline to enter the semaphore.  Compare this to our
 * textbook pseudocode of the semWait function.
 *
 * We use an internal mutex to create a critical section that is this whole
 * function.  Semaphore wait decrements the count, and if the count has become,
 * negative, the process is put on the semaphore wait queue and is blocked.
 * We implement blocking by using condition variables.  This thread will wait on
 * the condition variable.  When we wait on a condition variable, the thread
 * is blocked until it receive a broadcast signal on the condition, and the
 * mutex we have locked is unlocked by the process of waiting on the condition.
 *
 * @param sem A pointer to a strong_sem_t structure that contains the
 *   semaphore count and other variables we use internally.
 * @param threadId  Each thread using our strong_sem_t must be assigned a
 *   unique threadId.  If the thread that calls semWait blocks, its threadId
 *   is pushed on the wait queue.  The threadId also indexes the global
 *   threads[] array so we can correctly call pthread_kill() in semSignal on
 *   the blocking thread removed from the head of the wait queue.
 */
void semWait(strong_sem_t* sem, int threadId)
{
  // the whole function is a critical section, we protect with a simple
  // mutual exclusion lock/unlock mechanism
  pthread_mutex_lock(&sem->mutex);

  //cout << "semWait called by threadId: " << threadId << endl;
  //cout << flush;

  // decrement the semaphore count
  sem->count--;

  // if count is now negative, process must block.
  if (sem->count < 0)
  {
    // put the process on the wait queue
    sem->waitQueue.push(threadId);

    // the calling thread will now block in this function until a
    // broadcast signal on the condition is received.  Calling the cond_wait
    // causes the mutex to available to be locked (which is what we want),
    // but we should still call unlock after we unblock from this wait.
    pthread_cond_wait(&sem->condition[threadId], &sem->mutex);
  }

  // exit critical section
  pthread_mutex_unlock(&sem->mutex);
}


/** semaphore signal
 * Implementation of our own semaphore signal function to implement a strong
 * strict queueing discipline semaphore.  Compare this implementation to the
 * textbook pseudocode of the semaphore signal function.
 *
 * The semaphore signal increments the counting semaphore count.  If the count
 * is still negative or 0, that means process(es) are currently blocked and
 * waiting on the semaphore.  If processes are blocked, we get the next process
 * from the head of the wait and brodcast it a condition signal to wake it up.
 *
 * @param sem A pointer to a strong_sem_t structure that holds the semaphore
 *   count and other variables used in our strong semaphore implementation.
 */
void semSignal(strong_sem_t* sem)
{
  // the whole function is a critical section, we protect with a simple
  // mutual exclusion lock/unlock mechanism
  pthread_mutex_lock(&sem->mutex);

  //cout << "semSignal called " << endl;
  //cout << flush;

  // increment the semaphore count
  sem->count++;

  // if the count is less than or equal to 0 that means there are processes
  // waiting on the queue
  if (sem->count <= 0)
  {
    // get the thread id from the front of the wait queue and remove item from queue
    int threadId = sem->waitQueue.front();
    sem->waitQueue.pop();

    //cout << "  semSignal waking up blocked threadId: " << threadId << endl;
    //cout << flush;

    // send a broadcast signal on the condition variable to wake up thread
    // blocked on this condition
    pthread_cond_signal(&sem->condition[threadId]);
  }

  // exit critical section
  pthread_mutex_unlock(&sem->mutex);
}


/**
 * @brief thread function 0
 *
 * Code run in first thread created by this process.  This was the original
 * thread_function() code in the problem set. Update
 * the myglobal variable and get some sleep.
 *
 * @param arg A function created to run in a new thread accepts
 *   a pointer to an arbitrary sturcture that may be used to
 *   initialize values internally in the thread.  We do not use
 *   this arg in this example.
 *
 * @returns void* Likewise when thread is finished it can return
 *   some status information.  We always return NULL.
 */
void* thread_function0(void* arg)
{
  int threadId = 0;
  int i;
  int j;

  for (i = 0; i < NUM_LOOPS; i++)
  {
    // obtain lock before entering critical section
    semWait(&sem, threadId);

    // critical section
    j = myglobal;
    j = j + 1;
    //cout << "0 runs" << endl;
    cout << ".";
    cout << flush; // flush output immediatly so we see true sequence of interleavings
    // bad critical section, we are staying for a long time in computer time in the crit sec
    sleep(1); // sleep for 1 second
    myglobal = j;

    // exit critical section, so release the lock
    semSignal(&sem);
  }

  return NULL;
}


/**
 * @brief thread function 1
 *
 * Code originally in the main() thread. We need to set up signal handling
 * on thread level for this example of a strong semaphore.  So we had to
 * move this code to a explicit thread rather than reusing the main() thread.
 *
 * @param arg A function created to run in a new thread accepts
 *   a pointer to an arbitrary sturcture that may be used to
 *   initialize values internally in the thread.  We do not use
 *   this arg in this example.
 *
 * @returns void* Likewise when thread is finished it can return
 *   some status information.  We always return NULL.
 */
void* thread_function1(void* arg)
{
  int threadId = 1;
  int i;

  for (i = 0; i < NUM_LOOPS; i++)
  {
    // obtain lock before entering critical section
    semWait(&sem, threadId);

    // critical section
    myglobal = myglobal + 1;
    //cout << "1 runs" << endl;
    cout << "o";
    cout << flush;   // flush output immediatly so we see true sequence of interleavings
    sleep(1);  // sleep for 1 second

    // exit critical section, so release the lock
    semSignal(&sem);
  }

  return NULL;
}


/**
 * @brief main entry
 *
 * Main entry point of process when run.  Code execution starts here.
 * Whenever a process is created, it is initially created with a single
 * thread.  The main() function starting point is the code that
 * will initially be executing in the initial thread.
 *
 * @param argc The count of the number of arguments on the command line.
 * @param argv[] An array of char* strings, the command line arguments
 *   provided by the user when this program is run.
 *
 * @returns int Returns a status/exit code.  0 means normal termination.
 */
int main(int argc, char* argv[])
{
  // initialize semaphore before using.  This is our hand-made semaphore
  // structure.  Second parameter is the initial count of the semaphore.
  // A 1 indicates the semaphore is initially unlocked.
  semInit(&sem, 1);

  // start the first thread (threadId 0)
  if (pthread_create(&threads[0], NULL, thread_function0, NULL) != 0)
  {
    cerr << "error creating thread 0" << endl;
    abort();
  }

  // start the second thread (threadId 1), originally the main() function thread
  if (pthread_create(&threads[1], NULL, thread_function1, NULL) != 0)
  {
    cerr << "error creating thread 1" << endl;
    abort();
  }

  // now wait for the threads to end
  for (int threadId = 0; threadId < NUM_THREADS; threadId++)
  {
    if (pthread_join(threads[threadId], NULL))
    {
      cerr << "error joining thread." << endl;
      abort();
    }
  }

  cout << endl;
  cout << "myglobal equals " << myglobal << endl;

  // return 0 to indicate successful completion
  return 0;
}