/** @file SchedulingPolicy.hpp
 * @brief SchedulingPolicy class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our SchedulingPolicy class.  The
 * SchedulingPolicy class is an abstract base class that defines the
 * interface for implementing different job scheduling policies.
 * Basically any scheduling policy needs to be notified when a
 * newProcess() arrives, a process runs a runCpuCycle(), and when a
 * process finished().  The main method of this stategy abstraction is
 * the dispatch() method, which is called by the scheduling simulator
 * whenever the cpu is idle, and the scheduling policy needs to make a
 * decision.
 */
#ifndef SCHEDULING_POLICY_HPP
#define SCHEDULING_POLICY_HPP

#include "SchedulingSystem.hpp"
#include <string>

// forward declaration needed for circular references
class SchedulingSystem;

using namespace std;

/// @brief More descriptive name for things that hold process
///   identifiers.  We use int values for our processes identifiers
///   in this simulation.
typedef int Pid;

/** @class SchedulingPolicy
 * @brief SchedulingPolicy abstract base class
 *
 * This class defines the interface or API for the helper page
 * replacement scheme.  A PagingSystem simulation will instanciate
 * a derived class of this API, and will expect it to implement the
 * interface defined by this abstract base class.
 */
class SchedulingPolicy
{
protected: // derived classes need to be able to access the sys member instance
  /// @brief The paging system that this paging scheme is
  ///   supporting
  SchedulingSystem* sys;

public:
  SchedulingPolicy();

  // virtual function, concrete subclasses can override if needed
  virtual ~SchedulingPolicy();
  virtual void setSchedulingSystem(SchedulingSystem* sys);

  // pure virtual functions, concrete subclasses must implement
  virtual void newProcess(Pid pid) = 0;
  virtual Pid dispatch() = 0;
  virtual bool preempt() = 0;
  virtual void resetPolicy() = 0;
};

#endif // SCHEDULING_POLICY_HPP