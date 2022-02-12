/** @file Matrix.cpp
 * @brief A Matrix class for page fault simulation.
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Summer 2020
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * A matrix class for our page fault simulation.  Implements a
 * standard Matrix access, but also some hooks so we can 
 * calculate and keep track of hit or missed page references 
 * in a simulated demand paging system.
 */
#include <iostream>
#include "Matrix.hpp"

using namespace std;



/** default constructor
 * The default constructor for the paging simulator.  We anticipate
 * handling matrix/processes A, B and C in the simulation and initialize
 * the page table map for each with an NO_PAGE value initially.
 */
DynamicPagingSimulator::DynamicPagingSimulator()
{
  // initialize the page table to be empty initially
  pageTable["A"] = NO_PAGE;
  pageTable["B"] = NO_PAGE;
  pageTable["C"] = NO_PAGE;

  // initialize variables to keep track of paging performance
  pageFaultCount = 0;
}


/** paging simulator destructor
 * When the simulation ends the the paging simulator goes out of scope, 
 * display final statistics and information about the paging behavior we just
 * witnessed.
 */
void DynamicPagingSimulator::displayResults()
{
  cout << "<DynamicPagingSimulator> paging simulation ends" << endl
       << "    Total number of page faults seen: " << pageFaultCount << endl;
}


/** reset simulation
 * Reset the simulation for another run.
 */
void DynamicPagingSimulator::resetSimulation()
{
  pageTable.clear();
  pageTable["A"] = NO_PAGE;
  pageTable["B"] = NO_PAGE;
  pageTable["C"] = NO_PAGE;

  pageFaultCount = 0;
}


/** check for page fault
 * Check if a page fault has occurred for the indicated page number
 * memory reference.
 *
 * @param matrixName The name of the matrix/process making the page number reference.
 * @param pageNumber The page number being referenced.
 *
 * @returns bool True if a page fault needs to occure (the page number referenced
 *   is not loaded), or false if there is no page fault.
 */
bool DynamicPagingSimulator::pageFault(string matrixName, int pageNumber)
{
  return pageTable[matrixName] != pageNumber;
}


/** check memory referece
 * For the DynamicPagingSimulator class, called before all memory 
 * references occur so that we can simulate maintining a page table,
 * and dynamically loading needed pages before they are referenced when
 * needed.
 *
 * @param matrixName The name of the matrix (process) requesting a
 *   memory reference.
 * @param row, col The row and column being requested.  Think of this as 
 *   the virtual address space of the matrix/process.  We translate this 
 *   to a virtual page and offset for this simulation.
 */
void DynamicPagingSimulator::checkMemoryReference(string matrixName, int row, int col)
{
  //cout << "<DynamicPagingSimulator::checkMemoryReference> entered" << endl
  //     << "    matrixName: " << matrixName << endl
  //     << "    row: " << row << endl
  //     << "    col: " << col << endl;
  int pageNumber = translateReferenceToPage(row, col);

  // check if a page fault has occurred
  if (pageFault(matrixName, pageNumber))
  {
    cout << "Page Fault occurred for Matrix " << matrixName
	 << " reference to row: " << row << " col: " << col << endl;
    cout << "     old page: " << pageTable[matrixName] << endl;

    // perform the page replacement
    pageTable[matrixName] = pageNumber;
    cout << "     new page: " << pageTable[matrixName] << endl;

    // keep track of the count of page faults that occur
    pageFaultCount++;
  }
}


/** translate reference
 * Translate a virtual refernce (e.g. matrix row/column) to a corresponding
 * page number.  In this problem we are given the following information 
 * about pages mameory:
 *
 *   - A page is 1K in size, or 1024 bytes
 *   - Integers are 4 bytes long, this implies each page can 
 *     hold 1024 / 4 = 256 values
 *   - Each matrix in this simulation needs 64 x 64 = 4096 integer values
 *       This can also be seen as needing 64 x 64 x 4 = 16384 bytes
 *   - Whether you think of an array as needing 4096 values or 16384 
 *       bytes, this means that each matrix requires 
 *       4096 / 256 = 16384 / 1024 = 16 virtual pages of memory
 *   
 * So each matrix has a virtual address space with 16 pages that we will
 * number 0 to 15.  e.g. A has pages 0 to 15, so does B.
 * 
 * Next we have to define a translation or mapping of a row,col reference to 
 * a page number.  As implied in the question, the first 4 rows of a matrix,
 * for example A[0,0] to A[3,63] should map to page 0. To calculate 
 * the virtual page number and offset we do the following.  
 * 
 *     - Offset from start of virtual address space is 
 *       row * 64 + col.  e.g. each row has 64 values, and if memory is layed
 *       out contiguously by row, the first 64 values start from 0 to 63, then 
 *       row 1 starts at offset 64, etc.
 *     - Given the absolute offset, the page number is simply 
 *       offset // 256 (integer division), e.g. the first 256 integers are on page 0, etc.
 *     - The offset within the page (not needed for this simulation) is then
 *       original_offset - (page * 256)
 *
 * This function takes the row/column virtual reference and returns the 
 * virtual page number being referenced.
 *
 * @param row,col The row and column to be translated into the virtual address space
 *   reference
 * 
 * @returns int Returns the virtual page number the reference falls on.
 */
int DynamicPagingSimulator::translateReferenceToPage(int row, int col)
{
  // each row has 64 or MATRIX_SIZE values, so absolute offset goes that number
  // of values from 0 plus the number of values to reach the indicated column.
  int absoluteOffset = row * MATRIX_SIZE + col;

  // now determine the page number indicated by this absolute offset
  // integer division by default, whill be the whole number of offsets
  // we need to go, dropping any remainder
  int pageNumber = absoluteOffset / PAGE_SIZE_VALUES;

  return pageNumber;
}



// need to initialize static member variables external to declaration
// in class header
int Matrix::nextMatrixId = 0;
DynamicPagingSimulator* Matrix::pager = new DynamicPagingSimulator();

/** normal constructor
 * Normal constructor for the class.  Memory is allocated STATICALLY
 * for this class.  So We enforce everyone always creates matrices
 * with 64 rows and 64 columns for this simulation.
 *
 * @param numRows The number of rows in the 2D matrix, must be 64
 *   for this simulation.
 * @param numCols The number of columns in this 2D matrix, must be
 *   64 for this simulation.
 */
Matrix::Matrix(int numRows, int numCols)
{
  // enforce always 64 rows and columns for this simulation
  if ( (numRows != MATRIX_SIZE) or (numCols != MATRIX_SIZE) )
  {
    cerr << "Error: Matrix::Matrix() constructor must be constructed" << endl
	 << "   with 64 rows and 64 columns for this simulation" << endl;
    exit(1);
  }

  // otherwise ok to dynamically allocate memory and initialize
  this->numRows = numRows;
  this->numCols = numCols;

  int value = 1;
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      values[row][col] = value++;
    }
  }

  // assign the next matrix id to this new matrix
  matrixId = nextMatrixId;
  nextMatrixId++;

  // generate a name, first matrix gets named A, etc.
  char nameChar = char('A' + matrixId);
  matrixName = string(1, nameChar);
}


/** get index reference
 * Retrieve value at indicated row and column index of this matrix.
 * This is the basis of something like an oveloaded operator[][]
 * member function for this 2-D matrix.
 * We actually return a reference back to the caller.  So the caller
 * can use the value (a read) or can actuall assign into the value
 * (a write) using the returned memory reference.
 *
 * @param row The row index of the 2-D matrix to access
 * @param col The column index of the 2-D matrix to access
 *
 * @returns int& Retuns a reference to the integer memory in this matrix
 *   at matrix[row][col].
 */
int& Matrix::getIndex(int row, int col)
{
  // we could do some bounds checking here to make sure the
  // reference is legal and in the bounds of our matrix, but
  // not really needed in this small simulation

  // call the pager as if the next reference is going through the cpu
  // and it will determine if the reference is in memory or needs to be
  // paged in
  pager->checkMemoryReference(matrixName, row, col);
  
  // simply access the row and column of our private values
  // integer matrix.  The reference to this value is returned
  // from this function.
  return values[row][col];
}


/** end simulation
 * Called on one of the matrixes to end the current simulation and 
 * clean up.
 */
void Matrix::endSimulation()
{
  nextMatrixId = 0;
  pager->displayResults();
  pager->resetSimulation();
}
