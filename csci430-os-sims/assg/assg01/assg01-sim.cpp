/** @file assg01-sim.cpp
 * @brief System Test Simulator
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2020
 * @note   ide:  VS Code Editor/IDE ; GNU gcc tools
 *
 * Command line invocation of Hypothetical Machine Simulator,
 * used to perform system tests.  Given a file that specifies the
 * initial state of the memory and registers of the hypothetical
 * machine, we create a simulator object, load the program/state,
 * then execute fetch/execute cycles until either the machine
 * halts or we reach the maximum number of cycles specified.
 */
#include "HypotheticalMachineSimulator.hpp"
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
  cout << "Usage: sim maxCycles prog.sim" << endl
       << "Run hypothetical machine simulation on the given system state/simulation file" << endl
       << endl
       << "maxCycles          The maximum number of machine cycles (fetch/execute" << endl
       << "                     cycles) to perform" << endl
       << "file.sim           A simulation definition file containing starting" << endl
       << "                     state of machine and program / memory contents." << endl;
  exit(1);
}

/**
 * @brief main entry point
 *
 * Entry point of the hypothetical machine simulator system test
 * command line program.  This program is so small we do most all of
 * our work here.  We parse command line arguments, and if successful
 * we instantiate a HypotheticalMachineSimulator, load the
 * indicated program, and run the simulation.
 *
 * @param argc The command line argument count.  This program requires
 *   3 command line arguments to run.
 * @param argv[] The command line argument values.  argv[1] should be
 *   the number of fetch/execute cycles to perform (maximum), and
 *   argv[2] should be the simulation file to be loaded and executed.
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
  int maxCycles = atoi(argv[1]);
  string simFileName = string(argv[2]);
  bool verbose = true;

  // load the indicated simulation file and execute the program
  HypotheticalMachineSimulator sim;

  try
  {
    sim.loadProgram(simFileName);
    sim.runSimulation(maxCycles, verbose);
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