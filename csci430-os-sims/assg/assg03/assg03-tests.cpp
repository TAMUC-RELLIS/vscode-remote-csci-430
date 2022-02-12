/** @file assg03-tests.cpp
 * @brief Unit tests for Resouce Allocation Denial (Banker's algorithm)
 *   system tests.
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Unit tests for assignment 03, the Resource Allocation Denial
 * simulation.  We test the needed functions to implement handling the
 * loading of system state, modifying state, and determing if a state
 * is safe or not to make the allow/deny decision.
 */
#include "SimulatorException.hpp"
#include "State.hpp"
#include "catch.hpp"

using namespace std;

/**
 * @brief test State loadState() functionality
 */
TEST_CASE("Test State loadState() functionality", "[tate loadState]")
{
  State s;
  CHECK(s.getNumProcesses() == 0);
  CHECK(s.getNumResources() == 0);

  // try reading a nonexistent file, should throw exception
  CHECK_THROWS_AS(s.loadState("simfiles/bogus-file-name.sim"), SimulatorException);

  // try reading our actual test file
  s.loadState("simfiles/state-01.sim");
  CHECK(s.getNumProcesses() == 4);
  CHECK(s.getNumResources() == 3);

  string state01String = "Claim matrix C\n"
                         "    R0  R1  R2  \n"
                         "P0  3   2   2   \n"
                         "P1  6   1   3   \n"
                         "P2  3   1   4   \n"
                         "P3  4   2   2   \n"
                         "\n"
                         "Allocation matrix A\n"
                         "    R0  R1  R2  \n"
                         "P0  1   0   0   \n"
                         "P1  6   1   2   \n"
                         "P2  2   1   1   \n"
                         "P3  0   0   2   \n"
                         "\n"
                         "Need matrix C-A\n"
                         "    R0  R1  R2  \n"
                         "P0  2   2   2   \n"
                         "P1  0   0   1   \n"
                         "P2  1   0   3   \n"
                         "P3  4   2   0   \n"
                         "\n"
                         "Resource vector R\n"
                         "    R0  R1  R2  \n"
                         "    9   3   6   \n"
                         "\n"
                         "Available vector V\n"
                         "    R0  R1  R2  \n"
                         "    0   1   1   \n"
                         "\n";

  // cout << s;
  CHECK(s.tostring() == state01String);
}

/**
 * @brief test State  needsAreMet
 */
TEST_CASE("Test State needsAreMet() functionality", "[State needsAreMet]")
{
  // load the state-01 again for tests
  State s;
  s.loadState("simfiles/state-01.sim");

  // we will make our own currentAvailable vector, initially it is
  // the same as the available vector
  int currentAvailable[] = {0, 1, 1};

  // only P1 can have its needs met for this current available
  CHECK(not s.needsAreMet(0, currentAvailable));
  CHECK(s.needsAreMet(1, currentAvailable));
  CHECK(not s.needsAreMet(2, currentAvailable));
  CHECK(not s.needsAreMet(3, currentAvailable));

  // another test, given currentAvailable of 3,2,2
  // then P0 and P1 should be true (needs can be met)
  currentAvailable[0] = 3;
  currentAvailable[1] = 2;
  currentAvailable[2] = 2;

  CHECK(s.needsAreMet(0, currentAvailable));
  CHECK(s.needsAreMet(1, currentAvailable));
  CHECK(not s.needsAreMet(2, currentAvailable));
  CHECK(not s.needsAreMet(3, currentAvailable));

  // test no process needs can be met
  currentAvailable[0] = 4;
  currentAvailable[1] = 2;
  currentAvailable[2] = 3;

  CHECK(s.needsAreMet(0, currentAvailable));
  CHECK(s.needsAreMet(1, currentAvailable));
  CHECK(s.needsAreMet(2, currentAvailable));
  CHECK(s.needsAreMet(3, currentAvailable));

  // test all process needs can be met (max of each need)
  currentAvailable[0] = 1;
  currentAvailable[1] = 5;
  currentAvailable[2] = 0;

  CHECK(not s.needsAreMet(0, currentAvailable));
  CHECK(not s.needsAreMet(1, currentAvailable));
  CHECK(not s.needsAreMet(2, currentAvailable));
  CHECK(not s.needsAreMet(3, currentAvailable));
}

/**
 * @brief test State findCandidateProcess
 */
TEST_CASE("Test State findCandidateProcess() functionality", "[State findCandidateProcess]")
{
  // load the state-01 again for tests
  State s;
  s.loadState("simfiles/state-01.sim");

  // initialy for the state-01 file, P1 is the first process whose
  // would be a candidate given the current available resources
  // we will make our own currentAvailable vector, initially it is
  // the same as the available vector
  int currentAvailable[] = {0, 1, 1};

  // all process are not yet compeleted for first tests
  bool completed[] = {false, false, false, false};

  int candidateProcess;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 1);

  // if P1 is now marked (but available is not changed), no
  // other process is a candidate, so findCandidate should
  // fail
  completed[1] = true;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == NO_CANDIDATE);

  // if P1 resources were returned, the new current available
  // would be
  currentAvailable[0] = 6;
  currentAvailable[1] = 2;
  currentAvailable[2] = 3;

  // which means actually all remainig processes needs can be met,
  // the findCandidate should return the first it finds, P0
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 0);

  // to complete this simulation, P0 resources would be returned,
  // but this won't make a difference, if P0 is marked as complete
  // we should now determine P2 is a canddate
  completed[0] = true;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 2);

  // to finish, if P2 is now marked, then P3 is final candidate
  completed[2] = true;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 3);

  // when everything is marked completed,there should be no
  // candidates left
  completed[3] = true;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == NO_CANDIDATE);

  // check no process is complete, but still no candidate because
  // not enough resources for any process to complete
  completed[0] = false;
  completed[1] = false;
  completed[2] = false;
  completed[3] = false;

  currentAvailable[0] = 0;
  currentAvailable[1] = 5;
  currentAvailable[2] = 0;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == NO_CANDIDATE);

  // only P3 is a candidate because it is only process that
  // doesn't need any R2
  currentAvailable[0] = 4;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 3);
}

/**
 * @brief test State releaseAllocatedResources
 */
TEST_CASE("Test State releaseAllocatedResources() functionality", "[State releaseAllocatedResources]")
{
  // load the state-01 again for tests
  State s;
  s.loadState("simfiles/state-01.sim");

  // initialy for the state-01 file, P1 is the first process whose
  // would be a candidate given the current available resources
  // we will make our own currentAvailable vector, initially it is
  // the same as the available vector
  int currentAvailable[] = {0, 1, 1};

  // all process are not yet compeleted for first tests
  bool completed[] = {false, false, false, false};

  // we are simulating the isSafe() mechanism more fully here
  // We use findCandidate, then we will release the
  // resources of the candidate.  This is basically the steps
  // that need to happen in a loop in the isSafe() method...
  int candidateProcess;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 1);

  // release the process allocations
  s.releaseAllocatedResources(candidateProcess, currentAvailable);
  // and check the currentAvailable are as we would expect now
  CHECK(currentAvailable[0] == 6);
  CHECK(currentAvailable[1] == 2);
  CHECK(currentAvailable[2] == 3);

  // continue simulation of isSafe() steps.  P1 is now complete, and
  // currentAvailable have been updated, so find next candidate
  // process, which will be P0 and release its resources
  completed[candidateProcess] = true;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 0);
  s.releaseAllocatedResources(candidateProcess, currentAvailable);
  CHECK(currentAvailable[0] == 7);
  CHECK(currentAvailable[1] == 2);
  CHECK(currentAvailable[2] == 3);

  // mark P0 as complete, its resources were already released, and
  // find next candidate which will be P2 and release its allocations
  completed[candidateProcess] = true;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 2);
  s.releaseAllocatedResources(candidateProcess, currentAvailable);
  CHECK(currentAvailable[0] == 9);
  CHECK(currentAvailable[1] == 3);
  CHECK(currentAvailable[2] == 4);

  // only P3 left, find, mark and release its resources
  // final available should be equal to the system totalAvailable
  completed[candidateProcess] = true;
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == 3);
  s.releaseAllocatedResources(candidateProcess, currentAvailable);
  CHECK(currentAvailable[0] == 9);
  CHECK(currentAvailable[1] == 3);
  CHECK(currentAvailable[2] == 6);
  completed[candidateProcess] = true;

  // final test, there are plenty of resources available but all
  // processes are complete, so findCandidate should fail
  candidateProcess = s.findCandidateProcess(completed, currentAvailable);
  CHECK(candidateProcess == NO_CANDIDATE);
}

/**
 * @brief test State isSafe()
 */
TEST_CASE("Test State isSafe() functionality", "[State isSafe]")
{
  // load the state-01 again for tests
  // state 01 is safe, so check it
  State s;
  s.loadState("simfiles/state-01.sim");
  CHECK(s.isSafe());

  // load the state-02
  // state 02 is unsafe, so check it
  s.loadState("simfiles/state-02.sim");
  CHECK(not s.isSafe());

  // load the state-03
  // state 03 is safe, so check it
  s.loadState("simfiles/state-03.sim");
  CHECK(s.isSafe());

  // load the state-04
  // state 04 is unsafe, so check it
  s.loadState("simfiles/state-04.sim");
  CHECK(not s.isSafe());
}
