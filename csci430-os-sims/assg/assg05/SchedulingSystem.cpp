/** @file SchedulingSystem.cpp
 * @brief SchedulingSystem class implementations
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our SchedulingSystem class.  The
 * SchedulingSystem class defines the framework for a process
 * scheduling based system.  It supports reading in a table of process
 * arrival and service time information from a file or generating a
 * random set of process arrivals.  This system keeps track of whether
 * a job is currently running or not, if the current job has finished
 * (it has run its service time to completion), and helps with
 * preemption of running processes if the process scheduling policy is
 * a preemptive policy.  This class works with a SchedulingPolicy
 * object, which is the object that actually makes the scheduling
 * decisions when needed.

 */
#include "SchedulingSystem.hpp"
#include "FCFSSchedulingPolicy.hpp"
#include "SimulatorException.hpp"
#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief SchedulingSystem default constructor
 *
 * Default constructor for a SchedulingSystem simulation.  When beginning
 * a simulation, the most basic information will be what process scheduling
 * policy is to be used for the simulation.
 *
 * We default to a FCFS scheduling policy if none is specified when
 * the simulation starts.
 */
SchedulingSystem::SchedulingSystem()
{
  // create a FCFS scheduling policy by default
  this->policy = new FCFSSchedulingPolicy();

  // make sure we are mutually associated, that the policy knows
  // they are working with this system.
  this->policy->setSchedulingSystem(this);

  // 1 time initializations go here
  process = NULL;

  // make sure system is setup for a new simulation
  resetSystem();
}

/**
 * @brief SchedulingSystem policy
 *
 * Alternative constructor for a SchedulingSystem simulation.
 * You can specify a different strategy other than the default
 * strategy by creating your own SchedulingStrategy instance
 * (dynamically) and passing a pointer to the instance
 * into the constructor to be used by the simulation.
 *
 * @param policy A pointer to the policy that should be
 *   used by this simulation.
 */
SchedulingSystem::SchedulingSystem(SchedulingPolicy* policy)
{
  // remember which policy we are tol to use for the simulations
  this->policy = policy;

  // make sure we are mutually associated, that the policy knows
  // they are working with this system.
  this->policy->setSchedulingSystem(this);

  // 1 time initializations go here
  process = NULL;

  // make sure system is setup for a new simulation
  resetSystem();
}

/**
 * @brief SchedulingSystem destructor
 *
 * Destroy the SchedulingSystem instance.  Free up any dynamically
 * allocated memory.
 */
SchedulingSystem::~SchedulingSystem()
{
  // delete scheduling policy if we have one
  if (policy != NULL)
  {
    delete policy;
  }

  // delete process table
  if (process != NULL)
  {
    delete[] process;
  }
}

/**
 * @brief reset system simulation
 *
 * Make sure the simulation is correctly initialized to start
 * a new simulation.
 */
void SchedulingSystem::resetSystem()
{
  // set initial state of simulation variables
  systemTime = 0;
  cpu = IDLE;
  schedule = "";

  // make sure our policy resets as well
  policy->resetPolicy();
}

/** @brief system time accessor
 *
 * Accessor method to get the current system time of the
 * scheduling system simulation.
 *
 * @returns int The current system time of the simulation.
 */
int SchedulingSystem::getSystemTime() const
{
  // implement this for task 1
  return 0;
}

/** @brief num processes accessor
 *
 * Accessor method to get the number of simulated processes
 * in the process table for this simulation.
 *
 * @returns int The total number of processes in the process table,
 *   This will be the total of all processes we will simulate arriving
 *   and running in this system.
 */
int SchedulingSystem::getNumProcesses() const
{
  // implement this for task 1
  return 0;
}

/** @brief cpu idle test
 *
 * Determine if the cpu is currently idel or not.  This function returns
 * true if the cpu is currently idle and false otherwise.
 *
 * @returns bool true if the cpu is currently idle, false otherwise.
 */
bool SchedulingSystem::isCpuIdle() const
{
  // implement this for task 1
  // need to check the cpu member variable and determine it if
  // is IDLE or not.
  return true;
}

/** @brief get running process
 *
 * Returns the name of the current running process.  This method
 * will return the string "IDLE" if the cpu is currently idle.
 *
 * @returns string The name of the current running process, "IDLE"
 *   if the cpu is currently idle.
 */
string SchedulingSystem::getRunningProcessName() const
{
  // implement this for task 1, if the cpu is not idle you need to look up
  // the name from the process table
  return "IDLE";
}

/** @brief get process table
 *
 * Get a handle/pointer to the simulation process table. This
 * is needed information by some policies, so they can look up
 * service times and other information about the processes.
 *
 * @returns Process* returns an array of Process objects.
 */
Process* SchedulingSystem::getProcessTable() const
{
  return process;
}

/** @brief check all processes done
 *
 * Determine if all of the processes in our simulation have finished yet
 * or not.  The simulation ends once we have simulated all processes
 * running for their full service times.  Thus this method controls
 * when the simulation needs to end.
 *
 * @returns bool true if all processes in the process table have been
 *   marked as done, false otherwise.
 */
bool SchedulingSystem::allProcessesDone() const
{
  // task 2
  // You need to check and see if any process is still not done,
  // if you find a process that is not done, you need to return
  // false, otherwise you should return true.
  return true;
}

/** @brief final results table
 *
 * Calculate the final results and format as a table.
 * We stream the table into a string and return this as
 * the final result of the function.
 *
 * @returns string A string representation of the final
 *   results for the simulation formatted as a table.
 */
string SchedulingSystem::finalResultsTable() const
{
  stringstream out;

  // output a header first
  out << setw(4) << left << "Name"
      << " " << setw(4) << left << "Arrv"
      << " " << setw(4) << left << "T_s"
      << " " << setw(4) << left << "Strt"
      << " " << setw(4) << left << "End"
      << " " << setw(4) << left << "T_r"
      << " " << setw(8) << left << "T_r / T_s" << endl;

  // stream the results table to the string stream
  for (Pid pid = 0; pid < numProcesses; pid++)
  {
    Process p = process[pid];
    int turnaroundTime = p.endTime - p.arrivalTime;
    double trtsRatio = double(turnaroundTime) / double(p.serviceTime);

    out << setw(4) << left << p.name << " " << setw(4) << left << p.arrivalTime << " " << setw(4) << left << p.serviceTime << " " << setw(4)
        << left << p.startTime << " " << setw(4) << left << p.endTime << " " << setw(4) << left << turnaroundTime << " " << setw(8) << left
        << setprecision(4) << fixed << trtsRatio << endl;
  }

  // return the results as a string
  return out.str();
}

/** @brief final schedule
 *
 * Return the resulting final schedule history we
 * saw of scheduled processes running for this simulation.
 *
 * @returns string A string representation of the final
 *   schedule of process executions.
 */
string SchedulingSystem::finalSchedule() const
{
  return schedule;
}

/**
 * @brief load process table from file
 *
 * Load a table of process arrival and service time information
 * from th eindicated file.  The first line of the file indicates
 * the total number of processes in the file.  This is used
 * to dynamically allocate our table of process information objects.
 * Then the process information are read from the file and
 * put into the table for use by the simulation.  Each
 * process's information is on 1 line of the file, and is of the
 * format:
 *
 *      Name ArrivalTime ServiceTime
 *
 * It is expected that Name can be represented as a string, and ArrivalTime
 * and ServiceTime are values that can be interpreted as integers.
 *
 * @param simfilename The name of the file to open and read the process
 *   information from.
 */
void SchedulingSystem::loadProcessTable(string simfilename)
{
  ifstream processfile(simfilename);

  // if we can't open file, abort and let the user know problem
  if (not processfile.is_open())
  {
    stringstream msg;
    msg << "<SchedulingSystem::loadProcessTable> File not found, could not open"
        << " process table file: " << simfilename << endl;
    throw SimulatorException(msg.str());
  }

  // determine the total number of processes in the table
  processfile >> numProcesses;
  if ((numProcesses < 0) or (numProcesses > MAX_PROCESSES))
  {
    stringstream msg;
    msg << "<SchedulingSystem::loadPageStream> Invalid number of processes"
        << " in simulation: " << numProcesses << endl;
    throw SimulatorException(msg.str());
  }

  // dynamically allocate array to hold the process table,
  // freeing up old table if needed
  if (process != NULL)
  {
    delete[] process;
  }
  process = new Process[numProcesses];

  // load the simulated process table into our process array
  int pid = 0;
  while ((not processfile.eof()) and (pid < numProcesses))
  {
    // load the process information
    processfile >> process[pid].name >> process[pid].arrivalTime >> process[pid].serviceTime;

    // initialize other variables to initial states
    process[pid].startTime = NOT_STARTED;
    process[pid].endTime = NOT_STARTED;
    process[pid].timeUsed = 0;
    process[pid].done = false;

    // increment process identifier in preparation for reading
    // the next process
    pid++;

    // extract newlines from end of file
    processfile >> ws;
  }

  // final sanity check, if we didn't load in all processes or
  // if we didn't yet reach the end of the file as we were expecting
  // then throw an exception
  if ((pid != numProcesses) or (not processfile.eof()))
  {
    stringstream msg;
    msg << "<SchedulingSystem::loadPageStream> Error, did not see expected"
        << " number of processes in process table, expected: " << numProcesses << " received: " << pid << endl;
    throw SimulatorException(msg.str());
  }

  // (re)set simulator variables so we start simulation from beginning
  // using new page stream and no old page references are in memory
  resetSystem();
}

/**
 * @brief generate random process table
 *
 * Generate a random process table of processes and their arrival
 * times and service times.  It is useful for large scale statistical
 * analysis to generate random sets of process arrival information.
 * This method generates processes with a given probability of
 * arriving at each time step, and with a uniform service time and in
 * the range from 1 up to the maxServiceTime (defaults to 6). This
 * method also accepts a random seed. Use the const SEED_TIME to have
 * the random page table use the current system time to seed a
 * completely random page stream.
 *
 * @param numProcesses The number of processes to randomly create.  We keep
 *   creating random processes until we have generated this requested
 *   number of processes.
 * @param arrivalProbability This probability governs how probable a
 *   process is to arrive at each time step.
 * @param maxServiceTime The maximum serviceTime for the randomly generated
 *   processes.  We generate a serviceTime with uniform probability for each
 *   process in the range [1, maxServiceTime]
 * @param seed=SEED_TIME The seed to use for the random page table
 *   generation.  Default is the global constant SEED_TIME, which if
 *   given will cause the function to use the current system time
 *   to seed the random number generator.  Set this to some other value
 *   to generate a particular known random page table in order
 *   to have a repeatable simulation result.
 */
void SchedulingSystem::generateRandomProcessTable(int numProcesses, double arrivalProbability, int maxServiceTime, int seed)
{
  // first set random seed, use provided seed value, or use current
  // system time to generate a new stream if given SEED_TIME as the seed.
  if (seed == SEED_TIME)
  {
    seed = time(0);
  }
  srand(seed);

  // allocate a new pageReference block of memory, freeing up any
  // previous created pageReference stream
  if (process != NULL)
  {
    delete[] process;
  }
  this->numProcesses = numProcesses;
  process = new Process[numProcesses];

  // keep generating random processes until we have generated the asked for numProcesses
  int pid = 0;
  int time = 0;
  while (pid < numProcesses)
  {
    // check if a process arrives at the current time
    // r is a uniform random number from 0.0 to 1.0
    double r = ((double)rand() / (INT_MAX));
    if (r < arrivalProbability)
    {
      // the name of the process
      ostringstream nameStream;
      nameStream << "P" << pid;
      string name = nameStream.str();

      // the service time needs to be a random number from 1 to maxServiceTime
      int serviceTime = (rand() % maxServiceTime) + 1;

      // enter the new process into the table
      process[pid].name = name;
      process[pid].arrivalTime = time;
      process[pid].serviceTime = serviceTime;

      // initialize other variables to initial states
      process[pid].startTime = NOT_STARTED;
      process[pid].endTime = NOT_STARTED;
      process[pid].timeUsed = 0;
      process[pid].done = false;

      // increment the process identifier for next process we create
      pid++;
    }

    // increment arrival time for next check of process arriving
    time++;
  }

  // (re)set simulator variables so we start simulation from beginning
  // using new page stream and no old page references are in memory
  resetSystem();
}

/** process table as string
 *
 * Return a representation of the simulated processes as a string.
 * The table is represented as a list of tuples with
 * (ProcessName, arrivalTime, serviceTime) information given for each
 * process in the process table.  This function is mainly used
 * for debugging and testing.
 *
 * @returns string Returns a string representation of the processes
 *   in our process table that will be used in the simulation.
 */
string SchedulingSystem::processTableToString() const
{
  stringstream out;

  // iterate over process table and build output string stream
  out << "[ ";
  for (Pid pid = 0; pid < numProcesses; pid++)
  {
    out << "(" << process[pid].name << " " << process[pid].arrivalTime << " " << process[pid].serviceTime << ") ";
  }
  out << "]";

  // convert to string and return
  return out.str();
}

/**
 * @brief check new arrivals
 *
 * Check if a process (or multiple processes) arrive at the
 * current system time.  We basically have to notify our policy
 * of arrivals, so they can add them to their list of ready
 * and waiting processes, waiting to be scheduled on the cpu.
 */
void SchedulingSystem::checkProcessArrivals()
{
  // search process table to see if any process has an
  // arrival time of right now.  If so, notify the policy
  // of the newly arrived process.
  for (Pid pid = 0; pid < numProcesses; pid++)
  {
    if (process[pid].arrivalTime == systemTime)
    {
      policy->newProcess(pid);
    }
  }
}

/**
 * @brief dispatch cpu
 *
 * If the cpu is currently idle try and dispatch a process,
 * e.g. select a new process to be allocated the cpu and run
 * for a bit.  Which process to select is decided by the
 * SchedulingPolicy instance associated with this simulation.
 * We call the policy.dispatch() to request it
 * to tell us the pid of the process we should dispatch.
 * NOTE: it can be the case that no process is currently
 * ready to run.  Thus it is valid for the dispatch() method
 * call to our ScheculingPolicy to return IDLE if no process
 * can be dispatched, and thus the cpu remains idle.
 */
void SchedulingSystem::dispatchCpuIfIdle()
{
  // task 2
  // implement this.  You should first make sure the cpu is idle
  // if it is idle, you need to aske your policy to dispatch()
  // the next process (see previous process as an example of
  // working with your policy instnce).  The policy will return
  // the pid of the process to be dispatch.  You then need to
  // assign this process identifier to the cpu.  Also you need
  // to record the startTime for the process here if this is
  // the first time the process has ever run.  Proceses that
  // have never run have their startTime initialized to
  // NOT_STARTED, which is how you can tell if this is their first
  // time running or not.
}

/**
 * @brief simulate cpu cycle
 *
 * Simulate the execution of the cpu.  Increment the system
 * time, and statistics for the current running process, if
 * there is one.
 */
void SchedulingSystem::simulateCpuCycle()
{
  // increment system time
  systemTime++;

  // if a process is running, increment its statistics and record
  // the history of its execution
  if (not isCpuIdle())
  {
    process[cpu].timeUsed++;
    schedule += (process[cpu].name + "  ");
  }
  else // record cpu idle during this time period
  {
    schedule += "I  ";
  }
}

/**
 * @brief check process finished
 *
 * Check if currently running process is finished.
 * We update the process statistics when finished
 * and set the cpu to be idle.
 */
void SchedulingSystem::checkProcessFinished()
{
  // task 3
  // Again if the cpu is currently idle, then there is nothing
  // to do here, so you should first check if the cpu is idle
  // and just return without doing anything if it is.
  // If it is not idle, you need to see if the timeUsed of
  // the current cpu process is greater than or equal to its
  // serviceTime, which is how you know if it is finished or not.
  // If the process is finished you have to do the following:
  // a. record the endTime of the process
  // b. make sure you set the done flag of the process to no be true
  // c. The cpu should not be IDLE because the process just
  // finished.
}

/**
 * @brief process preemption
 *
 * Check if process needs to be preempted.  Preemption is a policy
 * decision.  So we send our policy a message each cycle to have
 * it determine if process should preempt or not. The policy will
 * return true if the process should be preempted, and false otherwise.
 * It is up to the policy to keep track of and determine if/when
 * preemption should happen.  For example for time slice based
 * systems, the policy should set a countdown timer and return true
 * when it reaches 0.  For preemption on new arrival, the policy
 * should make a note when a new process arrives, and do a preemption
 * at that point.
 */
void SchedulingSystem::checkProcessPreemption()
{
  // if cpu is idle, nothing to check
  if (isCpuIdle())
  {
    return;
  }

  // if the policy says we need to preempt, then remove the
  // process from the cpu and make the cpu idle.
  if (policy->preempt())
  {
    cpu = IDLE;
  }
}

/**
 * @brief run simulation
 *
 * Run a full simulation of a process scheduling system.  Before
 * calling this method, make sure a valid page table for the
 * simulation has been loaded or created, and make sure you have set
 * the process scheduling policy you wish to simulation.
 *
 * This method will simulate system time passing, starting at 1,
 * until all processes have arrived and have completely finished running.
 *
 * @param verbose If true we will display information about state of
 *   system to standard output after each system time step.  Default
 *   values is false, do not display this information.
 *
 * @throws Throws an exception if no process table has been (pre)loaded
 *   and is ready for the simulation to use.
 */
void SchedulingSystem::runSimulation(bool verbose)
{
  // check that a process table is loaded and ready to
  // simulate first before beginning
  if ((numProcesses <= 0) or (process == NULL))
  {
    stringstream msg;
    msg << "<SchedulingSystem::runSimulation> Error, you must load or"
        << " generate a process table first before running"
        << " a simulation" << endl;
    throw SimulatorException(msg.str());
  }

  // simulate time passing, process new arrivals and ask the scheduling policy
  // to make scheduling decisions.  We keep running the simulation until
  // all processes in the process table are done
  string schedule = "";
  while (not allProcessesDone())
  {
    // check for new arrivals at this time step so can notify
    // our scheduling policy to add new processs they are managing
    checkProcessArrivals();

    // determine if our policy wants to preempt the current running process
    checkProcessPreemption();

    // at beginning of time time step, check if cpu is idle and try and
    // schedule and dispatch a process if we can
    dispatchCpuIfIdle();

    // simulate process running for 1 clock cycle
    simulateCpuCycle();

    // determine if process has finished
    checkProcessFinished();
  }

  // Display scheduling simulation results if asked too
  if (verbose)
  {
    // display a header of systemTime and the final schedule
    for (int time = 0; time <= systemTime; time++)
    {
      cout << setw(2) << left << time << " ";
    }
    cout << endl;
    cout << "  " << finalSchedule() << endl << endl;

    // display final job statistics as a table
    cout << finalResultsTable() << endl;
  }
}