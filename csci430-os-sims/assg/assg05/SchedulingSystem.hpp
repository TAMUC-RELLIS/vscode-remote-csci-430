/** @file SchedulingSystem.hpp
 * @brief SchedulingSystem class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our SchedulingSystem class.  The
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
#ifndef SCHEDULING_SYSTEM_HPP
#define SCHEDULING_SYSTEM_HPP

#include "SchedulingPolicy.hpp"
#include <string>

// forward declaration needed for circular references
class SchedulingPolicy;

using namespace std;

/// @brief More descriptive name for things that hold process
///   identifiers.  We use int values for our processes identifiers
///   in this simulation.
typedef int Pid;

/// @brief IDLE is a flag used to indicate when the system cpu
//    is idle.
const int IDLE = -1;

/// @brief NOT_STARTED is a flag used to indicate processes
///   that have never yet run on the cpu
const int NOT_STARTED = -1;

/// @brief MAX_PROCESSES arbitrary upper limit on size of
///   simulations we will load, can be increased if needed for
///   huge simulations
const int MAX_PROCESSES = 10000;

/// @brief SEED_TIME flag used by the generateRandomPageStream to
///   indicate we should generate a unique stream by seeding using
///   the current system time as the seed.
const int SEED_TIME = 0;

/** @class Process
 * @brief Process Class
 *
 * This is a private/internal class for the SchedulingSystem
 * simulator.  This is basically structure of information
 * about the processes being managed by the system.
 */
struct Process
{
  /// @brief A human readable/string name assigned to the process
  string name;

  /// @brief The time when the process arrives in the simulation
  int arrivalTime;

  /// @brief The total amount of service time, or run time, the
  ///   process will need in order to complete its task
  int serviceTime;

  /// @brief The time when the process actually starts.  This can
  ///   (and often is) different from arrivalTime, as often the
  ///   process will be put on a ready queue and will have to wait
  ///   its turn before it can start.
  int startTime;

  /// @brief The time when the program successfully complets all of
  ///   its serviceTime and exits the system.
  int endTime;

  /// @brief While the simulation is running, this will keep track
  ///   of the total time used so far, so we can determine when
  ///   the process is finished by comparing to the serviceTime
  int timeUsed;

  /// @brief A boolean that will be false when the process is first
  ///    arrived/created.  It will be set to true when the process
  ///    is finished.  When all processes in the process table are
  ///    finished, then the simulation is done.
  bool done;
};

/** @class SchedulingSystem
 * @brief SchedulingSystem Class
 *
 * Framework to organize and simulate process scheduling
 * and process management in an operating system.  The
 * scheduling system class simulates time passing on the
 * system, and keeps track of the current running process,
 * when the process is done running, when new processes
 * arrive.  It works with a particular SchedulingPolicy
 * object that is responsible for making the actual
 * dispatching/scheduling decisions when needed.
 */
class SchedulingSystem
{
private:
  /// @brief The total number of processes that will be in the simulation.
  int numProcesses;

  /// @brief The process table.  Holds the table of information about
  ///   all of the proceesses that will be used in the simulation.
  ///   Each process has a name, an arrival time, and a service time
  Process* process;

  /// @brief SchedulingPolicy an instance of a SchedulingPolicy class that
  ///   conforms to the SchedulingPolicy API.  This instance is called
  ///   whenever we need to make process scheduling decisions for the
  ///   simulation.
  SchedulingPolicy* policy;

  /// @brief The current simulation system time.
  int systemTime;

  /// @brief The currently scheduled process on the simulated system cpu.
  ///   This is simply the pid (process id) of the index into our
  ///   process table.  IDLE is used to indicate an idle cpu.
  Pid cpu;

  /// @brief A string to keep track of the schedule history.  This
  ///   may need to be something a bit more robust if we need to
  ///   do more with the history in the future, but for now we
  ///   simply append the name of the process that runs in each
  ///   cpu cycle for display.
  string schedule;

public:
  // constructors and destructors
  SchedulingSystem();
  SchedulingSystem(SchedulingPolicy* policy);
  ~SchedulingSystem();
  void resetSystem();

  // accessor methods and system information
  int getSystemTime() const;
  int getNumProcesses() const;
  bool isCpuIdle() const;
  string getRunningProcessName() const;
  Process* getProcessTable() const;
  bool allProcessesDone() const;
  string finalResultsTable() const;
  string finalSchedule() const;

  // methods for loading or generating page reference streams
  // for the simulation
  void loadProcessTable(string simfilename);
  void generateRandomProcessTable(int numProcesses, double arrivalProbability, int maxServiceTime = 6, int seed = SEED_TIME);
  string processTableToString() const;

  // methods for running paging system simulation
  void checkProcessArrivals();
  void dispatchCpuIfIdle();
  void simulateCpuCycle();
  void checkProcessFinished();
  void checkProcessPreemption();
  void runSimulation(bool verbose = false);
};

#endif // SCHEDULING_SYSTEM_HPP