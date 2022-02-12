/** @file ProcessState.cpp
 * @brief Process State helper/overloaded functions
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our ProcessState supporting functions.
 */
#include "ProcessState.hpp"
#include <iostream>

using namespace std;

/** ProcessState output operator
 * Overload the output operator for a ProcessState enumerated type.
 * This function allows us to directly stream a ProcessState
 * variable into an output stream.
 *
 * @param stream A reference to the output stream we are to
 *    output the representation of the ProcessState.
 * @param state A reference to the ProcessState we are streaming to
 *    the output stream.
 *
 * @returns ostream& Returns a reference to the (modified) output
 *    stream that we wrote the ProcessState into.
 */
ostream& operator<<(ostream& stream, const ProcessState& state)
{
  switch (state)
  {
  case NEW:
    stream << "NEW";
    break;
  case READY:
    stream << "READY";
    break;
  case RUNNING:
    stream << "RUNNING";
    break;
  case BLOCKED:
    stream << "BLOCKED";
    break;
  case DONE:
    stream << "DONE";
    break;
  default:
    stream << "Error: Unknown ProcessState?";
  }

  return stream;
}