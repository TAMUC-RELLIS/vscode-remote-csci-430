/** @file Process.hpp
 * @brief Process API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our Process class.  This class is basically
 * our Process Control Block Entry.  All information needed to manage
 * a process, including the process current state and statistics are
 * kept in this process structure.  Definition of API goes in this
 * file.  Implementation of member methods is in the corresponding
 * Process.cpp file.
 */
#ifndef PROCESS_HPP
#define PROCESS_HPP
#include "ProcessState.hpp"
#include "SimulatorException.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Use more descriptive labels for some common types of simulator /

/// @brief More descriptive name for Pid variable type used by Process
///   and in the process simulation
typedef unsigned int Pid;

/// @brief All system times and time measurements like quantum used
///   will be of type Time in the simulations.
typedef unsigned int Time;

/// @brief All fields that hold an event identifier that is being
///   blocked on are of this type.
typedef unsigned int EventId;

/// @brief Pid of 0 is used as a flag to indicate an idle
///   (unallocated) cpu and/or to indicate a stub or unused process in
///   some data structures.
const Pid IDLE = 0;

/// @brief And EventId of 0 is used as a flag to indicate that no
///   event is currently being waited on (e.g. this is none or Not
///   Applicable).
const EventId NA_EVENT = 0;

/** @class Process
 * @brief Process Class
 *
 * A basic class to hold information about a process being managed in
 * the simulated operating system.
 */
class Process
{
private:
  /// @brief The process identifier of this process.  The pid is a
  ///   unique identifier, only 1 process will ever have this
  ///   identifier in a running system.
  Pid pid;

  /// @brief The current state of this process, like READY, RUNNING,
  ///   BLOCKED, etc.
  ProcessState state;

  /// @brief The time when this process was started and entered the
  ///   system.
  Time startTime;

  /// @brief The amount of cpu time that has been used so far by this
  ///   process.
  Time timeUsed;

  /// @brief The amount of time slice quantum used so far by the
  ///   process for the most recent dispatch/allocation of the cpu.
  ///   This should always be less than or equal to the system time
  ///   slice quantum, because when we reach the time slice quantum the
  ///   process needs to be timed out and returned back to the ready
  ///   queue.
  Time quantumUsed;

  /// @brief If this process is blocked, this is the unique id of the
  ///   event the process is waiting to receive.  If the process is
  ///   not blocked, this will be set to NA_EVENT (not applicable).
  EventId waitEventId;

  void testProcessState(string function, ProcessState state) const;

public:
  // constructors and destructors
  Process();
  Process(Pid pid, Time startTime);
  ~Process();

  // support functions for the Process Simulator
  void ready();
  void dispatch();
  void cpuCycle();
  bool isQuantumExceeded(Time timeSliceQuantum) const;
  void timeout();
  void block(EventId eventId);
  bool isWaitingOnEvent(EventId eventId) const;
  void unblock();

  // miscellaneous functions, mostly for debugging and assignment
  // implementation
  bool isInState(Pid pid, ProcessState state, Time startTime, Time timeUsed, Time quantumUsed, EventId waitEventId) const;
  Pid getPid() const;

  // friend functions for i/o
  string toString() const;
  friend ostream& operator<<(ostream& stream, const Process& process);
};

#endif // PROCESS_HPP