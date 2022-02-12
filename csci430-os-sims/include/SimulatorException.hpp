/** @file SimulatorException.hpp
 * @brief Simulation Exceptions
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for a basic Exception class we will use in all
 * of the class assignment simulations.  We use a generic Exception
 * but we allow the thrower to add a message to the exception that
 * will allow us to determine the reason the exception was generated.
 */
#ifndef SIMULATOR_EXCEPTION_HPP
#define SIMULATOR_EXCEPTION_HPP
#include <string>

using namespace std;


/** @class SimulatorException
 * @brief Exceptions for assignment simulations 
 *
 * Exception class to be thrown by our Process Simulator when it
 * encounters a problem.
 *
 */
class SimulatorException : public exception
{
public:
  explicit SimulatorException(const string& msg);
  ~SimulatorException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

#endif // SIMULATOR_EXCEPTION_HPP
