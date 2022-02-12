/** @file ps04-pagefaults.cpp
 * @brief Problem Set 04 Problem #3
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Simulation of the page faulting problem given for problem set 
 * 04, question #3.
 */
#include <iostream>
#include <iomanip>
#include "Matrix.hpp"

using namespace std;


/// In the problem size is defined as a global constant, we use
/// global const int as a more C++ey way to express the same thing
const int SIZE = 64;


/**
 * @brief buggy implementation
 * 
 * This is the version of the code given initially in the problem 
 * set question.  It is buggy in the sense that it performs many
 * unneded page faults, slowing down the execution substantially.
 */
void buggyMatrixOperations()
{
  cout << "Starting buggyMatrixOperations() -----------------------------------"
       << endl;

  // Create the matrices A, B and C for use.
  Matrix A(SIZE, SIZE);
  Matrix B(SIZE, SIZE);
  Matrix C(SIZE, SIZE);

  // Test the matrix
  //B.getIndex(5, 5) = 25;
  //cout << "B[5][5] = " << B.getIndex(5, 5) << endl;

  int register i, j; // loop index variables

  // outer loop over the columns
  for (j = 0; j < SIZE; j++)
  {
    // inner loop over the rows
    for (i = 0; i < SIZE; i++)
    {
      C.getIndex(i, j) = A.getIndex(i, j) + B.getIndex(i, j);
    }
  }


  // clean up the simulation for this example
  A.endSimulation();
  cout << endl << endl;
}


/**
 * @brief fixed implementation
 * 
 * This version fixes paging problems, processes matrices to 
 * maximize use of loaded pages.
 */
void fixedMatrixOperations()
{
  cout << "Starting fixedMatrixOperations() -----------------------------------"
       << endl;

  // Create the matrices A, B and C for use.
  Matrix A(SIZE, SIZE);
  Matrix B(SIZE, SIZE);
  Matrix C(SIZE, SIZE);

  // Test the matrix
  //B.getIndex(5, 5) = 25;
  //cout << "B[5][5] = " << B.getIndex(5, 5) << endl;

  int register i, j; // loop index variables

  // outer loop over the rows
  for (i = 0; i < SIZE; i++)
  {
    // inner loop over the cols
    for (j = 0; j < SIZE; j++)
    {
      C.getIndex(i, j) = A.getIndex(i, j) + B.getIndex(i, j);
    }
  }


  // clean up the simulation for this example
  A.endSimulation();
  cout << endl << endl;
}


/**
 * @brief main entry
 *
 * Main entry point of process when run.  Code execution starts here.
 * Whenever a process is created, it is initially created with a single
 * thread.  The main() function starting point is the code that
 * will initially be executing in the initial thread.
 *
 * @param argc The count of the number of arguments on the command line.
 * @param argv[] An array of char* strings, the command line arguments
 *   provided by the user when this program is run.
 *
 * @returns int Returns a status/exit code.  0 means normal termination.
 */
int main(int argc, char* argv[])
{
  // call the buggy version
  buggyMatrixOperations();
  
  // call the buggy version
  fixedMatrixOperations();
  
  // return 0 to indicate successful completion
  return 0;
}
