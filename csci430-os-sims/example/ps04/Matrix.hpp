/** @file Matrix.hpp
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
#include <map>
#include <string>

using namespace std;



/// global constants for the DynamicPagingSimulator class
const int NO_PAGE = -1; // indicate no page loaded for indicated process/matrix
const int PAGE_SIZE_BYTES = 1024; // pages are 1K in size
const int PAGE_SIZE_VALUES = PAGE_SIZE_BYTES / 4; // there are 256 int values on a page

/** Dynamic Paging simulator
 * Simulate dynamic paging.  Each matrix is given a "name"
 * and its own set of pages. In this simple simulation 
 * the matrix calls us for every page reference, and we
 * calculate which page needs to be reference, and generate
 * a page fualt if needed.  For simplicity we only keep the 
 * 3 pages needed for the 3 expected matrices A, B and C
 */
class DynamicPagingSimulator
{
private:
  /// the paging simulator uses a map for the page table.
  /// Each matrix/process A,B,C has a single page loaded, which
  /// is kept track of in this map.  The map maps the
  /// matrix/process name to the page number currently in
  /// memory
  map<string, int> pageTable;
  int pageFaultCount;
  
public:
  DynamicPagingSimulator();
  void displayResults();
  void resetSimulation();
  void checkMemoryReference(string matrixName, int row, int col);
  bool pageFault(string matrixName, int pageNumber);
  int translateReferenceToPage(int row, int col);
  
};


// we statically allocate 2D matrix of this size to use,
const int MATRIX_SIZE = 64;

/** Matrix Class
 * A simple class to encapsulate a matrix.  We also put in hooks for
 * our simulation so we can calculate and detect and implement
 * paging and page faults for the simulation.
 */
class Matrix
{
private:
  /// A private actual array of 2-D values
  int numRows;
  int numCols;
  int values[MATRIX_SIZE][MATRIX_SIZE];

  /// The "name" we are known by by the paging system
  static int nextMatrixId;
  int matrixId;
  string matrixName;
  
  // All matrix clases will have a reference to the same
  // paging simulator for this simulation
  static DynamicPagingSimulator* pager;
  

public:
  // constructors and destructors
  Matrix(int numRows, int numCols);
  
  // we could get fancy and overload operator[], but overloading 2-D or higher
  // indexing operation is tricky, so we'll keep it a bit simpler and define
  // a member function<
  int& getIndex(int row, int col);

  void endSimulation();
public:
};

