/** @file ProcessSimulator.hpp
 * @brief ProcessSimulator API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our Process Simulator class.
 * Definition of simulator API goes in this file.  Implementation
 * of member methods is found in corresponding .cpp file.
 */
#ifndef PROCESS_SIMULATOR_HPP
#define PROCESS_SIMULATOR_HPP
#include "Process.hpp"
#include "ProcessState.hpp"
#include "SimulatorException.hpp"
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

using namespace std;

/** @class ProcessSimulator
 * @brief Process Simulation class
 *
 * Perform simulation of basic process creation and scheduling in an
 * operating system.
 */
class ProcessSimulator
{
private:
  /// @brief The system time slice quantum.  This parameter controls how long a
  ///   process is scheduled and given to run on the cpu before it is forcably
  ///   timed out and moved back to the end of the ready queue.
  Time timeSliceQuantum;

  /// @brief The current system time.  Each cpu cycle causes 1 system time
  /// clicke
  ///   to occur in this discrete simulation.
  Time systemTime;

  /// @brief The next process identifier that will be assigned to the next new
  ///   process to enter the system.
  Pid nextProcessId;

  /// @brief Keeps track of the number of processes that have exited the system.
  int numFinishedProcesses;

public:
  // constructors and destructors
  ProcessSimulator(Pid timeSliceQuantum);
  ~ProcessSimulator();
  void reset();

  // accessor and mutator (get/set) methods for ProcessSimulator
  Time getTimeSliceQuantum() const;
  Pid getNextProcessId() const;
  Time getSystemTime() const;
  int getNumActiveProcesses() const;
  int getNumFinishedProcesses() const;

  // accessor methods for Processes managed by the simulator
  const Process& getProcess(Pid pid) const;

  // cpu, ready queue and blocked list management functions
  Pid runningProcess() const;
  bool isCpuIdle() const;
  int readyQueueSize() const;
  Pid readyQueueFront() const;
  Pid readyQueueBack() const;
  int blockedListSize() const;
  bool isInState(Time timeSliceQuantum, Time systemTime, int numActiveProcesses, int numFinishedProcesses, Pid runningProcess,
    int readyQueueSize, Pid readyQueueFront, Pid readyQueueBack, int blockedListSize);

  // system event simulations and simulation management
  void newEvent();
  void dispatch();
  void cpuEvent();
  void timeout();
  void blockEvent(EventId eventId);
  void unblockEvent(EventId eventId);
  void doneEvent();

  // full simulation functions
  void runSimulation(string simulationFile);

  // friend functions for i/o
  string toString() const;
  friend ostream& operator<<(ostream& stream, const ProcessSimulator& sim);
};

#endif // PROCESS_SIMULATOR_HPP