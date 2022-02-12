/** @file FCFSSchedulingPolicy.hpp
 * @brief FCFSSchedulingPolicy class implementation file
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our FCFSSchedulingPolicy class.  The
 * FCFSSchedulingPolicy class is an abstract base class that defines the
 * interface for implementing different job scheduling policies.
 * Basically any scheduling policy needs to be notified when a
 * newProcess() arrives, a process runs a runCpuCycle(), and when a
 * process finished().  The main method of this stategy abstraction is
 * the dispatch() method, which is called by the scheduling simulator
 * whenever the cpu is idle, and the scheduling policy needs to make a
 * decision.
 */
#include "FCFSSchedulingPolicy.hpp"
#include <queue>

using namespace std;

/**
 * @brief constructor
 *
 * The basic constructor is called by the PagingSystem when setting up/creating
 * the paging scheme to use for a simulation.  We keep track of the paging system
 * instance we are associated with, so we can call the paging system to get
 * needed information to make replacment decisions.
 */
FCFSSchedulingPolicy::FCFSSchedulingPolicy()
  : SchedulingPolicy()
{
  sys = NULL;
  resetPolicy();
}

/**
 * @brief destructor
 *
 * Define a concrete destructor.  This destructor has no work to do, but
 * base classes that need a destructor should define their own.
 */
FCFSSchedulingPolicy::~FCFSSchedulingPolicy() {}

/** new process
 * Handle new process arrivals.  When a new process arrives it is
 * put in a ready to run state.  We add it to the end of our
 * ready queue.
 *
 * @param pid The process identifier (pid) of the newly arriving
 *   process that should now be managed by this policy.
 */
void FCFSSchedulingPolicy::newProcess(Pid pid)
{
  // put the new process on the end of the ready queue
  readyQueue.push(pid);
}

/** dispatch a process
 * When the cpu is idle, the scheduling simulator calls this
 * method of the policy object to select which process to
 * dispatch and schedule and run next on the cpu.  The
 * First Come First Serve (FCFS) policy simply selects the
 * process that has been waiting the longest, and thus was the
 * first to "come" into the system.
 *
 * @returns pid Returns the process identifier of the process
 *   we select to run next.
 */
Pid FCFSSchedulingPolicy::dispatch()
{
  // make sure the ready queue is not empty, if it is we
  // can't dispatch at this time
  if (readyQueue.empty())
  {
    return IDLE;
  }
  // otherwise pop the front item and return it
  else
  {
    int pid = readyQueue.front();
    readyQueue.pop();
    return pid;
  }
}

/**
 * @brief preemption
 *
 * Determine if current running processes needs to be preempted.
 * FCFS is a non-preempting policy, so we have nothing to
 * do here but always return false to mean we shouldn't preempt
 * now.
 *
 * @returns bool Always returns false to indicate FCFS never
 *   preempts.
 */
bool FCFSSchedulingPolicy::preempt()
{
  return false;
}

/** reset policy
 * Reset or initialize the scheduling policty to an initial state,
 * in preparation for beginning a simulation.  For FCFS this means
 * we want to clear out the ready queue and make sure it is
 * empty to begin with.
 */
void FCFSSchedulingPolicy::resetPolicy()
{
  // make sure the queue is empty, swap a queue with a known
  // empty queue will free up the old queue and ensure we start
  // with an empty one.
  queue<Pid> empty;
  swap(readyQueue, empty);
}