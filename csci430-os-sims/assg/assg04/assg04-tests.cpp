/** @file assg04-tests.cpp
 * @brief Unit tests for page replacement scheme simulations and
 *   specifically for the implementation of the Clock Algorithm
 *   page replacement scheme.
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Unit tests for assignment 04, Clock Algorithm page replacement
 * scheme simulation.
 */
#include "FifoPageReplacementScheme.hpp"
#include "PageReplacementScheme.hpp"
#include "PagingSystem.hpp"
#include "SimulatorException.hpp"
#include "catch.hpp"

using namespace std;

/**
 * @brief Test PagingSystem construction and page stream creation
 */
TEST_CASE("Test PagingSystem basic construction and page stream creation", "[Test PagingSystem construction page stream creation]")
{
  // a basic paging system simulation with 5 physical frames of memory
  PagingSystem sim(5);

  CHECK(sim.getMemorySize() == 5);
  CHECK(sim.getSystemTime() == 0);
  CHECK(sim.getNumPageReferences() == 0);
  CHECK(not sim.isMemoryFull());

  // test bad file name exceptions
  CHECK_THROWS_AS(sim.loadPageStream("simfiles/bogus.sim"), SimulatorException);

  // test loading simulated page reference streams from file
  sim.loadPageStream("simfiles/pageref-01.sim");
  CHECK(sim.getNumPageReferences() == 12);
  CHECK(sim.pageStreamToString() == "[ 2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2 ]");

  sim.loadPageStream("simfiles/pageref-02.sim");
  CHECK(sim.getNumPageReferences() == 30);
  CHECK(sim.pageStreamToString() == "[ 6, 5, 2, 4, 2, 4, 3, 5, 3, 6, 7, 5, 3, 5, 4, 3, 4, 7, 2, 1, 3, 7, 6, 4, 1, 2, 1, 3, 4, 7 ]");

  // test randomly generated page reference stream
  sim.generateRandomPageStream(1, 10, 42);
  CHECK(sim.getNumPageReferences() == 1);
  CHECK(sim.pageStreamToString() == "[ 7 ]");

  sim.generateRandomPageStream(20, 100, 42);
  CHECK(sim.getNumPageReferences() == 20);
  CHECK(sim.pageStreamToString() == "[ 67, 41, 82, 42, 13, 59, 22, 41, 36, 44, 75, 44, 18, 5, 97, 63, 93, 49, 99, 60 ]");

  sim.generateRandomPageStream(1000000, 100, 42);
  CHECK(sim.getNumPageReferences() == 1000000);
}

/**
 * @brief Test basic paging simulation functions
 */
TEST_CASE("Test basic paging simulation functions", "[Test basic paging simulation functions]")
{
  // create a basic paging system simulation with 3 physical frames of
  // and load the basic page stream from simulation 01
  PagingSystem sim(3);
  sim.loadPageStream("simfiles/pageref-01.sim");

  // populate memory with some initial page reference for testing
  sim.pokeMemory(0, 2); // memory[0] 2
  CHECK(sim.peekMemory(0) == 2);
  sim.pokeMemory(1, 1); // memory[1] 1
  CHECK(sim.peekMemory(1) == 1);
  sim.pokeMemory(2, 4); // memory[2] 4
  CHECK(sim.peekMemory(2) == 4);

  CHECK(sim.getMemorySize() == 3);
  CHECK(sim.getSystemTime() == 0);
  CHECK(sim.getNumPageReferences() == 12);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 1, 4 ]");

  // test hit or miss determination and system time increment
  // systemTime = 0 is a hit
  CHECK(sim.isPageHit());

  // systemTime = 1 is a miss
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 1);
  CHECK(not sim.isPageHit());

  // systemTime = 2 is a hit
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 2);
  CHECK(sim.isPageHit());

  // systemTime = 3 is a hit
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 3);
  CHECK(sim.isPageHit());

  // systemTime = 4 is a miss
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 4);
  CHECK(not sim.isPageHit());

  // systemTime = 5 is a hit
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 5);
  CHECK(sim.isPageHit());

  // systemTime = 6 is a hit
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 6);
  CHECK(sim.isPageHit());

  // systemTime = 7 is a miss
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 7);
  CHECK(not sim.isPageHit());

  // systemTime = 8 is a miss
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 8);
  CHECK(not sim.isPageHit());

  // systemTime = 9 is a hit
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 9);
  CHECK(sim.isPageHit());

  // systemTime = 10 is a miss
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 10);
  CHECK(not sim.isPageHit());

  // systemTime = 11 is a hit
  sim.incrementSystemTime();
  CHECK(sim.getSystemTime() == 11);
  CHECK(sim.isPageHit());
}

/**
 * @brief Test page placement
 */
TEST_CASE("Test initial page placement into empty frames", "[Test page placement]")
{
  // create a basic paging system simulation with 3 physical frames of
  // and load the basic page stream from simulation 01
  PagingSystem sim(3);
  sim.loadPageStream("simfiles/pageref-01.sim");

  // memory is initially empty.  Calling processNextPageReference()
  // should cause initial page placements to occur, until memory
  // becomes full.
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 1);
  CHECK(not sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 0, 0 ]");

  // next reference will go to next free frame
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 2);
  CHECK(not sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 3, 0 ]");

  // next reference is a hit, memory should not change
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 3);
  CHECK(not sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 3, 0 ]");

  // next reference is a miss and it fills up our 3 frame memory
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 4);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 3, 1 ]");

  // doPagePlacement() should never be called when memory is full
  // test correctly throws exception here
  CHECK_THROWS_AS(sim.doPagePlacement(), SimulatorException);

  // if we free up some frames of memory, we should be able to
  // continue with page placements
  sim.pokeMemory(0, EMPTY_FRAME);
  sim.pokeMemory(2, EMPTY_FRAME);
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 5);
  CHECK(not sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 5, 3, 0 ]");

  // next reference is a miss
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 6);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 5, 3, 2 ]");
}

/**
 * @brief Test fifo page replacement
 */
TEST_CASE("Test basic page replacement using fifo replacement scheme", "[Test basic page replacement]")
{
  // create a basic paging system simulation with 3 physical frames of
  // and load the basic page stream from simulation 01
  PagingSystem sim(3);
  sim.loadPageStream("simfiles/pageref-01.sim");

  // test that doPageReplacement() throws exception if called when
  // memory is not full
  CHECK_THROWS_AS(sim.doPageReplacement(), SimulatorException);

  // first 4 page references should cause 3 page placements (3 misses
  // and 1 hit) where we end up with a full memory
  for (int time = 0; time < 4; time++)
  {
    sim.processNextPageReference();
  }
  CHECK(sim.getSystemTime() == 4);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 3, 1 ]");

  // memory is now full, we can now check the fifo page replacement
  // next memory reference is page 5, should replace page 2 in
  // frame 0
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 5);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 5, 3, 1 ]");

  // next reference is to page 2, another miss, page 3 in frame 1
  // should be replaced
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 6);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 5, 2, 1 ]");

  // next reference is again a miss, replace frame 2 page 1 with
  // page 4
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 7);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 5, 2, 4 ]");

  // next reference is to page 5 which is a hit, memory should not change
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 8);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 5, 2, 4 ]");

  // next refernce is page 3, a miss.  Test wrap around back to
  // beginning of physical memory, frame 0/page 5 should be replaced
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 9);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 3, 2, 4 ]");

  // next reference is a hit on page 2, no changes in memory
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 10);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 3, 2, 4 ]");

  // next reference to page 5 is a miss, replace frame 1/page 2
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 11);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 3, 5, 4 ]");

  // final reference is to page 2, which is a miss again, replace
  // frame 2/page 4
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 12);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 3, 5, 2 ]");

  // we have reached end of simulation, it is an error to try
  // and continue processing page references
  CHECK_THROWS_AS(sim.processNextPageReference(), SimulatorException);
}

/**
 * @brief Test full simulation exectuon on the default fifo page
 *   replacement scheme
 */
TEST_CASE("Test full fifo simulation execution", "[Test full fifo simulation execution]")
{
  // create a basic paging system simulation with 3 physical frames of
  // and load the basic page stream from simulation 01
  PagingSystem sim(3);

  // test that runSimulaiton() properly croaks if not page stream
  // has been loaded to simulate yet
  CHECK_THROWS_AS(sim.runSimulation(), SimulatorException);

  // load the simulation 01 and run the simulation to the end
  sim.loadPageStream("simfiles/pageref-01.sim");
  sim.runSimulation();
  CHECK(sim.memoryToString() == "[ 3, 5, 2 ]");

  // load the simulation 02 and run the simulation to the end
  sim.loadPageStream("simfiles/pageref-02.sim");
  sim.runSimulation();
  CHECK(sim.memoryToString() == "[ 4, 7, 3 ]");

  // create a long random simulation with a known seed and
  // ensure always end up with same memory contents using
  // fifo replacement scheme
  sim.generateRandomPageStream(1000000, 100, 42);
  CHECK(sim.getNumPageReferences() == 1000000);
  sim.runSimulation();
  CHECK(sim.memoryToString() == "[ 21, 56, 70 ]");
}

/**
 * @brief Test clock page replacement
 */
TEST_CASE("Test basic page replacement using clock replacement scheme", "[Test basic page replacement]")
{
  // create a  paging system simulation with 4 physical frames of
  // memory using clock page replacment
  // and load the basic page stream from simulation 01
  PagingSystem sim(4, CLOCK);
  sim.loadPageStream("simfiles/pageref-01.sim");

  // test that doPageReplacement() throws exception if called when
  // memory is not full
  CHECK_THROWS_AS(sim.doPageReplacement(), SimulatorException);

  // first 5 page references should cause 4 page placements (4 misses
  // and 1 hit) where we end up with a full memory
  for (int time = 0; time < 5; time++)
  {
    sim.processNextPageReference();
  }
  CHECK(sim.getSystemTime() == 5);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 3, 1, 5 ]");

  // memory is now full, we can now check the clock page replacement
  // next memory reference is page 2, which is a hit
  // frame 0
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 6);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 2, 3, 1, 5 ]");

  // next page reference is to page 4, a fault, replace frame 0
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 7);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 4, 3, 1, 5 ]");

  // next reference is to page 5 which is a hit, memory should not change
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 8);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 4, 3, 1, 5 ]");

  // next refernce is page 3 a hit, memory does not change
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 9);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 4, 3, 1, 5 ]");

  // next reference is a hit on page 2, a fault, page 2 replaces
  // frame 2
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 10);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 4, 3, 2, 5 ]");

  // next reference to page 5 is a hit, no change in memory
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 11);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 4, 3, 2, 5 ]");

  // final reference is to page 2 is a hit, no change in memory
  sim.processNextPageReference();
  CHECK(sim.getSystemTime() == 12);
  CHECK(sim.isMemoryFull());
  CHECK(sim.memoryToString() == "[ 4, 3, 2, 5 ]");

  // we have reached end of simulation, it is an error to try
  // and continue processing page references
  CHECK_THROWS_AS(sim.processNextPageReference(), SimulatorException);
}

/**
 * @brief Test full simulation exectuon on the clock page
 *   replacement scheme
 */
TEST_CASE("Test full clock simulation execution", "[Test full clock simulation execution]")
{
  // create a basic paging system simulation with 3 physical frames of
  // and load the basic page stream from simulation 01
  PagingSystem sim(4, CLOCK);

  // test that runSimulaiton() properly croaks if not page stream
  // has been loaded to simulate yet
  CHECK_THROWS_AS(sim.runSimulation(), SimulatorException);

  // load the simulation 01 and run the simulation to the end
  sim.loadPageStream("simfiles/pageref-01.sim");
  sim.runSimulation();
  CHECK(sim.memoryToString() == "[ 4, 3, 2, 5 ]");

  // load the simulation 02 and run the simulation to the end
  sim.loadPageStream("simfiles/pageref-02.sim");
  sim.runSimulation();
  CHECK(sim.memoryToString() == "[ 2, 4, 3, 7 ]");

  // create a long random simulation with a known seed and
  // ensure always end up with same memory contents using
  // clock replacement scheme
  sim.generateRandomPageStream(1000000, 100, 42);
  CHECK(sim.getNumPageReferences() == 1000000);
  sim.runSimulation();
  CHECK(sim.memoryToString() == "[ 56, 84, 21, 70 ]");
}
