/** @file PagingSystem.cpp
 * @brief PagingSystem class implementations
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our PagingSystem class.  The PagingSystem
 * class defines the framework for a paging based system.  It
 * supports reading in a stream of page references from a file
 * or generating a random stream of page references.  This system
 * keeps track of the physical frames of memory of the simulated
 * system, and it interacts with a PageReplacementScheme instance that
 * will make determinations of which pages to remove/replace
 * when paging decisions need so be made.
 *
 */
#include "PagingSystem.hpp"
#include "ClockPageReplacementScheme.hpp"
#include "FifoPageReplacementScheme.hpp"
#include "SimulatorException.hpp"
#include <cassert>
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief PagingSystem default constructor
 *
 * We should not normally call the default constructor as it is
 * a requirement we know the amount of memory that is to be
 * simulated.  But this is needed to be declared so can
 * pass references to PageReplacementScheme objects.
 */
PagingSystem::PagingSystem()
{
  // TODO: maybe should throw an exception here to ensure a raw
  // PagingSystem is never created?
}

/**
 * @brief PagingSystem constructor
 *
 * Normal constructor for a PagingSystem simulation.  When beginning
 * a simulation, the most basic information will be the size of the
 * physical memory we are simulating.  This constructor creates
 * a memory of PageNumber references, and initializes all of memory
 * to initially be empty.
 *
 * @param memorySize The size of memory, or in other words, the numbers
 *   of physical memory frames we will simulate.
 * @param schemeType The page replacement scheme algorith to use
 *   for this simulation.  Defaults to FIFO page replacement if not
 *   specified.
 */
PagingSystem::PagingSystem(int memorySize, PageReplacementSchemeType schemeType)
{
  // dynamically allocate needed memory for our physical memory frames
  this->memorySize = memorySize;
  this->memory = new PageNumber[this->memorySize];

  // initialze page reference stream to empty initially
  this->numPageReferences = 0;
  this->pageReference = NULL; // initially no page reference stream loaded

  // create page replacement scheme type.  This parameter defaults to FIFO
  // if not specified in the constructor, otherwise user can specify a different
  // page replacement scheme to use
  switch (schemeType)
  {
  case FIFO:
    this->scheme = new FifoPageReplacementScheme(this);
    break;
  case CLOCK:
    this->scheme = new ClockPageReplacementScheme(this);
    break;
  default:
    stringstream msg;
    msg << "<PagingSystem::PagingSystem> Error: unknown page replacement"
        << " scheme type received, scheme type:" << schemeType << endl;
    throw SimulatorException(msg.str());
  }

  // make sure system is setup for a new simulation
  resetSystem();
}

/**
 * @brief PagingSystem destructor
 *
 * Destroy the PagingSystem instance.  Free up any dynamically
 * allocated memory.
 */
PagingSystem::~PagingSystem()
{
  // delete any dynamically allocated system memory frames
  if (memory != NULL)
  {
    delete[] memory;
  }

  // delete any dynamically allocated page reference stream
  if (pageReference != NULL)
  {
    delete[] pageReference;
  }

  // delete paging scheme if we have one
  if (scheme != NULL)
  {
    delete scheme;
  }
}

/**
 * @brief reset system simulation
 *
 * Clear out all of memory, make sure all frames are empty, no
 * pages currently loaded into any frames.  Set instance variables
 * to initial states for start of a simulation.
 */
void PagingSystem::resetSystem()
{
  // clear out memory make sure it is completely empty
  for (FrameNumber frame = 0; frame < this->memorySize; frame++)
  {
    this->memory[frame] = EMPTY_FRAME;
  }

  // cause our current page replacement scheme to reset itself
  scheme->resetScheme();

  // initialize other system variables
  this->systemTime = 0;
  this->hitCount = 0;
  this->faultCount = 0;
  this->placementCount = 0;
  this->replacementCount = 0;
}

/**
 * @brief memorySize accessor
 *
 * Return the memory size of this PagingSystem.  memorySize
 * in this case refers to the number of physical frames being
 * simulated in this system.
 *
 * @returns int The memory size of the current PagingSystem simulation.
 */
int PagingSystem::getMemorySize() const
{
  // unit test task 1, implement accessor/information methods of
  // simulation class
  return 1;
}

/**
 * @brief systemTime setter
 *
 * Set the system time to a new time
 * starts at t=0 and increments in discrete time steps.
 *
 * @returns int The current systemTime of this PagingSystem simulation.
 */
int PagingSystem::getSystemTime() const
{
  // unit test task 1, implement accessor/information methods of
  // simulation class
  return 0;
}

/**
 * @brief numPageReferences accessor
 *
 * Return the total number of page references that will be made in
 * the simulation.  Page reference streams can be loaded and unloaded.
 * So this value is the number of page references of current loaded
 * stream to simulate.  If numPageReferences is 0 then no page reference
 * stream is currently available.
 *
 * @returns int The number of page references in the current simulation
 *   stream, 0 if no page reference stream is currently available.
 */
int PagingSystem::getNumPageReferences() const
{
  // unit test task 1, implement accessor/information methods of
  // simulation class
  return 0;
}

/**
 * @brief is memory full
 *
 * Determine if memory is currently completely full (no EMPTY_FRAMEs
 * exist) or not.  Return true if full, false if 1 or more empty
 * frames still present in memory.
 *
 * @returns bool True if memory is completely full, false if 1 ore
 *   more empty memory frames are present.
 */
bool PagingSystem::isMemoryFull() const
{
  // unit test task 2, search memory[], if any frame is empty
  // then the answer is false, otherwise if all frames
  // are nonempty, answer should be true
  return true;
}

/**
 * @brief page stream as string
 *
 * Return a representation of the simulated page reference stream
 * as a string.  The stream is represented as a time ordered
 * list of the page references in the current page reference stream.
 * This function is mainly used for debugging and testing.
 *
 * @returns string Returns a string representation of the page
 *   stream as a list of page references from t=0 to t=numPageReferences-1
 */
string PagingSystem::pageStreamToString() const
{
  stringstream out;

  // iterate over pageReferences and build output string stream
  out << "[ ";
  for (int time = 0; time < numPageReferences; time++)
  {
    out << pageReference[time];
    if (time != numPageReferences - 1)
    {
      out << ", ";
    }
  }
  out << " ]";

  // convert to string and return
  return out.str();
}

/**
 * @brief memory as string
 *
 * Return a representation of the current contents of the physical
 * memory frames as a string.  This function is mainly useful
 * for debugging and testing.
 *
 * @returns string Returns a string representation of memory contents
 *   as a list of the page references in each frame.
 */
string PagingSystem::memoryToString() const
{
  stringstream out;

  // iterate over memory frames and build output string stream
  out << "[ ";
  for (FrameNumber frame = 0; frame < memorySize; frame++)
  {
    out << memory[frame];
    if (frame != memorySize - 1)
    {
      out << ", ";
    }
  }
  out << " ]";

  // convert to string and return
  return out.str();
}

/**
 * @brief current page status
 *
 * Return the status of the currently reference page as a string.
 * If it will be a page hit, we return "hit".  If it is a miss and
 * memory is not yet full, we return "fault (placement)", else we return
 * "fault (replacement)".
 *
 * @returns string String representation of the current referenced
 *   page status, one of "hit", "fault (placement)" or "fault (replacement)"
 */
string PagingSystem::getPageStatus() const
{
  string res;

  if (isPageHit())
  {
    res = "hit";
  }
  else if (isMemoryFull())
  {
    res = "fault (replacement)";
  }
  else
  {
    res = "fault (placement)";
  }

  return res;
}

/**
 * @brief poke memory
 *
 * Method for testing/debugging in order to be able to explictly
 * set the page number reference in a frame of memory.
 *
 * @param frame The frame number of memory to modify
 * @param pageNumber The page reference number to be poked into the
 *   physical memory frame.
 */
void PagingSystem::pokeMemory(FrameNumber frame, PageNumber pageNumber)
{
  memory[frame] = pageNumber;
}

/**
 * @brief peek memory
 *
 * Given a frame number, return the contents of memory, the page number in
 * that physical frame.  Used by scheme classes to display algorithm status.
 *
 * @param frame The frame number we are to access and peek at in memory.
 *
 * @returns PageNumber returns the page number in the indicated physical
 *   frame of memory
 */
PageNumber PagingSystem::peekMemory(FrameNumber frame) const
{
  return memory[frame];
}

/**
 * @brief find frame of current page
 *
 * Find the frame number of the currently referenced page in our
 * page stream and return it.
 *
 * @returns FrameNumber the frame number of the currently references
 *   and hit page.
 *
 * @throws SimulatorException is thrown if this method is called
 *   and the current page is not in memory.  This method should only
 *   be called on a page hit, when it is known the page is in a memory
 *   frame.
 */
FrameNumber PagingSystem::findFrameOfCurrentPage() const
{
  // search memory for the current page in the page stream
  for (FrameNumber frame = 0; frame < memorySize; frame++)
  {
    if (memory[frame] == pageReference[systemTime])
    {
      return frame;
    }
  }

  // if we searched all of memory and did not find the current
  // page in it, something is wrong.  We should never be called
  // unless it known the page was a hit
  stringstream msg;
  msg << "<PagingSystem::findFrameOfCurrentPage> Error: current page is"
      << " not present in memory, cannot find frame of current page." << endl;
  throw SimulatorException(msg.str());
}

/**
 * @brief load page references from file
 *
 * Load a stream of simulated page references from the indicated
 * file.  The first line of the file indicates the total number of
 * page references in the stream to be loaded.  This is used to
 * dynamically allocate the pageReferences[] block of memory.
 * Then the page references are read from the file.  Each reference
 * is on 1 line of the file, and is expected to be an unsigned
 * integer in the range 1-N.
 *
 * @param simfilename The name of the file to open and read the page
 *   references from.
 */
void PagingSystem::loadPageStream(string simfilename)
{
  ifstream pagestreamfile(simfilename);

  // if we can't open file, abort and let the user know problem
  if (not pagestreamfile.is_open())
  {
    stringstream msg;
    msg << "<PagingSystem::loadPageStream> File not found, could not open"
        << " system state file: " << simfilename << endl;
    throw SimulatorException(msg.str());
  }

  // determine the total number of page references in the stream
  pagestreamfile >> numPageReferences;
  if ((numPageReferences < 0) or (numPageReferences > MAX_STREAM_SIZE))
  {
    stringstream msg;
    msg << "<PagingSystem::loadPageStream> Invalid number of page references"
        << " in simulation: " << numPageReferences << endl;
    throw SimulatorException(msg.str());
  }

  // dynamically allocate array to hold the page reference stream,
  // freeing up old stream if needed
  if (pageReference != NULL)
  {
    delete[] pageReference;
  }
  pageReference = new PageNumber[numPageReferences];

  // load the simulated page references into our pageReference array
  int time = 0;
  PageNumber pageref;
  while ((not pagestreamfile.eof()) and (time < numPageReferences))
  {
    pagestreamfile >> pageref;
    pageReference[time] = pageref;
    time++;
    pagestreamfile >> ws; // extract newlines from end of file
  }

  // final sanity check, if we didn't load in all page references or
  // if we didn't yet reach the end of the file as we were expecting
  // then throw an exception
  if ((time != numPageReferences) or (not pagestreamfile.eof()))
  {
    stringstream msg;
    msg << "<PagingSystem::loadPageStream> Error, did not see expected"
        << " number of pages in simulation stream, expected: " << numPageReferences << " received: " << time << endl;
    throw SimulatorException(msg.str());
  }

  // (re)set simulator variables so we start simulation from beginning
  // using new page stream and no old page references are in memory
  resetSystem();
}

/**
 * @brief generate random page stream
 *
 * Generate a stream of random page references to use for a simulation.
 * It is useful for large scale statistical analysis to generate
 * random streams of page references.  This method generates
 * page references with a uniform probability.  The pages that
 * might be references range from 1 to maxPage inclusive, where maxPage is a
 * parameter passed in to this function (defaults to 10).  This method
 * also accepts a random seed. Use the const SEED_TIME to have the
 * random page stream use the current system time to seed a completely
 * random page stream.
 *
 * @param numPageReferences The number of random page references to
 *   generate and put into the page reference stream for the simulation.
 * @param maxPage=10 The maximum page reference to generate.  We generate
 *   page references using a uniform probability.  Pages range from [1, maxPage]
 *   inclusive.  Default is 10, so that page number references are
 *   generated for range [1,10]
 * @param seed=SEED_TIME The seed to use for the random page reference
 *   generation.  Default is the global constant SEED_TIME, which if
 *   given will cause the function to use the current system time
 *   to seed the random number generator.  Set this to some other value
 *   to generate a particular known page reference sequence in order
 *   to have a repeatable simulation result.
 */
void PagingSystem::generateRandomPageStream(int numPageReferences, int maxPage, int seed)
{
  // first set random seed, use provided seed value, or use current
  // system time to generate a new stream if given SEED_TIME as the seed.
  if (seed == SEED_TIME)
  {
    seed = time(0);
  }
  srand(seed);

  // allocate a new pageReference block of memory, freeing up any
  // previous created pageReference stream
  if (pageReference != NULL)
  {
    delete[] pageReference;
  }
  this->numPageReferences = numPageReferences;
  pageReference = new PageNumber[numPageReferences];

  // generate random page references in the indicated range.
  int nextPageRef;
  for (int time = 0; time < numPageReferences; time++)
  {
    nextPageRef = (rand() % maxPage) + 1;
    pageReference[time] = nextPageRef;
  }

  // (re)set simulator variables so we start simulation from beginning
  // using new page stream and no old page references are in memory
  resetSystem();
}

/**
 * @brief is page a hit
 *
 * Is the current page reference a hit or a miss.  Return
 * true if the current page reference for the current systemTime
 * is somewhere in memory (a hit).  Return false if the current
 * page reference is not in memory (a miss)
 *
 * @returns bool True if the current page reference for the current
 *   systemTime is a hit, false if the reference is a miss.
 */
bool PagingSystem::isPageHit() const
{
  // unit test task 3.  Search current contents of memory[]
  // to see if the current pageReference for the current
  // systemTime is in memory or not.  Return true if
  // the current page referenc eis in memory, false otherwise.
  return false;
}

/**
 * @brief systemTime increment
 *
 * Increment the current system time one time step.
 */
void PagingSystem::incrementSystemTime()
{
  systemTime++;
}

/**
 * @brief process next page reference
 *
 * Perform a single step of the simulation.  This method first
 * checks if the current page references (for the current systemTime)
 * is a hit or a miss.  If it is a hit, nothing further needs to be
 * done besides updating any system performance statistics.  If
 * page reference is a miss, we need to perform either an initial
 * page placements, or do a page replacement.  Page placement occurs
 * anytime memory is not yet full, and we use a simple algorithm and
 * select the  lowest free frame of memory for the placement.
 * The most complex case occurs when memory is full.  When memory
 * is full, we first must make a page replacement decision, and
 * select a memory frame to be removed from memory.  Then we can
 * proceed to place the new page reference in the freed up memory
 * frame (a replacement).
 *
 * @throws This method tests if trying to run simulation past
 *   the end of the simulated page references we have to simulate.
 *   An exception is thrown if no more simulated page references
 *   are available when this method is called.
 */
void PagingSystem::processNextPageReference()
{
  // test if we still have a next page reference to simulate
  if (systemTime >= numPageReferences)
  {
    stringstream msg;
    msg << "<PagingSystem::processNextPageReference> Error, reached"
        << " end of simulation, no more simulated page references"
        << " available, numPageReferences: " << numPageReferences << " systemTime: " << systemTime << endl;
    throw SimulatorException(msg.str());
  }

  // if current page reference is a hit, update system performance
  // statistics and we are done
  if (isPageHit())
  {
    // notify paging scheme as it may need to know the page was hit to update
    // its algorithm
    FrameNumber frame = findFrameOfCurrentPage();
    scheme->pageHit(frame);

    // update system statistics here
    hitCount++;
  }
  // otherwise it was a miss, so determine if we need to do
  // an initial page placement, or a page replacement
  // if memory is full, we need to do a replacement
  else
  {
    if (isMemoryFull())
    {
      // page replacement
      // select frame to remove from memory
      // replace selected frame with the current page reference
      doPageReplacement();
      replacementCount++;
      faultCount++;
    }
    // otherwise we need to do a simple page placement
    else
    {
      // page placement
      // select next empty frame and place the page reference in
      // the free frame
      doPagePlacement();
      placementCount++;
      faultCount++;
    }
  }

  // update system statistics and system simulation variables
  incrementSystemTime();
}

/**
 * @brief page placement
 *
 * Page placement occurs whenever memory is not yet full and there
 * are free frames available.  A memory management system of course
 * prefers to use a free frame of memory when available rather than
 * going through the expense of selecting and removing a frame.
 * We simulate the simplest page placement for our simulator here.
 * We scan memory and select the first (lowest numbered) free frame
 * of memory for page placement.
 *
 * @throws SimulatorException An exception is thrown if this method
 *   is called when memory is already full.  We cannot do a page
 *   placement into a full memory (that requres a replacement).
 */
void PagingSystem::doPagePlacement()
{
  // unit test task 4, first of all, if memory is full, throw
  // an exception saying Error, cannot do initial page placement
  // when memory already full.

  // otherwise if memory is not full, you need to search memory
  // to find the first empty frame

  // and then once you find the frame, you should put the current
  // pageReference for the current systemTime into that frame of
  // memory
}

/**
 * @brief page RE placement
 *
 * Page REplacement occurs when memory is full.  Before we can
 * place the next page reference into a physical memory frame, we
 * must select a frame to be replaced.  In a real OS the replaced
 * page needs to be written back out to secondary storage if it is
 * dirty (modified).  Then we can simply load the new references
 * page from secondary storage to the newly freed up frame.
 */
void PagingSystem::doPageReplacement()
{
  // sanity check, we should only be called when memory is
  // full, throw an exception if this is not the case
  if (not isMemoryFull())
  {
    stringstream msg;
    msg << "<PagingSystem::doPageReplacement> Error, memory is not yet full"
        << " replacement decisions are not made until memory becomes full" << endl;
    throw SimulatorException(msg.str());
  }

  // call method to make the replacment decision and select the frame
  // of memory to be removed
  FrameNumber frameToReplace = makeReplacementDecision();

  // we have made the replacment decision of which frame to be kicked
  // out and replace.  In real system we would first have to check if
  // frame is dirty and write it out, then we would load the newly
  // referenced page to the now freed up frame
  memory[frameToReplace] = pageReference[systemTime];
}

/**
 * @brief make replacement decision
 *
 * Given current state of memory, and other information like past
 * history of references, future history, modify and reference bits,
 * etc, make a page replacement decision.  When all is said and done,
 * the replacement decision simply results in a frame number of the
 * physical frame of memory that should be kicked out and replaced
 * by the new page reference.
 *
 * @returns int Returns the frame number of the page selected to
 *   be replaced from physical memory.
 */
FrameNumber PagingSystem::makeReplacementDecision()
{
  // Have our page replacement scheme make the page replacement
  // decision given the current system state and history
  FrameNumber frameToReplace = scheme->makeReplacementDecision();

  // return the frame to replace
  return frameToReplace;
}

/**
 * @brief run simulation
 *
 * Run a full simulation of a paging system.  Before calling
 * this method, make sure a valid page stream has been
 * loaded or created, and make sure you have set the
 * page replacement scheme you wish to simulation.
 *
 * This method will step through each page reference in the
 * currently loaded page reference scheme, making page
 * placement and replacement decisions and managing the simulated
 * memory based on the page replacement decisions.  Page replacement
 * decisions are made by a helper PageReplacementScheme class that
 * implements different page replacement algorithms such as fifo,
 * LRU, Optimal, and Clock.
 *
 * @param verbose If true we will display information about state
 *   of system to standard output after each page reference event
 *   (whether a hit or miss), including state of memory (the
 *   physical frames) and current hit/miss statistics.  Default
 *   values is false, do not display this information.
 *
 * @throws Throws an exception if now page reference stream has
 *   been (pre)loaded and is ready for the simulation to use.
 */
void PagingSystem::runSimulation(bool verbose)
{
  // check that a page reference stream is loaded and ready to
  // simulate first before beginning
  if ((numPageReferences <= 0) or (pageReference == NULL))
  {
    stringstream msg;
    msg << "<PagingSystem::runSimulation> Error, you must load or"
        << " generate a page reference stream first before running"
        << " a simulation" << endl;
    throw SimulatorException(msg.str());
  }

  // initial header/information before start of simulation
  if (verbose)
  {
    cout << "Paging Simulation" << endl
         << "=====================================" << endl
         << "memory size          : " << memorySize << endl
         << "reference stream size: " << numPageReferences << endl
         << "paging scheme        : fifo" << endl
         << endl;
  }

  // simulate time passing in terms of each new page
  // refernce that is made in the running system
  double hitRatio;
  double missRatio;
  string pageStatus;
  for (int time = 0; time < numPageReferences; time++)
  {
    // save status before processing for verbose output
    if (verbose)
    {
      pageStatus = getPageStatus();
    }

    // perform the next page reference
    processNextPageReference();

    // display system state after processing page reference if
    // asked to
    if (verbose)
    {
      // time step and memory contents
      cout << "-------------------------------------" << endl
           << "system time   : " << time << endl
           << "page reference: " << pageReference[time] << endl
           << "page status   : " << pageStatus << endl
           << endl;

      // let replacement scheme represent its internal status at this
      // moment in the simulations progress
      cout << scheme->getSchemeStatus() << endl;

      // current system statistics
      hitRatio = (double)hitCount / (double)systemTime;
      missRatio = (double)faultCount / (double)systemTime;
      cout << "Hit  ratio : " << hitCount << " / " << systemTime << " (ratio = " << hitRatio << ")" << endl
           << "Fault ratio: " << faultCount << " / " << systemTime << " (ratio = " << missRatio << ")" << endl
           << endl
           << "Hit count        : " << hitCount << endl
           << "Placement count  : " << placementCount << endl
           << "Replacement count: " << replacementCount << endl
           << endl;
    }
  }
}