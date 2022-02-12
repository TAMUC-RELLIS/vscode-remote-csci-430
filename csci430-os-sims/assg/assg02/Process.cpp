/** @file Process.cpp
 * @brief Process Class implementations
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our Process class and
 * supporting functions.
 */
#include "Process.hpp"

using namespace std;

/**
 * @brief test state
 *
 * This private function is used by all of the support function of the
 * Process Simulator.  We check that the operation is being performed
 * on a valid process (not IDLE), and that the process is in the
 * expected state.
 *
 * @param function A string identifying the function that we are
 *   testing state for.
 * @param state The expected state the process must be in for this to
 *   be a valid call to the support function.
 *
 * @throws SimulatorException is thrown.  If a support funciton is
 *   called on an IDLE process or invalid process id we throw an
 *   exception.  If the ProcessState of the process is not in the
 *   expected state we also throw an exception.
 */
void Process::testProcessState(string function, ProcessState state) const
{
  // If this is not a valid process then we throw an exception.
  if (this->pid <= IDLE)
  {
    stringstream msg;
    msg << function << "  Error: expecting real process, IDLE or invalid pid seen: " << pid;
    throw SimulatorException(msg.str());
  }

  // If process is not in the expected state, we throw an exception
  // rather than proceeding
  if (this->state != state)
  {
    stringstream msg;
    msg << function << " Error: process must be in " << state << " state pid: " << pid << " state: " << this->state;
    throw SimulatorException(msg.str());
  }
}

/**
 * @brief Process default constructor
 *
 * We need a default constructor to manage processes with
 * stl maps and lists.  But we should never use a process
 * created in this way, thus we assign a flag value indicating
 * this is a invalid process.
 */
Process::Process()
{
  this->pid = IDLE;
  this->startTime = 0;
  this->state = NEW;
  this->timeUsed = 0;
  this->quantumUsed = 0;
  this->waitEventId = NA_EVENT;
}

/**
 * @brief Process constructor
 *
 * Basic constructor for a Process, basically only the
 * pid is needed and the time when the process was started.
 * All other information should be
 * initialized to an initial state/value for the process.
 *
 * @param pid The assigned process identifier for this process.
 * @param startTime The current system time when this process
 *   was started.
 */
Process::Process(Pid pid, Time startTime)
{
  this->pid = pid;
  this->startTime = startTime;
  this->state = NEW;
  this->timeUsed = 0;
  this->quantumUsed = 0;
  this->waitEventId = NA_EVENT;
}

/**
 * @brief Process destructor
 *
 * Clean up any necessary dynamic allocations or resources
 * if needed when a process goes out of scope.
 */
Process::~Process() {}

/**
 * @brief new to ready
 *
 * This function places new processes into a READY state
 * in preparation to be added to the ready queue
 * by the process simulator.  All of our support functions
 * first check that process is in expected state if called.
 * The process muste be in the NEW state when this method
 * is called.
 *
 * @throws SimulatorException Throws an exception if the process
 *   is not in the expected NEW state or is not a valid process.
 */
void Process::ready()
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::ready>", NEW);

  // otherwise process is in expected NEW state, so make it ready and
  // ensure that time quantum is 0
  state = READY;
  quantumUsed = 0;
}

/**
 * @brief dispatch process
 *
 * Perform necessary updates to dispatch this process so it can be
 * scheduled and begin running on the simulated cpu.
 *
 * @throws SimulatorException Throws an exception if the process is not
 *   in the expected READY state currently, or is not a valid process.
 */
void Process::dispatch()
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::dispatch>", READY);

  // process is ready so we can dispatch it to the cpu now
  state = RUNNING;
  quantumUsed = 0;
}

/**
 * @brief cpu cycle
 *
 * Update statistics to simulate this process running for 1 cpu
 * cycle.
 *
 * @throws SimulatorException Throws an exception if the process is
 *   not in the expected RUNNING state currently, or is not a valid
 *   process.
 */
void Process::cpuCycle()
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::cpuCycle>", RUNNING);

  // time used and time quantum is incremented for cpu cycle
  timeUsed++;
  quantumUsed++;
}

/**
 * @brief test quantum limit
 *
 * Test if this process has exceeded the system time slice quantum.
 * The maximum time slice quantum is passed in as a parameter.
 * This function returns true if we have reached or exceeded the
 * quantum slice limit and false if not.
 *
 * @param timeSliceQuantum The system time slice quantum setting.
 *
 * @throws SimulatorException Throws an exception if the process is
 *   not in the expected RUNNING state currently, or is not a valid
 *   process.
 *
 * @returns bool True if process has met or exceeded the system time
 *   slice quantum, false if not.
 */
bool Process::isQuantumExceeded(Time timeSliceQuantum) const
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::isQuantumExceeded>", RUNNING);

  return quantumUsed >= timeSliceQuantum;
}

/**
 * @brief timeout process
 *
 * Cause process to return to a READY state from a RUNNING
 * state.
 *
 * @throws SimulatorException Throws an exception if the process is
 *   not in the expected RUNNING state currently, or is not a valid
 *   process.
 */
void Process::timeout()
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::timeout>", RUNNING);

  // timeout process, put back into READY state and reset time quantum
  state = READY;
  quantumUsed = 0;
}

/**
 * @brief block process
 *
 * Cause process to become blocked waiting on an event.
 *
 * @param eventId The identifier of the event this process is blocked
 *   waiting on.
 *
 * @throws SimulatorException Throws an exception if the process is
 *   not in the expected RUNNING state currently, or is not a valid
 *   process.
 */
void Process::block(EventId eventId)
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::block>", RUNNING);

  // block the process and remember which event we are waiting on
  state = BLOCKED;
  quantumUsed = 0;
  waitEventId = eventId;
}

/**
 * @brief test event waiting on
 *
 * Test if this process is waiting on the event indicated or not.
 * This function returns true if it is the event we are waiting on and
 * false if not.
 *
 * @param eventId The id of the event to test this process for.
 *
 * @throws SimulatorException Throws an exception if the process is
 *   not in the expected BLOCKED state currently, or is not a valid
 *   process.
 *
 * @returns bool True if process is waiting on the indicated event
 *   false if not.
 */
bool Process::isWaitingOnEvent(EventId eventId) const
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::isWaitingOnEvent>", BLOCKED);

  return waitEventId == eventId;
}

/**
 * @brief unblock process
 *
 * Unblock a blocked process waiting on an event.
 *
 * @throws SimulatorException Throws an exception if the process is
 *   not in the expected RUNNING state currently, or is not a valid
 *   process.
 */
void Process::unblock()
{
  // private function, we test process is valid (not IDLE) and that it
  // is in the indicated state before we perform the operation
  testProcessState("<Process::unblock>", BLOCKED);

  // otherwise the process is blocked so we can unblock it and return
  // it to the ready state
  state = READY;
  quantumUsed = 0;
  waitEventId = NA_EVENT;
}

/**
 * @brief test process state
 *
 * Test to see if the process is in the indicated state currently.
 * This doesn't just test the ProcessState, but also checks that
 * timeUsed and quantumUsed are the same as the indicated values, and
 * that the pid is what is expected.  This function is mostly for
 * debugging purposes, to make writing unit test cases easier
 * for the process simulator.
 *
 * @param pid The pid to test if it is the same as this process.
 * @param state The process state to check if same as current state of
 *   this process.
 * @param startTime The starting system time when this process was
 *   created and entered into the system.
 * @param timeUsed Check if timeUsed for process is the expected value.
 * @param quantumUsed Check if the time slice quantumUsed is as
 *   expected currently.
 * @param waitEventId Check if the process is waiting on this expected
 *   event to occur.  Use NA_EVENT when the process is not blocked and
 *   is not waiting on an event.
 *
 * @returns bool True if all process state and values match the given
 *   expected state values.  False if any are a mismatch.
 */
bool Process::isInState(Pid pid, ProcessState state, Time startTime, Time timeUsed, Time quantumUsed, EventId waitEventId) const
{
  bool stateIsCorrect = (pid == this->pid) and (state == this->state) and (startTime == this->startTime) and
                        (timeUsed == this->timeUsed) and (quantumUsed == this->quantumUsed) and (waitEventId == this->waitEventId);

  // if the state was correct, we just return true
  if (stateIsCorrect)
  {
    return true;
  }
  // otherwise, we first display the actual state of this process to
  // stdout, to help with debugging of the test that failed.
  else
  {
    cout << *this << endl;
    return false;
  }
}

/**
 * @brief pid accessor
 *
 * Getter method to access and return the process identifier
 * or pid of this process.
 *
 * @returns Pid returns the process identifier of the process.
 */
Pid Process::getPid() const
{
  return pid;
}

/**
 * @brief string representation
 *
 * Create a string representation of the current state of this
 * Process object.  This method is used by the overloaded
 * output operator<< to send the status of the simulation
 * to an output stream.
 *
 * @returns string Returns a string object that contains
 *   information about the current state of this Process object.
 */
string Process::toString() const
{
  stringstream stream;

  // if this is the IDLE process, just return a simple string for
  // display
  if (pid == IDLE)
  {
    stream << "IDLE";
  }
  // otherwise give a more detailed state of this process
  else
  {
    stream << "Pid: " << setw(3) << left << pid << " state: " << setw(8) << left << state << " start: " << setw(3) << left << startTime
           << " used: " << setw(3) << left << timeUsed << " quant: " << setw(3) << left << quantumUsed << " event: " << setw(3) << left
           << waitEventId;
  }

  // convert our string stream back to a string for return to caller
  return stream.str();
}

/**
 * @brief Process output operator
 *
 * Overload the output operator for a Proces
 * This function allows us to directly stream a Process
 * object into an output stream.
 *
 * @param stream A reference to the output stream we are to
 *    output the representation of the ProcessState.
 * @param process A reference to the Process we are streaming to
 *    the output stream.
 *
 * @returns ostream& Returns a reference to the (modified) output
 *    stream that we wrote the Process into.
 */
ostream& operator<<(ostream& stream, const Process& process)
{
  stream << process.toString();

  return stream;
}