/** @file assg03-sim.cpp
 * @brief System Test Simulator
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Command line invocation of Resource Allocation Denial (Banker's
 * Algorithm) deadlock avoidance Simulator, used to perform system
 * tests.
 */
#include "SimulatorException.hpp"
#include "State.hpp"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief usage
 *
 * Usage information for invoking simulator with command line
 * arguments.  Print usage information and exit with non success
 * status to indicate error.
 */
void usage()
{
  cout << "Usage: sim state.sim" << endl
       << "Run Resource Allocation Denial (Banker's Algorithm) on simulation" << endl
       << "state file.  Return safe if the state is safe, or unsafe if not." << endl
       << endl
       << endl
       << "state.sim    Filename describing system state to load and" << endl
       << "             test if it is safe or unsafe." << endl;
  exit(1);
}

/**
 * @brief main entry point
 *
 * Entry point of the Resource Allocation Denial (Banker's algorithm)
 * simulator system test command line program.  This program is so
 * small we do most all of our work here.  We parse command line
 * arguments, and if successful we instantiate a ProcessSimulator,
 * load the indicated simulation events file, and run the simulation.
 *
 * @param argc The command line argument count.  This program requires
 *   3 command line arguments to run.
 * @param argv[] The command line argument values.  argv[1] should be
 *   the system timeSliceQuantum, and argv[2] should be the simulation
 *   file to be loaded and executed.
 *
 * @return 0 is returned if simulation finishes successfully with no errors
 *   or exceptions.  A non-zero value is returned when an exception occurs
 *   or whenever simulation terminates abnormally.
 */
int main(int argc, char** argv)
{
  // parse command line arguments
  // if we do not get required command line arguments, print usage
  // and exit immediately.
  if (argc != 2)
  {
    usage();
  }

  string stateFileName = string(argv[1]);

  // create a State, load the file, and test if the state is safe
  // or unsafe
  State state;
  state.loadState(stateFileName);

  try
  {
    cout << state << endl;
    if (state.isSafe())
    {
      cout << "State is safe" << endl;
    }
    else
    {
      cout << "State is unsafe" << endl;
    }
  }
  catch (const SimulatorException& e)
  {
    cerr << "Simulation run resulted in runtime rror occurring:" << endl;
    cerr << e.what() << endl;
    exit(1);
  }

  // exit with 0 status code to indicate successful invocation of simulator
  return 0;
}