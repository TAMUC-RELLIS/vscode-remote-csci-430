/** @file SchedulingPolicy.hpp
 * @brief SchedulingPolicy class implementation file
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our SchedulingPolicy class.  The
 * SchedulingPolicy class is an abstract base class that defines the
 * interface for implementing different job scheduling policies.
 * Basically any scheduling policy needs to be notified when a
 * newProcess() arrives, a process runs a runCpuCycle(), and when a
 * process finished().  The main method of this stategy abstraction is
 * the dispatch() method, which is called by the scheduling simulator
 * whenever the cpu is idle, and the scheduling policy needs to make a
 * decision.
 */
#include "SchedulingPolicy.hpp"

/**
 * @brief constructor
 *
 * The basic constructor is called by the PagingSystem when setting up/creating
 * the paging scheme to use for a simulation.  We keep track of the paging system
 * instance we are associated with, so we can call the paging system to get
 * needed information to make replacment decisions.
 */
SchedulingPolicy::SchedulingPolicy() {}

/**
 * @brief destructor
 *
 * Define a concrete destructor.  This destructor has no work to do, but
 * base classes that need a destructor should define their own.
 */
SchedulingPolicy::~SchedulingPolicy() {}

/**
 * @brief set scheduling system
 *
 * Set the scheduling system instance that this policy is working
 * with.  When we create a ScheudlingSystem instance, we pass in
 * an already made policy for it to use.  Thus the SchedulingSystem
 * instance sets itself as the system for the policy when it is
 * created by calling this method.
 *
 * @param sys A pointer to the SchedulingSystem simulator that
 *   this policy will be working with.
 */
void SchedulingPolicy::setSchedulingSystem(SchedulingSystem* sys)
{
  this->sys = sys;
}