/** @file assg05-sim.cpp
 * @brief System Test Simulator
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Command line invocation of Scheduling System
 * Simulator, used to perform system tests.
 */
#include "FCFSSchedulingPolicy.hpp"
#include "SchedulingSystem.hpp"
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
  cout << "Usage: sim policy process-table.sim [quantum]" << endl
       << "  Run scheduling system simulation.  The scheduling" << endl
       << "  simulator reads in a table of process information, specifying" << endl
       << "  arrival times and service times of processes to simulate." << endl
       << "  This program simulates the indicated process scheduling" << endl
       << "  policy.  Simulation is run until all processes are finished." << endl
       << "  Final data are displayed about the scheduling history" << endl
       << "  of which process ran at each time step, and the statistics " << endl
       << "  of the performance of the scheduling policy." << endl
       << endl
       << "Options:" << endl
       << "  policy       The page job scheduling policy to use, current" << endl
       << "               'FCFS', 'RR', 'SPN' are valid and supported" << endl
       << "  process-table.sim|RND  Filename of process table information to" << endl
       << "               to be used for the simulation.  RND indicates generate" << endl
       << "               a random process table." << endl
       << "  [quantum]    Time slice quantum, only used by some policies" << endl
       << "               that perform round-robin time slicing" << endl;
  exit(1);
}

/**
 * @brief main entry point
 *
 * Entry point of the job scheduling system simulator command line
 * program.  This program is so small we do most all of our work here.
 * We parse command line arguments, and if successful we instantiate a
 * SchedulingSimulator, object, load the indicated process table, and
 * run the simulation.
 *
 * @param argc The command line argument count.  This program requires
 *   2 command line arguments to run, and accepts additional optional ones.
 * @param argv[] The command line argument values.  argv[1] should be
 *   the policy to use for the simulation, and argv[2] should be the simulation
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
  if ((argc != 3) and (argc != 4))
  {
    usage();
  }

  string policyName = string(argv[1]);
  string processTableFileName = string(argv[2]);
  bool verbose = true;
  int quantum = 1;
  // if optional 4th argument, parse the time slice quantum
  if (argc == 4)
  {
    quantum = atoi(argv[3]);
    // need to use quantum to make compiler happy, can remove if/when really
    // using below
    cout << "Time slice quantum: " << quantum << endl;
  }

  // instantiate a policy instance to use
  SchedulingPolicy* policy;

  if (policyName == "FCFS")
  {
    policy = new FCFSSchedulingPolicy();
  }
  /*  example of adding additional policies to the simulation
     else if (policyName == "RR")
     {
     policy = new RRSchedulingPolicy(quantum);
     }
     else if (policyName == "SPN")
     {
     policy = new SPNSchedulingPolicy();
     }
   */
  else // unknwon/invalid scheduling policy specified
  {
    cerr << "Error: Unknown scheduling policy: " << policyName << endl;
    cerr << "  current valid policies: FCFS" << endl;
    exit(1);
  }

  // create Scheduling System simulation
  SchedulingSystem* sim = new SchedulingSystem(policy);

  // try and run the simulation, use verbose output so we can see whole system simulation
  // on standard output
  try
  {
    // if indicated, generate a set of random processes instead
    if (processTableFileName == "RND")
    {
      sim->generateRandomProcessTable(1000, 0.20, 10, SEED_TIME);
    }
    else
    {
      sim->loadProcessTable(processTableFileName);
    }
    sim->runSimulation(verbose);
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