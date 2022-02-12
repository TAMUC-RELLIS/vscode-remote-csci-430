/** @file State.hpp
 * @brief State API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our State class.  The state
 * class defines the current state of system processes
 * and resources needed in order to implement a
 * Resource Allocation Denial (Banker's Algorithm)
 * deadlock avoidance strategy.
 *
 */
#ifndef STATE_HPP
#define STATE_HPP
#include <string>

using namespace std;

// to simplify memory management, we will just statically
// allocate matrices/vectors that are needed for our
// claim, allocation, etc.  We will simply check that if
// a new state is created, it doesn't ask to manage more
// than these number of processes and resources
/// @brief define maximum memory allocation for number of processes
///   we will allow in these simulations
const int MAX_PROCESSES = 20;
/// @brief define maximum memory allocation for number of resources
///   we will allow in these simulations
const int MAX_RESOURCES = 20;

// initialize values to this so we can better detect if we
// make a bounds reference error
/// @brief This value is used to initialize all memory one
///   creation of a new or newly loaded state, so we can better
///   detect if there are any memory access/load/bounds errors.
const int BAD_VALUE = -1;

// flag value for the findCandidate() function, indicates
// an unsuccessfull search when no candidate process is
// currently available to run given the system state
/// @brief Flag used by the findCandidateProcess() method, when
///   no candidate is found, this flag is returned instead of a
///   valid process id/index
const int NO_CANDIDATE = -1;

/** @class State
 * @brief State Class
 *
 * The State of a (computing) system.  This is basically
 * the state informatin we need in order to perform
 * a Resource Allocation Denial (Banker's Algorithm)
 * deadlock avoidance strategy.  For this strategy,
 * We need a claim matrix and allocation matrix, which
 * keep track of the maximum claimed resources and current
 * allocations for each process.  We also need to know
 * the current process needs (claim - allocations).  In
 * addition we keep track of the total resource of each
 * type in the system, and the current number of available
 * resource of each time.
 */
class State
{
private:
  /// @brief The total number of system resources
  ///   in this computing system.
  int numResources;

  /// @brief The total number of processes in this
  ///   computing system.
  int numProcesses;

  /// @brief The claim matrix, a matrix of the maximum
  ///   number of resources each process can claim while
  ///   running.  This is a 2-d array, where each row
  ///   contains information about a process, and each
  ///   column is for a different system resource.
  int claim[MAX_PROCESSES][MAX_RESOURCES];

  /// @brief The allocation matrix, contains current
  ///   allocations of resources information for each
  ///   process.  Also a 2-d array with rows for each
  ///   process and columns for each resource.
  int allocation[MAX_PROCESSES][MAX_RESOURCES];

  /// @brief The need matrix, contains the current
  ///   needs of each process.  Needs are related
  ///   to the claims and allocations, e.g.
  ///   need = claim - allocation.  So the need
  ///   matrix is also a 2-d array with rows for each
  ///   process and columns for each resource.
  int need[MAX_PROCESSES][MAX_RESOURCES];

  /// @brief The total resource vector.  This is a 1-d
  ///   vector of size numResources that holds the
  ///   total number of resources of each type.
  int resourceTotal[MAX_RESOURCES];

  /// @brief The available resources vector.  This is a 1-d
  ///   vector of size numResources that holds the currently
  ///   number of available resources of each resource type.
  ///   The available resource is related to the total resources
  ///   minus those that are currently allocated to processes.
  int resourceAvailable[MAX_RESOURCES];

public:
  // constructors and destructors
  State();
  void initializeState();

  // accessor and mutator methods
  int getNumResources() const;
  int getNumProcesses() const;

  // methods to load, test, change and manipulate the state
  void loadState(string filename);
  void inferStateInformation();

  // Resource Allocation Denial methods, used to determine
  // if current state is safe or not
  bool isSafe() const;
  bool needsAreMet(int process, const int currentAvailable[]) const;
  int findCandidateProcess(bool completed[], const int currentAvailable[]) const;
  void releaseAllocatedResources(int process, int currentAvailable[]) const;

  // methods to convert system state to a string, for debugging
  // and display purposes
  string tostring() const;
  friend ostream& operator<<(ostream& stream, const State& state);
};

// helper functions for our State and RAD simulation.  No need for
// these to be member functions of State as they are generally useful.
void skipComments(ifstream& simfile);
void copyVector(int numItems, const int srcVector[], int dstVector[]);
string vectorToString(int numResources, const int vector[]);
string matrixToString(int numProcesses, int numResources, const int matrix[][MAX_RESOURCES]);

#endif // STATE_HPP