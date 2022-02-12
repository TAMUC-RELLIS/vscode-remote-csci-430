/** @file assg04-sim.cpp
 * @brief System Test Simulator
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Command line invocation of Clock Algorithm page replace scheme
 * Simulator, used to perform system tests.
 */
#include "PagingSystem.hpp"
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
  cout << "Usage: sim scheme memorySize pageref.sim" << endl
       << "  Run page replacement simulation on the given page reference" << endl
       << "  stream file.  Output shows the state of memory (loaded pages" << endl
       << "  in each memory frame) after each page reference as well as" << endl
       << "  summary information about hit/miss performance.  You can" << endl
       << "  select from different page replacement schemes by specifying" << endl
       << "  the scheme parameter." << endl
       << "Options:" << endl
       << "  scheme       The page replacement scheme to use, current 'fifo'" << endl
       << "               and 'clock' are supported" << endl
       << "  memorySize   The number of physical frames of memory to simulate" << endl
       << "  pageref.sim  Filename with page references, one per line," << endl
       << "               that represent references to pages of a running" << endl
       << "               (simulated) process or set of processes" << endl;
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
  if (argc != 4)
  {
    usage();
  }

  string scheme = string(argv[1]);
  int memorySize = atoi(argv[2]);
  string pageRefFileName = string(argv[3]);
  bool verbose = true;
  PageReplacementSchemeType schemeType;

  // determine requested paging scheme type from command line argument
  if (scheme == "fifo")
  {
    schemeType = FIFO;
  }
  else if (scheme == "clock")
  {
    schemeType = CLOCK;
  }
  else
  {
    cerr << "Error: unknown paging scheme, use one of 'fifo, clock'" << endl;
    usage();
  }

  // create simulation of request memory size and using the requested page replacement scheme
  PagingSystem sim(memorySize, schemeType);

  // try and run the simulation, use verbose output so we can see whole system simulation
  // on standard output
  try
  {
    sim.loadPageStream(pageRefFileName);
    sim.runSimulation(verbose);
  }
  catch (const SimulatorException& e)
  {
    cerr << "Simulation run resulted in runtime error occurring: " << endl;
    cerr << e.what() << endl;
    exit(1);
  }

  // exit with 0 status code to indicate successful invocation of simulator
  return 0;
}