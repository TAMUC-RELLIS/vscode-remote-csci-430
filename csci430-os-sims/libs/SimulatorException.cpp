/** @file SimulatorException.cpp
 * @brief SimulatorException implementations
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our Simulator Excepiton class and member
 * functions.
 */
#include "SimulatorException.hpp"

using namespace std;


/**
 * @brief SimulatorException constructor
 *
 * Constructor for exceptions used for our
 * SimulatorException class.
 *
 * @param msg The exception message thrown when an error occurs.
 */
SimulatorException::SimulatorException(const string& msg)
{
  message = msg;
}


/**
 * @brief SimulatorException destructor
 *
 * Destructor for exceptions used for our SimulatorException
 * class.
 */
SimulatorException::~SimulatorException()
{
}


/**
 * @brief SimulatorException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* SimulatorException::what() const throw()
{
  return message.c_str();
}

