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
#include "SchedulingSystem.hpp"
#include "SimulatorException.hpp"
#include "catch.hpp"

using namespace std;

/**
 * @brief Test SchedulingSystem construction and page stream creation
 */
TEST_CASE("Test Schedulingsystem basic construction and process table creation", "[Test SchedulingSystem construction and process table]")
{
  // a basic scheduling system simulator that defaults to FCFS scheduling policy
  SchedulingSystem sim;

  CHECK(sim.getSystemTime() == 0);
  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");

  // test bad file name exceptions
  CHECK_THROWS_AS(sim.loadProcessTable("simfiles/bogus.sim"), SimulatorException);

  // test loading simulated page reference streams from file
  sim.loadProcessTable("simfiles/process-table-01.sim");
  CHECK(sim.getNumProcesses() == 5);
  CHECK(not sim.allProcessesDone());
  CHECK(sim.processTableToString() == "[ (A 0 3) (B 2 6) (C 4 4) (D 6 5) (E 8 2) ]");

  sim.loadProcessTable("simfiles/process-table-02.sim");
  CHECK(sim.getNumProcesses() == 5);
  CHECK(not sim.allProcessesDone());
  CHECK(sim.processTableToString() == "[ (A 0 3) (B 1 5) (C 3 2) (D 9 5) (E 12 5) ]");

  sim.generateRandomProcessTable(10, 0.33, 10, 42);
  CHECK(sim.getNumProcesses() == 10);
  CHECK(not sim.allProcessesDone());
  CHECK(
    sim.processTableToString() == "[ (P0 0 1) (P1 3 9) (P2 6 4) (P3 9 5) (P4 10 3) (P5 11 9) (P6 15 10) (P7 23 8) (P8 26 1) (P9 27 2) ]");
}

/**
 * @brief Test  new process arrival and dispatch
 */
TEST_CASE("Test SchedulingSystem checkProcessArrivals()  and dispatchCpuIfIdle()", "[Test SchedulingSystem arrival and dispatch]")
{
  // a basic scheduling system simulator that defaults to using FCFS
  // scheduling policy
  SchedulingSystem sim;

  // load a simulation process table from file
  sim.loadProcessTable("simfiles/process-table-01.sim");
  CHECK(sim.getSystemTime() == 0);
  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");
  CHECK(sim.getNumProcesses() == 5);
  CHECK(not sim.allProcessesDone());
  CHECK(sim.processTableToString() == "[ (A 0 3) (B 2 6) (C 4 4) (D 6 5) (E 8 2) ]");

  // dispatch the first process
  sim.checkProcessArrivals();
  sim.dispatchCpuIfIdle();
  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "A");
}

/**
 * @brief Test simulate cpu cycles occurring
 */
TEST_CASE("Test SchedulingSystem simulateCpuCycle()", "[Test SchedulingSystem cpu cycle]")
{
  // a basic scheduling system simulator that defaults to using FCFS
  // scheduling policy
  SchedulingSystem sim;

  // load a simulation process table from file
  sim.loadProcessTable("simfiles/process-table-01.sim");
  CHECK(sim.getSystemTime() == 0);
  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");
  CHECK(sim.getNumProcesses() == 5);

  // run for 5 cycles and check system time
  for (int time = 0; time < 5; time++)
  {
    sim.simulateCpuCycle();
  }
  CHECK(sim.getSystemTime() == 5);

  // run for 5 more cycles and check system time
  for (int time = 0; time < 5; time++)
  {
    sim.simulateCpuCycle();
  }
  CHECK(sim.getSystemTime() == 10);
}

/**
 * @brief Test detecting process finished.  With this method,
 *   we can test full cycles of FCFS policy, as we have all
 *   of new arrivals, dispatching, simulating cpu and finishing
 *   processes done.
 */
TEST_CASE("Test SchedulingSystem checkProcessFinished()", "[Test SchedulingSystem process finished]")
{
  // a basic scheduling system simulator that defaults to using FCFS
  // scheduling policy
  SchedulingSystem sim;

  // load a simulation process table from file
  sim.loadProcessTable("simfiles/process-table-01.sim");
  CHECK(sim.getSystemTime() == 0);
  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");
  CHECK(sim.getNumProcesses() == 5);

  // check new arrivals and dispatch, so that first process A is
  // scheduled to run on the CPU
  sim.checkProcessArrivals();
  sim.dispatchCpuIfIdle();

  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "A");

  // process A has a service time of 3, so if we run 3 cycles, the
  // system should end up with A finished and the cpu idle again
  for (int time = 0; time < 3; time++)
  {
    sim.checkProcessArrivals();
    sim.dispatchCpuIfIdle();
    sim.simulateCpuCycle();
  }
  // process should still be on cpu untill we call checkProcessFinished
  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "A");

  sim.checkProcessFinished();

  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");
}

/**
 * @brief Single simulation  cycle tests
 *   Perform some system cycles by hand.
 */
TEST_CASE("Test SchedulingSystem test individual simulation cycles", "[Test SchedulingSystem individual simulation cycles]")
{
  // a basic scheduling system simulator that defaults to using FCFS
  // scheduling policy
  SchedulingSystem sim;

  // load a simulation process table from file
  sim.loadProcessTable("simfiles/process-table-01.sim");
  CHECK(sim.getSystemTime() == 0);
  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");
  CHECK(sim.getNumProcesses() == 5);

  // check new arrivals and dispatch, so that first process A is
  // scheduled to run on the CPU
  sim.checkProcessArrivals();
  sim.dispatchCpuIfIdle();
  sim.simulateCpuCycle();

  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "A");

  // process A has a service time of 3, so if we run 2 more cycles, the
  // system should end up with A finished and the cpu idle again
  for (int time = 0; time < 2; time++)
  {
    sim.checkProcessArrivals();
    sim.dispatchCpuIfIdle();
    sim.simulateCpuCycle();
  }
  // process should still be on cpu untill we call checkProcessFinished
  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "A");

  sim.checkProcessFinished();

  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");

  // if we run next cycle, B should be successfully dispatched
  sim.checkProcessArrivals();
  sim.dispatchCpuIfIdle();
  sim.simulateCpuCycle();
  sim.checkProcessFinished();
  sim.checkProcessPreemption();

  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "B");
  CHECK(sim.getSystemTime() == 4);

  // process B has a service time of 6, so run 6 cycles and see that B
  // is finished and C is now running
  for (int time = 0; time < 6; time++)
  {
    sim.checkProcessArrivals();
    sim.dispatchCpuIfIdle();
    sim.simulateCpuCycle();
  }
  // process should still be on cpu untill we call checkProcessFinished
  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "B");

  sim.checkProcessFinished();

  CHECK(sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "IDLE");

  // if we run next cycle, C should be successfully dispatched
  sim.checkProcessArrivals();
  sim.dispatchCpuIfIdle();
  sim.simulateCpuCycle();
  sim.checkProcessFinished();
  sim.checkProcessPreemption();

  CHECK(not sim.isCpuIdle());
  CHECK(sim.getRunningProcessName() == "C");
  CHECK(sim.getSystemTime() == 11);
}

/**
 * @brief Test full runSimulation()
 *   Make sure runSimulation() runs to completion
 *   on FCFS example.
 */
TEST_CASE("Test SchedulingSystem runSimulation()", "[Test SchedulingSystem runSimulation()]")
{
  // a basic scheduling system simulator that defaults to using FCFS
  // scheduling policy
  SchedulingSystem sim;

  // load a simulation process table from file
  sim.loadProcessTable("simfiles/process-table-01.sim");

  // run the simulation to completion with default FCFS
  // policy using the first process table simulation
  sim.runSimulation(false);
  CHECK(sim.isCpuIdle());
  CHECK(sim.allProcessesDone());
  CHECK(sim.getSystemTime() == 20);
  CHECK(sim.finalSchedule() == "A  A  A  B  B  B  B  B  B  C  C  C  C  D  D  D  D  D  E  E  ");
  CHECK(sim.finalResultsTable() == "Name Arrv T_s  Strt End  T_r  T_r / T_s\n"
                                   "A    0    3    0    3    3    1.0000  \n"
                                   "B    2    6    3    9    7    1.1667  \n"
                                   "C    4    4    9    13   9    2.2500  \n"
                                   "D    6    5    13   18   12   2.4000  \n"
                                   "E    8    2    18   20   12   6.0000  \n");
}
