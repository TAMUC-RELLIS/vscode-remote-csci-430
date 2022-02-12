/** @file amdhals-law.cpp
 * @brief Example of speedup gains from N parallel threads.
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Example of Amdhal's Law in practice.  Amdhal's law states that
 * the expected speedup of dividing a task into N parallel threads of
 * work, where some fraction f of the task is parallelizable, but
 * some fractions s = 1-f is inherently serial and cannot be
 * parallelized is:
 *
 *            speedup = 1 / (s + f/N)
 *
 * This is not to hard to derive from first principles.  For Example
 * if a task takes 100 seconds to execute on a single processor, and
 * if 88% of the program can be made parallel while 12% is inherently
 * serial.  Then that means 12 seconds has to run in serial, but the
 * 88% or 88 seconds of time can be broken into separate parallel
 * threads of work.  If N=8 that means we could do the original
 * work of 88 seconds in 88/8 = 11 seconds.  Thus the total time for
 * the parallel version is 12 + (88/8) = 23 seconds.  The speedup is
 * thus 100 / 23 for N=8 threads of work, or
 *
 *         speedup = 100 / 23 = 4.3478 = 1/(0.12 + 0.88/8)
 */
#include <pthread.h>
#include <chrono>
#include <cmath>
#include <iostream>

using namespace std;


// A small structure we use to pass in multiple parameter so thread workers
// we create
struct WorkerData
{
  int workerId;
  string workerName;
  int amountOfWorkForWorker;
};


/** do work
 * Our task, sum up the numbers from 1 to 10000000
 */
void doWork()
{
  int sum = 0;

  for (int i = 1; i <= 1000000; i++)
  {
    sum += i;
  }
}


/** worker
 * Function that runs in threads to simulate workers performing some
 * work.
 */
void* worker(void* arg)
{
  const int CHECKPOINT = 100; // show status every checkpoint units of work
  WorkerData* workerData = (WorkerData*) arg;

  cout << "Worker <" << workerData->workerName << "> started" << endl
       << "-------------------------------------------------" << endl
       << "threadid : " << workerData->workerId << endl
       << "amount of work for worker to do: " << workerData->amountOfWorkForWorker << endl
       << endl << endl;

  // do the work we were asked to do
  for (int workId = 1; workId <= workerData->amountOfWorkForWorker; workId++)
  {
    doWork();
    if (workId % CHECKPOINT == 0)
    {
      cout << "<" << workerData->workerName << "> checkpoint: " << workId << endl;
    }
  }
  cout << "<" << workerData->workerName << "> has finished my work, "
       << workerData->amountOfWorkForWorker << " work units completed" << endl;

  return NULL;
}


/** simulate work with N workers
 * Simulate performing some amoutn of work with N parallel workers. To
 * simulate a serial task, set number of workers N to 1 and fraction of work
 * that is parallel to 0.0;
 *
 * @param N Number of parallel workers to work on tasks.  If N is 1 we will
 *   simulate a serial task with no parallel speedup.
 * @param f The fraction of the work that is parallelizable.  If f is 0.0 we
 *   wil simulate a serial task with no parallel speedup.
 * @param amountOfWork The total amount of simulated work to perform.
 *
 * @returns Returns the amount of wallclock time it takes to perform the
 *   work we were asked to do.
 */
double simulateWorkWithNWorkers(int N, double f, int amountOfWork)
{
  // use ratio of parallelization to determine amount of work that can
  // be parallelized
  int amountOfWorkForParallelWorkers = f * amountOfWork;

  // the remaining work must be done in serial by a single worker
  int amountOfWorkForSerialWorker = amountOfWork - amountOfWorkForParallelWorkers;

  // determine work for each worker, we divide as evently as possible, but to
  // be conservative on our empirical experiment we round up so all workers do
  // equal work, and the total work plus that of the serial worker will be
  // equal to or grater than the amountOfWork
  int amountOfWorkForEachWorker = ceil(float(amountOfWorkForParallelWorkers) / float(N));

  // total amount of work we will do, so we can compare with what we were asked
  // to do
  int totalWorkToDo = amountOfWorkForSerialWorker + (N * amountOfWorkForEachWorker);

  // summarize what we will do
  cout << "Simulate Work with number of workers       : " << N << endl
       << "    Fraction of work parallelizable        : " << f << endl
       << "    Total amount of work to perform        : " << amountOfWork << endl
       << "    Amount of work for serial worker       : " << amountOfWorkForSerialWorker << endl
       << "    Amount of work for each parallel worker: " << amountOfWorkForEachWorker << endl
       << "    Sum of the work to be done             : " << totalWorkToDo << endl
       << endl << endl;


  // we will time the total elapsed time to complete all work plus overhead of
  // creating threads
  auto start = chrono::steady_clock::now();

  // first perform the serial work, create a single worker to perform their
  // work, and wait for them to finish
  pthread_t serialworker;
  WorkerData* serialWorkerData = new WorkerData;
  serialWorkerData->workerId = 1;
  serialWorkerData->workerName = "Serial Worker";
  serialWorkerData->amountOfWorkForWorker = amountOfWorkForSerialWorker;

  if (pthread_create(&serialworker, NULL, worker, (void*)serialWorkerData) != 0)
  {
    cerr << "Error: creating serial worker thread" << endl;
    abort();
  }

  if (pthread_join(serialworker, NULL))
  {
    cerr << "Error: joining back with serial worker thread." << endl;
    abort();
  }


  // then perform the parallel workers work, if the amount of work per worker is 0
  // because task cannot be parallelized we skip this step
  if (amountOfWorkForEachWorker > 0)
  {
    // dynamically allocate array to hold worker threads
    pthread_t* parallelWorker = new pthread_t[N];

    // create N workers
    for (int workerId = 0; workerId < N; workerId++)
    {
      WorkerData* parallelWorkerData = new WorkerData;
      parallelWorkerData->workerId = workerId;
      parallelWorkerData->workerName = "Parallel Worker <" + to_string(workerId) + ">";
      parallelWorkerData->amountOfWorkForWorker = amountOfWorkForEachWorker;

      if (pthread_create(&parallelWorker[workerId], NULL, worker, (void*)parallelWorkerData) != 0)
      {
        cerr << "Error: creating parallel worker thread " << workerId << endl;
        abort();
      }
    }

    // wait for all N workers to finish
    for (int workerId = 0; workerId < N; workerId++)
    {
      if (pthread_join(parallelWorker[workerId], NULL))
      {
        cerr << "Error: joining back with serial worker thread" << workerId << endl;
        abort();
      }
    }
  }

  // we have finished work
  auto end = chrono::steady_clock::now();

  double elapsed = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000.0;

  // return the amount of time it took to do the work
  return elapsed;
}


/** usage information
 * Display usage/help information for command line use of this program.
 *
 */
void usage()
{
  // display usage and exit
  cout << "Usage: ex work N f" << endl
       << "This program demonstrates the speedup predicted by Amdhal's" << endl
       << "law.  Program simulates running N threads of work in parallel" << endl
       << "and calculates the empirical speedup seen from the" << endl
       << "parallelization of the task." << endl
       << endl
       << "work  An integer value, the amount of simulated 'work' to perform" << endl
       << "N     The number of worker threads to create and perform" << endl
       << "      work in parallel." << endl
       << "f     The fraction of the task that is parallelizable" << endl
       << "      This implies s = 1 - f is the amount of work that is" << endl
       << "      inherently serial." << endl;
  exit(0);

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
 * @returns iProgram expectes 2 command line arguments.nt Returns a status/exit code.  0 means normal termination.
 */
int main(int argc, char* argv[])
{
  // we expect exactly 2 command line arguments, N and f,
  // check command line arguments and parse, or give usage if missing
  if (argc != 4)
  {
    usage();
  }

  // try and convert the the arguments
  // argv[0] is name of Program
  // argv[1] we expect to be the amount of work to perform
  int amountOfWork = atoi(argv[1]);

  // argv[2] we expect to be N the number of parallel worker threads to create
  int N = atoi(argv[2]);

  // argv[3] we expect to be f the fraction of the task that is
  // parallelizable;
  double f = atof(argv[3]);

  cout << "Empirical example of the speedup predicted by Amdhal's Law" << endl
       << "    Number of worker threads running in parallel: " << N << endl
       << "    Fraction of task that can be parallelized   : " << f << endl
       << "    Fraction of task that is serial             : " << (1.0 - f) << endl
       << "    Amount of simulated work to perform         : " << amountOfWork << endl
       << endl << endl;


  // Empirical test of amount of time it takes 1 worker to complete the work
  double serialTime;
  cout << "Simulate performing work with a single serial worker" << endl;
  cout << "----------------------------------------------------" << endl;
  serialTime = simulateWorkWithNWorkers(1, 0.0, amountOfWork);
  cout << endl << endl;

  // Empirical test of amount of time it takes to do same amount of work with
  // the requested N thread workers
  double parallelTime;
  cout << "Simulate performing work with a parallel workers" << endl;
  cout << "----------------------------------------------------" << endl;
  parallelTime = simulateWorkWithNWorkers(N, f, amountOfWork);
  cout << endl << endl;

  // calculate the resulting speedup we saw with this experiment
  double speedup = serialTime / parallelTime;
  cout << "Serial Processing Time  : " << serialTime << " sec" << endl
       << "Parallel Processing Time: " << parallelTime << " sec" << endl
       << "Observed speedup        : " << speedup << endl;

  // calculate predicted speedup according to Amdhal's law
  double predictedSpeedup = 1.0 / ((1.0 - f) + (f / float(N)));
  cout << "Speedup predicted by Amdhals law: " << predictedSpeedup << endl;


}