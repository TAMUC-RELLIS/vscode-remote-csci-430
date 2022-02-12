/** @file State.hpp
 * @brief State Class implementations
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our State class.  The state
 * class defines the current state of system processes
 * and resources needed in order to implement a
 * Resource Allocation Denial (Banker's Algorithm)
 * deadlock avoidance strategy.
 *
 */
#include "State.hpp"
#include "SimulatorException.hpp"
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @brief State constructor
 *
 * Basic default constructor for a State.  By default we
 * initialize to a completely empty state as the normal
 * use case is to load a system state from a file.  So
 * this method simply ensures all arrays are null and all
 * size parameters are set to 0.
 */
State::State()
{
  initializeState();
}

/**
 * @brief initialize State
 *
 * To make the State instance reusable, we separate
 * initialization back to an empty state so that
 * we can (re)initialize anytime we load a new state
 * as needed.
 */
void State::initializeState()
{
  numProcesses = numResources = 0;

  // initialize the 2-d matrices
  for (int process = 0; process < MAX_PROCESSES; process++)
  {
    for (int resource = 0; resource < MAX_RESOURCES; resource++)
    {
      claim[process][resource] = BAD_VALUE;
      allocation[process][resource] = BAD_VALUE;
      need[process][resource] = BAD_VALUE;
    }
  }

  // initialize the 1-d resource vectors
  for (int resource = 0; resource < MAX_RESOURCES; resource++)
  {
    resourceTotal[resource] = BAD_VALUE;
    resourceAvailable[resource] = BAD_VALUE;
  }
}

/**
 * @brief number of resource types accessor
 *
 * Constant accessor method to get the total number of resource
 * types that are present in the computing system state.  For example
 * if numResources is 3, that means the system has 3 resources,
 * labeled R0, R1 and R2.
 *
 * @returns int The number of resource types present in the system.
 */
int State::getNumResources() const
{
  return numResources;
}

/**
 * @brief number of processes accessor
 *
 * Constant accessor method to get the total number of
 * processes present in this simulated system.  For example
 * if numProcesses is 3, that means the system has 3 processes,
 * labeled P0, P1 and P2.
 *
 * @returns int The number of resource types present in the system.
 */
int State::getNumProcesses() const
{
  return numProcesses;
}

/**
 * @brief load state from file
 *
 * Given a file name, load the system state from the
 * indicated file.  This will load in the claim and
 * allocation matrices and the total resources vector.  The
 * need and available vectors are then inferred from the
 * allocations and claims.
 *
 * The file is expected to be in a very particular format.  If
 * the file cannot be parsed, this method throws an exception.
 * The file format is
 *
 * n m
 *
 * r0 r1 ... rm
 *
 * c_00 c_01 ... c_0m
 * c_10 c_11 ... c_1m
 * ...
 * c_n0 c_n1 ... c_nm
 *
 * a_00 a_01 ... a_0m
 * a_10 a_11 ... a_1m
 * ...
 * a_n0 a_n1 ... a_nm
 *
 * Where m is the total number of resource types in the system,
 * and n is the total number of processes in the system.  After
 * these 2 integers, there is a n rows by m columns matrix of
 * integer values, representing the maximum claims for the
 * processes.  Then likewise another n rows by m columns follows
 * which indicate the current allocations for the system.
 *
 * @param filename A string with the name of a file to open and
 *   read in the system state information.
 *
 * @throws SimulatorException is thrown if file is not found, or
 *   if file cannot be parsed because it is malformed or missing
 *   values at expected locations during read of file.
 */
void State::loadState(string filename)
{
  ifstream simfile(filename);

  // if we can't open file, throw an exception
  if (!simfile.is_open())
  {
    stringstream msg;
    msg << "<State::loadState> File not found, could not open system state file:" << filename << endl;
    throw SimulatorException(msg.str());
  }

  // make sure state is completely clean before load, just to be safe
  initializeState();

  // start by going to the line containing the number of
  // processes and resources and read them in
  skipComments(simfile);
  simfile >> numProcesses >> numResources;

  // check that processes or resources does not exceed the maximum
  // we can handle
  if ((numProcesses > MAX_PROCESSES) or (numResources > MAX_RESOURCES))
  {
    stringstream msg;
    msg << "<State::loadState> maximum exceeded, requested"
        << " numProcesses = " << numProcesses << " numResources = " << numResources << endl
        << " maximum = " << MAX_PROCESSES << ", " << MAX_RESOURCES << endl;
    throw SimulatorException(msg.str());
  }

  // Now go to the lines holding the total system resources and
  // read in the total resources
  skipComments(simfile);
  for (int resource = 0; resource < numResources; resource++)
  {
    simfile >> resourceTotal[resource];
  }

  // Now go to the lines holding the process/system claims and read
  // in the claims
  skipComments(simfile);
  for (int process = 0; process < numProcesses; process++)
  {
    for (int resource = 0; resource < numResources; resource++)
    {
      simfile >> claim[process][resource];
    }
  }

  // Now go to the lines holding the process/system current
  // allocations and read in the allocations
  skipComments(simfile);
  for (int process = 0; process < numProcesses; process++)
  {
    for (int resource = 0; resource < numResources; resource++)
    {
      simfile >> allocation[process][resource];
    }
  }

  // now infer the need and available resources from the
  // current state information
  inferStateInformation();

  // close the opened file before returning
  simfile.close();
}

/**
 * @brief infer state informaton
 *
 * When we load state information from a file, we are only
 * given the minimal necessary information.  We need to infer
 * the process needs from the given claim and allocation information,
 * and we need to infer the available resources given the
 * total resources and the current allocation of resources.
 */
void State::inferStateInformation()
{
  // first of all, infer need from claim and allocation.
  // need = claim - allocation
  for (int process = 0; process < numProcesses; process++)
  {
    for (int resource = 0; resource < numResources; resource++)
    {
      need[process][resource] = claim[process][resource] - allocation[process][resource];
    }
  }

  // now infer resource availability.  We need to sum up the allocated
  // resources for all processes from the allocation matrix, then use
  // this sum to determine the available from the resourceTotal
  // resourceAvailable = resourceTotal - (sum of current allocations)
  // notice the outer loop is over resources
  for (int resource = 0; resource < numResources; resource++)
  {
    // sum up the current allocations for this resource
    int currentAllocation = 0;
    for (int process = 0; process < numProcesses; process++)
    {
      currentAllocation += allocation[process][resource];
    }

    // now we know the sum of the current allocations for the resource,
    // so we can derive what is available
    resourceAvailable[resource] = resourceTotal[resource] - currentAllocation;
  }
}

/**
 * @brief determine if state is safe
 *
 * This method looks at the current values of this State and makes
 * a determination (using the banker's algorithm) of whether the
 * state is safe or not.  True is returned if the current State is
 * safe, and false otherwise.
 *
 * @returns bool True if the current State is safe, false if
 *   state is unsafe.
 */
bool State::isSafe() const
{
  // 1. make a copy of the resourceAvailable vector using the
  //    copyVector() function

  // 2. create a list of all processes, represent the list as
  //    an array of bool flags.  Initially all processes are
  //    marked as false indicating the process has not yet completed.

  // 3. search for candiddate processes from uncompleted processes,
  // and when we find a candidate, mark it as complete and return
  // its allocations to the currentAvailable pool

  // 3.1 if we found a candidate, need to release it allocations
  // and mark it as having been completed

  // 3.2 otherwise when no more candidates, we are done searching

  // 4. final test. After search completes, if some processes could
  // not complete, state is not safe
  // otherwise if all processes completed, then state is safe
  return true;
}

/**
 * @brief test if needs are met
 *
 * Given a process id and a vector of the currently available
 * resources, determine if the indicated process can have its
 * needs met from the currently available resources.
 *
 * @param process The index/id of the process to test.
 * @param currentAvailable A vector of the count of the number
 *   of current resources available for each resource type.
 *
 * @returns bool If all of the processes needs are <= to the
 *   currently available of each resource, we return true (the
 *   processes needs can be met), otherwise we return false.
 */
bool State::needsAreMet(int process, const int currentAvailable[]) const
{
  // need to check the needs for this process for each resource.
  // if any resource need cannot be met, the answer is false

  // otherwise if we find all needs <= currentAvailable then
  // the answer is true
  return true;
}

/**
 * @brief find candidate process to run
 *
 * For the banker's algorithm, given processes that have not
 * yet completed, search for one whose need <= currentAvailable
 * resources.  Return the first such candidate.  If there is
 * no candidate that can run, we return NO_CANDIDATE as the result.
 *
 * @param completed An array of boolean flags, one for each
 *   process.  Each process that is not yet complete has its
 *   flag set to false.  We only consider the uncompleted
 *   processes as candidates.
 * @param currentAvailable An array of the currently available
 *   resources.  We need to check each process that is not yet
 *   complete to see if their needs can be met from the current
 *   available resources.  If we find a process, we return it
 *   as the result from this funciton.
 *
 * @returns int Returns the index or process id of a candidate
 *   process if one is found.  A flag value of NO_CANDIDATE is
 *   returned if there are no processes that are candidates
 *   to run.
 */
int State::findCandidateProcess(bool completed[], const int currentAvailable[]) const
{
  // need to search each process.  If the process has not yet completed, and
  // the processes needs are met by the current available resources, then
  // the process is a candidate and you should return it.  You should be (re)using
  // the needsAreMet() function to perform this search

  // if no process is found that is not yet complete but its needs can be met,
  // then this function should return a failure NO_CANDIDATE flag
  return NO_CANDIDATE;
}

/**
 * @brief return allocated resources
 *
 * Given a process, return its allocated resources to the (temporary)
 * available resources vector provided for this function.
 * Simply cause all of the allocated resources for the
 * indicated process to be added into the current available
 * resources vector.
 *
 * @param process The id/index of the process whose allocated
 *   resources are to be returned to the available vector of
 *   resources.
 * @param currentAvailable A vector of the current counts of the
 *   currently available number of resources of each type.
 */
void State::releaseAllocatedResources(int process, int currentAvailable[]) const
{
  // all of the allocated resources for the indicated process should be
  // added back into the currentAvailable resources array here
}

/**
 * @brief State to string
 *
 * Represent current state as a string.  The current state
 * is basically the contents of the claim, allocation, and need
 * matrices, and the total and available resource vectors.
 *
 * @returns string Returns a formatted string object with the
 *   contents the current system State.
 */
string State::tostring() const
{
  stringstream out;

  // output the claim matrix to the string
  out << "Claim matrix C" << endl;
  out << matrixToString(numProcesses, numResources, claim);
  out << endl;

  // output the allocation matrix to the string
  out << "Allocation matrix A" << endl;
  out << matrixToString(numProcesses, numResources, allocation);
  out << endl;

  // output the need matrix to the string
  out << "Need matrix C-A" << endl;
  out << matrixToString(numProcesses, numResources, need);
  out << endl;

  // output the total resources to the string
  out << "Resource vector R" << endl;
  out << vectorToString(numResources, resourceTotal);
  out << endl;

  // output the available resources to the string
  out << "Available vector V" << endl;
  out << vectorToString(numResources, resourceAvailable);
  out << endl;

  return out.str();
}

/** State output operator
 * Overload the output operator for a State object.
 * This function allows us to directly stream the simulated
 * system State object into an output stream.
 *
 * @param stream A reference to the output stream we are to
 *    output the representation of the ProcessState.
 * @param state A reference to the State we are streaming to
 *    the output stream.
 *
 * @returns ostream& Returns a reference to the (modified) output
 *    stream that we wrote the State into.
 */
ostream& operator<<(ostream& stream, const State& state)
{
  stream << state.tostring();

  return stream;
}

//------------------------------------------------------------------

/**
 * @brief skip comments in file
 *
 * Given an input file stream, read in and skip over comment
 * lines starting with '#'  We keep skipping over these lines
 * until we find a line that doesn't start with a '#' then we
 * are done.
 *
 * @param simfile An input file stream object we are to read
 *   from and process.
 */
void skipComments(ifstream& simfile)
{
  bool done = false;
  char c;

  // keep going until we find out we are done by reading
  // a non '#' character
  while (!done)
  {
    // this will actually skip over whitespace as well, so
    // at this point c is next non whitespace character in the
    // input file stream
    simfile >> c;

    if (c == '#')
    {
      // if we see a comment, skip over all characters till we
      // see next newline character
      while (c != '\n' && simfile)
      {
        simfile.get(c);
        continue;
      }
    }
    // otherwise next character on next line is not a comment
    // so put it back and stop skipping comments
    else
    {
      simfile.unget();
      done = true;
    }
  }
}

/**
 * @brief copy vector
 *
 * Convenience function to copy a src vector's values into
 * a destination vector.  It is assumed that the destination
 * vector has enough allocated space to receive all of the
 * source vectors copied values.
 *
 * @param numItems The number of resources being copied from
 *   The source vector into the destination vector.
 * @param srcVector The source of the values we are copying from.
 * @param dstVector The destination to copy the values into.
 */
void copyVector(int numItems, const int srcVector[], int dstVector[])
{
  for (int item = 0; item < numItems; item++)
  {
    dstVector[item] = srcVector[item];
  }
}

/**
 * @brief vector to string
 *
 * Function to convert a vector to a string for display.  We assume
 * each column of the vector is data for a Resource starting at R0
 *
 * @param numResources The number of resources in the vector
 * @param vector An array of integer values which are the number
 *   of each resource type.
 *
 * @returns string Returns a formatted string object with the
 *   contents of the given vector represented in the string.
 */
string vectorToString(int numResources, const int vector[])
{
  stringstream out;

  // output a header for the vector, e.g. R0 R1 ... RN
  // skip 4 spaces for the row labels
  out << left << fixed << setw(4) << " ";
  for (int resource = 0; resource < numResources; resource++)
  {
    out << "R" << left << fixed << setw(3) << resource;
  }
  out << endl;

  // output the vector contents
  // skip 4 spaces to keep columns aligned for vectors
  out << left << fixed << setw(4) << " ";
  for (int resource = 0; resource < numResources; resource++)
  {
    out << left << fixed << setw(4) << vector[resource];
  }
  out << endl;

  return out.str();
}

/**
 * @brief matrix to string
 *
 * Function to convert a 2-d matrix to a string for display.  We assume
 * each row of the vector is process information and each column
 * is for a particular resource
 *
 * @param numProcesses The number of processes (rows) in the matrix
 * @param numResources The number of resources (columns) in the matrix
 * @param matrix A 2-d array of integer values which are the number
 *   of each resource type.
 *
 * @returns string Returns a formatted string object with the
 *   contents of the given matrix represented in the string.
 */
string matrixToString(int numProcesses, int numResources, const int matrix[][MAX_RESOURCES])
{
  stringstream out;

  // output a header for the matrix, e.g. R0 R1 ... RN
  // skip 4 spaces for the row labels
  out << left << fixed << setw(4) << " ";
  for (int resource = 0; resource < numResources; resource++)
  {
    out << "R" << left << fixed << setw(3) << resource;
  }
  out << endl;

  // output the matrix contents
  for (int process = 0; process < numProcesses; process++)
  {
    out << "P" << left << fixed << setw(3) << process;
    for (int resource = 0; resource < numResources; resource++)
    {
      out << left << fixed << setw(4) << matrix[process][resource];
    }
    out << endl;
  }

  return out.str();
}