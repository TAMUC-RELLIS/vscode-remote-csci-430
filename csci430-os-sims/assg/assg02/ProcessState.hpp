/** @file ProcessState.hpp
 * @brief ProcessState API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our Process State.
 * This is an enumerated type that defines the valid
 * states a process can be in in our process simulator.
 * Definition of API goes in this file.
 */
#ifndef PROCESS_STATE_HPP
#define PROCESS_STATE_HPP
#include <iostream>

using namespace std;

/** define process state
 * Enumerated type, defines legal process states that a Process can
 * be in and that the OperatingSystem manages.  We overload the
 * operator<<, so that we can send string/text representation of a
 * processState out to a stream.
 */
enum ProcessState
{
  NEW,
  READY,
  RUNNING,
  BLOCKED,
  DONE
};

/** overload ostream output
 * Overload output stream operator for our ProcessState to provide
 * more human readable string representations of the process states
 * when needed.
 */
ostream& operator<<(ostream& stream, const ProcessState& state);

#endif // PROCESS_STATE_HPP