/** @file assg02-sim.cpp
 * @brief System Test Simulator
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  VS Code Editor / IDE ; g++ 8.2.0 / GNU Make 4.2.1
 *
 * Command line invocation of Process Simulator, used to perform
 * system tests.  Given a file that specifies the simulated events
 * that occur in our simulated system, we create a ProcessSimulator
 * simulator object and load and run the file to simulate the sequence
 * of events occurring that cause processes to be created, exit,
 * block, unblock, dispatch and timeout.
 */
#include "ProcessSimulator.hpp"
#include "SimulatorException.hpp"
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
  cout << "Usage: sim timeSliceQuantum events-file.sim" << endl
       << "Run process simulation on the given set of simulated process events "
          "file"
       << endl
       << endl
       << "timeSliceQuantum   Parameter controlling the round robin time slicing" << endl
       << "                     simulated by the system.  This is the maximum" << endl
       << "                     number of cpu cycles a process runs when "
          "scheduled"
       << endl
       << "                     on the cpu before being interrupted and returned" << endl
       << "                     back to the end of the ready queue" << endl
       << "events-file.sim    A simulation definition file containing process" << endl
       << "                     events to be simulated." << endl;
  exit(1);
}

/**
 * @brief main entry point
 *
 * Entry point of the process simulator system test command line
 * program.  This program is so small we do most all of our work here.
 * We parse command line arguments, and if successful we instantiate a
 * ProcessSimulator, load the indicated simulation events file, and
 * run the simulation.
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
  if (argc != 3)
  {
    usage();
  }
  int timeSliceQuantum = atoi(argv[1]);
  string simFileName = string(argv[2]);

  // load the indicated simulation file and execute the program
  ProcessSimulator sim(timeSliceQuantum);

  try
  {
    sim.runSimulation(simFileName);
  }
  catch (const SimulatorException& e)
  {
    cerr << "Simulation run resulted in runtime error occurring:" << endl;
    cerr << e.what() << endl;
    exit(1);
  }

  // exit with 0 status code to indicate successful invocation of simulator
  return 0;
}