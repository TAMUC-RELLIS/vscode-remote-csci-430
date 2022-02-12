/** @file assg01-tests.cpp
 * @brief Unit tests for Hypothetical Machine simulation
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2020
 * @note   ide:  VS Code Editor/IDE ; GNU gcc tools
 *
 * Unit tests for assignment 1, the hypothetical machine simulator.
 * You should start with the first set of tests in the first TEST_CASE,
 * and get the tests to pass in order from the first one in this file
 * to the last one.  If all unit tests pass, you will most likely have
 * a working system simulator for this assignment.
 */
#include "HypotheticalMachineSimulator.hpp"
#include "SimulatorException.hpp"
#include "catch.hpp"
#include <string>
using namespace std;

/// simulator instance used for all of the tests
HypotheticalMachineSimulator sim;

/**
 * @brief test memory initialization
 */
TEST_CASE("<initializeMemory()> HypotheticalMachineController test memory initialization", "[member]")
{
  // make sure memory set correctly, especially memory size determined correctly
  sim.initializeMemory(300, 1000);
  CHECK(sim.getMemoryBaseAddress() == 300);
  CHECK(sim.getMemoryBoundsAddress() == 1000);
  CHECK(sim.getMemorySize() == 700);

  // reset should be working to reset state of simulator
  sim.reset();
  CHECK(sim.getMemoryBaseAddress() == 0);
  CHECK(sim.getMemoryBoundsAddress() == 0);
  CHECK(sim.getMemorySize() == 0);

  // another random test
  sim.initializeMemory(42, 917);
  CHECK(sim.getMemoryBaseAddress() == 42);
  CHECK(sim.getMemoryBoundsAddress() == 917);
  CHECK(sim.getMemorySize() == (917 - 42));

  // we use XYYY addresses, where X is an opcode and YYY is a reference
  // address, thus memory can't exceed 1000, only valid memory is 0 - 999
  sim.reset();
  CHECK_THROWS_AS(sim.initializeMemory(99, 1001), SimulatorException);
}

/**
 * @brief test memory address translation
 */
TEST_CASE("<translateAddress()> HypotheticalMachineController test memory address translation", "[member()]")
{
  // a typical memory address space to test first
  sim.initializeMemory(300, 1000);
  CHECK(sim.getMemoryBaseAddress() == 300);
  CHECK(sim.getMemoryBoundsAddress() == 1000);
  CHECK(sim.getMemorySize() == 700);

  // test some translations of addresses in this address space
  CHECK(sim.translateAddress(300) == 0);
  CHECK(sim.translateAddress(476) == 176);
  CHECK(sim.translateAddress(999) == 699); // last legal address in ths address space

  // check bounds testing, we should get exception if try and reference an
  // illegal address
  CHECK_THROWS_AS(sim.translateAddress(299), SimulatorException);
  CHECK_THROWS_AS(sim.translateAddress(1000), SimulatorException);

  // a second more difficult memory address space
  sim.initializeMemory(187, 432);
  CHECK(sim.getMemoryBaseAddress() == 187);
  CHECK(sim.getMemoryBoundsAddress() == 432);
  CHECK(sim.getMemorySize() == (432 - 187));

  // test some translations of addresses in this address space
  CHECK(sim.translateAddress(187) == 0);
  CHECK(sim.translateAddress(217) == 30);
  CHECK(sim.translateAddress(432 - 1) == (432 - 187 - 1)); // last legal address in ths address space

  // check bounds testing, we should get exception if try and reference an
  // illegal address
  CHECK_THROWS_AS(sim.translateAddress(186), SimulatorException);
  CHECK_THROWS_AS(sim.translateAddress(432), SimulatorException);
}

/**
 * @brief test memory access functions
 */
TEST_CASE("<peek() and poke()> HypotheticalMachineController test memory peeks and pokes", "[member]")
{
  // a typical memory address space to test first
  sim.initializeMemory(300, 1000);
  CHECK(sim.getMemoryBaseAddress() == 300);
  CHECK(sim.getMemoryBoundsAddress() == 1000);
  CHECK(sim.getMemorySize() == 700);

  // poke some random locations then peek and make sure
  // we get same value back
  sim.pokeAddress(300, 42);
  CHECK(sim.peekAddress(300) == 42);

  sim.pokeAddress(999, 1867);
  CHECK(sim.peekAddress(999) == 1867);

  sim.pokeAddress(456, 789);
  CHECK(sim.peekAddress(456) == 789);

  sim.pokeAddress(789, 456);
  CHECK(sim.peekAddress(789) == 456);

  // should still be illegal to peek and poke to addresses beyond
  // our simulation memory address space
  CHECK_THROWS_AS(sim.pokeAddress(299, 42), SimulatorException);
  CHECK_THROWS_AS(sim.peekAddress(299), SimulatorException);
  CHECK_THROWS_AS(sim.pokeAddress(1000, 42), SimulatorException);
  CHECK_THROWS_AS(sim.peekAddress(1000), SimulatorException);
}

/**
 * @brief test program loading function
 */
TEST_CASE("<loadProgram()> HypotheticalMachineController test program load", "[member]")
{
  // should be throwing exception when file name is not correct
  string progFile = "simfiles/badfile.sim";
  CHECK_THROWS_AS(sim.loadProgram(progFile), SimulatorException);

  // load actual program and see we get expected values into
  // the hypothetical machine
  progFile = "simfiles/prog-01.sim";
  sim.loadProgram(progFile);
  CHECK(sim.getPC() == 300);
  CHECK(sim.getAC() == 0);
  CHECK(sim.getIR() == 0);
  CHECK(sim.getMemoryBaseAddress() == 300);
  CHECK(sim.getMemoryBoundsAddress() == 1000);
  CHECK(sim.getMemorySize() == 700);

  // test memory was loaded as expected
  CHECK(sim.peekAddress(300) == 1940);
  CHECK(sim.peekAddress(301) == 5941);
  CHECK(sim.peekAddress(302) == 2941);
  CHECK(sim.peekAddress(303) == 0);
  CHECK(sim.peekAddress(939) == 0);
  CHECK(sim.peekAddress(940) == 3);
  CHECK(sim.peekAddress(941) == 2);
  CHECK(sim.peekAddress(942) == 0);

  // load another program for more tests
  progFile = "simfiles/prog-02.sim";
  sim.loadProgram(progFile);
  CHECK(sim.getPC() == 50);
  CHECK(sim.getAC() == 0);
  CHECK(sim.getIR() == 0);
  CHECK(sim.getMemoryBaseAddress() == 50);
  CHECK(sim.getMemoryBoundsAddress() == 150);
  CHECK(sim.getMemorySize() == 100);

  // test memory was loaded as expected
  CHECK(sim.peekAddress(50) == 1141);
  CHECK(sim.peekAddress(51) == 5140);
  CHECK(sim.peekAddress(52) == 3051);
  CHECK(sim.peekAddress(53) == 4142);
  CHECK(sim.peekAddress(54) == 0);
  CHECK(sim.peekAddress(140) == 2);
  CHECK(sim.peekAddress(141) == 4);
  CHECK(sim.peekAddress(142) == 8);
  CHECK(sim.peekAddress(143) == 0);
}

/**
 * @brief test fetch phase
 */
TEST_CASE("<fetch()> HypotheticalMachineController test fetch phase", "[member]")
{
  // load a program and check results of performing fetch cycles
  string progFile = "simfiles/prog-01.sim";
  sim.loadProgram(progFile);

  // initially in prog-01 PC is 300, should fetch instruction 1940
  // and then we fetch until the 0/noop/halt
  sim.fetch();
  CHECK(sim.getIR() == 1940);
  CHECK(sim.getPC() == 300);
  sim.incrementPC();

  sim.fetch();
  CHECK(sim.getIR() == 5941);
  CHECK(sim.getPC() == 301);
  sim.incrementPC();

  sim.fetch();
  CHECK(sim.getIR() == 2941);
  CHECK(sim.getPC() == 302);
  sim.incrementPC();

  sim.fetch();
  CHECK(sim.getIR() == 0);
  CHECK(sim.getPC() == 303);
  sim.incrementPC();

  // load a second program and step through it
  progFile = "simfiles/prog-02.sim";
  sim.loadProgram(progFile);

  // initially in prog-01 PC is 300, should fetch instruction 1940
  // and then we fetch until the 0/noop/halt
  sim.fetch();
  CHECK(sim.getIR() == 1141);
  CHECK(sim.getPC() == 50);
  sim.incrementPC();

  sim.fetch();
  CHECK(sim.getIR() == 5140);
  CHECK(sim.getPC() == 51);
  sim.incrementPC();

  sim.fetch();
  CHECK(sim.getIR() == 3051);
  CHECK(sim.getPC() == 52);
  sim.incrementPC();

  sim.fetch();
  CHECK(sim.getIR() == 4142);
  CHECK(sim.getPC() == 53);
  sim.incrementPC();

  sim.fetch();
  CHECK(sim.getIR() == 0);
  CHECK(sim.getPC() == 54);
  sim.incrementPC();
}

/**
 * @brief test execute phase
 */
TEST_CASE("<execute()> HypotheticalMachineController test ir translation in execute()", "[method]")
{
  // the execute() part of cycle starts out by translating
  // the fetched ir into opcode and address parts, test these are translated
  // correctly
  string progFile = "simfiles/prog-01.sim";
  sim.loadProgram(progFile);
  sim.fetch();
  CHECK(sim.getIR() == 1940);
  sim.execute();
  CHECK(sim.getIROpcode() == 1);
  CHECK(sim.getIRAddress() == 940);

  sim.fetch();
  CHECK(sim.getIR() == 5941);
  sim.execute();
  CHECK(sim.getIROpcode() == 5);
  CHECK(sim.getIRAddress() == 941);

  sim.fetch();
  CHECK(sim.getIR() == 2941);
  sim.execute();
  CHECK(sim.getIROpcode() == 2);
  CHECK(sim.getIRAddress() == 941);

  // test that a nonsensical ir value is detected
  sim.pokeAddress(303, 10000); // only values of 0000 - 9999 make sense in this sim
  sim.fetch();
  CHECK(sim.getIR() == 10000);
  CHECK_THROWS_AS(sim.execute(), SimulatorException);

  // check a second set of translations to ensure working
  progFile = "simfiles/prog-02.sim";
  sim.loadProgram(progFile);
  sim.fetch();
  CHECK(sim.getIR() == 1141);
  sim.execute();
  CHECK(sim.getIROpcode() == 1);
  CHECK(sim.getIRAddress() == 141);

  sim.fetch();
  CHECK(sim.getIR() == 5140);
  sim.execute();
  CHECK(sim.getIROpcode() == 5);
  CHECK(sim.getIRAddress() == 140);

  sim.fetch();
  CHECK(sim.getIR() == 3051);
  sim.execute();
  CHECK(sim.getIROpcode() == 3);
  CHECK(sim.getIRAddress() == 51);
}

/**
 * @brief test load instruction
 */
TEST_CASE("<executeLoad()> HypotheticalMachineController test load instruction", "[member]")
{
  // prog-03 tests load instructions
  string progFile = "simfiles/prog-03.sim";
  sim.loadProgram(progFile);

  // fetch and execute the 3 load instructions and test the result is
  // as we expect
  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 1);
  CHECK(sim.getIRAddress() == 150);
  CHECK(sim.getAC() == 42);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 1);
  CHECK(sim.getIRAddress() == 175);
  CHECK(sim.getAC() == -5);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 1);
  CHECK(sim.getIRAddress() == 190);
  CHECK(sim.getAC() == 123);

  // load from out of bounds reference should fail
  sim.fetch();
  CHECK_THROWS_AS(sim.execute(), SimulatorException);
}

/**
 * @brief test store instruction
 */
TEST_CASE("<executeStore()> HypotheticalMachineController test store instruction", "[member]")
{
  // prog-04 tests store instructions
  string progFile = "simfiles/prog-04.sim";
  sim.loadProgram(progFile);

  // fetch and execute the 3 store instructions and test the result is
  // as we expect
  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 2);
  CHECK(sim.getIRAddress() == 250);
  CHECK(sim.getAC() == 32);
  CHECK(sim.peekAddress(250) == 32);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 2);
  CHECK(sim.getIRAddress() == 242);
  CHECK(sim.getAC() == 32);
  CHECK(sim.peekAddress(242) == 32);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 2);
  CHECK(sim.getIRAddress() == 287);
  CHECK(sim.getAC() == 32);
  CHECK(sim.peekAddress(287) == 32);

  // next instruction loads from out of bounds reference and should fail
  sim.fetch();
  CHECK_THROWS_AS(sim.execute(), SimulatorException);
}

/**
 * @brief test add and subtract instructions
 */
TEST_CASE("<executeAdd() and executeSubtract()> HypotheticalMachineController test add and subtract instructions", "[member]")
{
  // prog-05 tests addition and subtraction
  string progFile = "simfiles/prog-05.sim";
  sim.loadProgram(progFile);

  // subtract SUB=4
  // additon  ADD=5
  // fetch and execute the 8 instructions in this test program and determine
  // if the results are calculated as we expect
  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 4);
  CHECK(sim.getIRAddress() == 701);
  CHECK(sim.getAC() == 41);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 5);
  CHECK(sim.getIRAddress() == 701);
  CHECK(sim.getAC() == 42);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 4);
  CHECK(sim.getIRAddress() == 702);
  CHECK(sim.getAC() == 43);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 5);
  CHECK(sim.getIRAddress() == 702);
  CHECK(sim.getAC() == 42);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 4);
  CHECK(sim.getIRAddress() == 703);
  CHECK(sim.getAC() == 35);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 5);
  CHECK(sim.getIRAddress() == 704);
  CHECK(sim.getAC() == 30);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 4);
  CHECK(sim.getIRAddress() == 705);
  CHECK(sim.getAC() == 15);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 5);
  CHECK(sim.getIRAddress() == 705);
  CHECK(sim.getAC() == 30);
}

/**
 * @brief test jump instruction
 */
TEST_CASE("<executeJump()> HypotheticalMachineController test jump instructions", "[member]")
{
  // prog-06 tests jump instructions
  string progFile = "simfiles/prog-06.sim";
  sim.loadProgram(progFile);

  // JMP=6
  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 3);
  CHECK(sim.getIRAddress() == 750);
  CHECK(sim.getPC() == 750);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 3);
  CHECK(sim.getIRAddress() == 725);
  CHECK(sim.getPC() == 725);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 3);
  CHECK(sim.getIRAddress() == 790);
  CHECK(sim.getPC() == 790);

  sim.fetch();
  sim.execute();
  CHECK(sim.getIROpcode() == 0);
  CHECK(sim.getIRAddress() == 0);
}

/**
 * @brief test full simulation
 */
TEST_CASE("<fetch/execute cycles> HypotheticalMachineController test execution simulation of whole programs", "[simulation]")
{
  // test program 01 execution
  string progFile = "simfiles/prog-01.sim";
  sim.loadProgram(progFile);

  int cycle = sim.runSimulation();
  CHECK(cycle == 4);
  CHECK(sim.getPC() == 303);
  CHECK(sim.getAC() == 5);
  CHECK(sim.peekAddress(941) == 5);

  // test program 02 execution
  // has an infinite loop so will run for the max cycles
  progFile = "simfiles/prog-02.sim";
  sim.loadProgram(progFile);

  cycle = sim.runSimulation();
  CHECK(cycle == 100);
  CHECK(sim.getPC() == 52);
  CHECK(sim.getAC() == 104);
}