/** @file ps02-semaphore.cpp
 * @brief Problem Set 02 Problem #2.
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Example of using posix semaphore to fix the concurrency issues with
 * the problem set 02 posix threads example.
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

using namespace std;


// global variables, accessible by and shared by all threads
int myglobal = 0;

// global semaphore lock.  The sem_t is a counting semaphore, but annoyingly
// it is a weak semaphore, not a strong semaphore, thus it will not queue
// up processes and dequeue them in the order they wait on the semaphore
sem_t lock;


/**
 * @brief thread function
 *
 * Code run in second thread created by this process.  Update
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
  int i;
  int j;

  for (i = 0; i < 20; i++)
  {
    // obtain lock before entering critical section
    sem_wait(&lock);

    // critical section
    j = myglobal;
    j = j + 1;
    cout << ".";
    cout << flush; // flush output immediatly so we see true sequence of interleavings
    // bad critical section, we are staying for a long time in computer time in the crit sec
    sleep(1); // sleep for 1 second
    myglobal = j;

    // exit critical section, so release the lock
    sem_post(&lock);
  }

  return NULL;
}


/**
 * @brief thread function 1
 *
 * Code originally in the main() thread.  We can't set SCHED_FIFO attribute on
 * main thread, so to demonstrate strong semaphore need to run that code now
 * as a thread we create with pthread_create
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
  int i;

  for (i = 0; i < 20; i++)
  {
    // obtain lock before entering critical section
    sem_wait(&lock);

    // critical section
    myglobal = myglobal + 1;
    cout << "o";
    cout << flush;  // flush output immediatly so we see true sequence of interleavings
    sleep(1);  // sleep for 1 second

    // exit critical section, so release the lock
    sem_post(&lock);
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
  pthread_t mythread;
  pthread_t mythread2;

  // initialize semaphore before using, the second parameter 0 indicates the
  // semaphore is shared and used by threads in this same process, and the third
  // parameter 1 is the initiale value of our semaphore count indicating that the
  // lock is initialy available to be locked
  sem_init(&lock, 0, 1);


  // start the first thread
  if (pthread_create(&mythread, NULL, thread_function0, NULL) != 0)
  {
    cerr << "error creating thread 0" << endl;
    abort();
  }

  // start the second thread
  if (pthread_create(&mythread2, NULL, thread_function1, NULL) != 0)
  {
    cerr << "error creating thread 1" << endl;
    abort();
  }



  // now wait for the threads to end
  if (pthread_join(mythread, NULL))
  {
    cerr << "error joining thread." << endl;
    abort();
  }
  if (pthread_join(mythread2, NULL))
  {
    cerr << "error joining thread." << endl;
    abort();
  }

  cout << endl;
  cout << "myglobal equals " << myglobal << endl;

  // return 0 to indicate successful completion
  return 0;
}