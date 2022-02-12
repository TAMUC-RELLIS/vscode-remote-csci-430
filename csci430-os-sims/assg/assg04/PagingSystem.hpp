/** @file PagingSystem.hpp
 * @brief PagingSystem class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our PagingSystem class.  The PagingSystem
 * class defines the framework for a paging based system.  It
 * supports reading in a stream of page references from a file
 * or generating a random stream of page references.  This system
 * keeps track of the physical frames of memory of the simulated
 * system, and it interacts with a PageReplacementScheme instance that
 * will make determinations of which pages to remove/replace
 * when paging decisions need so be made.
 *
 */
#ifndef PAGING_SYSTEM_HPP
#define PAGING_SYSTEM_HPP

#include "PageReplacementScheme.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

// forward declaration needed for circular references
class PageReplacementScheme;

using namespace std;

/// @brief More descriptive type name for page numbers.  In this
///   simulation page numbers are positive integers in range 1-N
typedef unsigned int PageNumber;

/// @brief More descriptive type name for frame numbers.  In this
///   simulation frame numbers need to be in the range 0-memorySize
typedef int FrameNumber;

/// @brief EMPTY_FRAME definition.  In this simulation all pages will
///   be numbered using positive integers 1-N.  Thus we can use 0 as a
///   flag for an empty memory frame
const PageNumber EMPTY_FRAME = 0;

/// @brief MAX_STREAM_SIZE arbitrary upper limit on size of
///   simulations we will load, can be increased if needed for
///   huge simulations
const int MAX_STREAM_SIZE = 1000000;

/// @brief SEED_TIME flag used by the generateRandomPageStream to
///   indicate we should generate a unique stream by seeding using
///   the current system time as the seed.
const int SEED_TIME = 0;

/** @enum PageReplacementSchemeType
 * @brief An enumerated type of implemented page replacement schemes,
 *   so can give safer more readable parameters to specify which scheme
 *   to use for simulations.
 */
enum PageReplacementSchemeType
{
  FIFO,
  CLOCK
};

/** @class PagingSystem
 * @brief PagingSystem Class
 *
 * Framework to organize and simulate paging systems of an
 * operating system.  The paging system class implements
 * the physical frames of memory and interacts with a
 * PageReplacementScheme to simulate page replacement decisions.
 * This class supports reading in a simulated page reference
 * stream from a file, or generating a random stream of
 * page references.
 */
class PagingSystem
{
private:
  /// @brief The number of physical memory frames being
  ///   simulated by this paging system, or in other words
  ///   the size of the physical memory in terms of number of
  ///   memory frames/pages physical memory holds.
  int memorySize;

  /// @brief The simulated physical memory frames of the system,
  ///   each frame holds 1 page of memory, or is currently
  ///   empty.  Each frame here simply holds the PageNumber of the
  ///   page currently loaded into the memory.
  PageNumber* memory;

  /// @brief The current system time of the simulation.  System
  ///   time starts at t=0 and increments in discrete time steps.
  ///   At each time step a new memory page reference is made.
  int systemTime;

  /// @brief The number of page references in the current
  ///   page reference stream being used by the simulation.
  int numPageReferences;

  /// @brief All of the page references that will be made in
  ///   the simulation.  The index in this array gives the reference
  ///   at that time, so at t=5, pageReferenct[5] is the page number
  ///   that is referenced by the running processe(s) in the system.
  PageNumber* pageReference;

  /// @brief PageReplacementScheme an instance of a PageReplacementScheme class that
  ///   conforms to the PageReplacementScheme API.  This instance is called
  ///   whenever we need to make page replacement decisions for the
  ///   simulation.
  PageReplacementScheme* scheme;

  /// @brief Count of page hits seen so far in simulation
  int hitCount;

  /// @brief Count of page faults seen so far in simulation
  int faultCount;

  /// @brief Count of page placements seen so far in simulation
  ///   (for these simulations there should be placements equal to
  ///   the number of frames in the simulation).
  int placementCount;

  /// @brief Count of page replacements seen so far in simulation
  int replacementCount;

public:
  // constructors and destructors
  PagingSystem();
  PagingSystem(int memorySize, PageReplacementSchemeType schemeType = FIFO);
  ~PagingSystem();
  void resetSystem();

  // accessor methods and system information
  int getMemorySize() const;
  int getSystemTime() const;
  int getNumPageReferences() const;
  bool isMemoryFull() const;
  string pageStreamToString() const;
  string memoryToString() const;
  string getPageStatus() const;
  void pokeMemory(FrameNumber frame, PageNumber pageNumber);
  PageNumber peekMemory(FrameNumber) const;
  FrameNumber findFrameOfCurrentPage() const;

  // methods for loading or generating page reference streams
  // for the simulation
  void loadPageStream(string simfilename);
  void generateRandomPageStream(int numPageReferences, int maxPage = 10, int seed = SEED_TIME);

  // methods for running paging system simulation
  bool isPageHit() const;
  void incrementSystemTime();
  void processNextPageReference();
  void doPagePlacement();
  void doPageReplacement();
  FrameNumber makeReplacementDecision();
  void runSimulation(bool verbose = false);
};

#endif // PAGING_SYSTEM_HPP