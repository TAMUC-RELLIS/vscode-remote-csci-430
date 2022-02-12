/** @file ClockPageReplacementScheme.hpp
 * @brief ClockPageReplacementScheme class implementation file
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our ClockPageReplacementScheme class.  This concrete
 * child class implements a clock page replacement scheme for the
 * PagingSystem simulator
 */
#include "ClockPageReplacementScheme.hpp"
#include <iomanip>
#include <sstream>
#include <string>

/**
 * @brief constructor
 *
 * The basic constructor is called by the PagingSystem when setting up/creating
 * the paging scheme to use for a simulation.  We keep track of the paging system
 * instance we are associated with, so we can call the paging system to get
 * needed information to make replacment decisions.
 *
 * @param sys The associated PagingSystem system instance that this scheme
 *   is associated with.
 */
ClockPageReplacementScheme::ClockPageReplacementScheme(PagingSystem* sys)
  : PageReplacementScheme(sys)
{
  // make sure we reset the fifo scheme to an initial state when first
  // creating the instnace
  resetScheme();
}

/**
 * @brief destructor
 *
 * Clean up any dynamically allocated memory when we exit scope.
 */
ClockPageReplacementScheme::~ClockPageReplacementScheme()
{
  // not described in assignment, but if you dynamically allocate
  // memory, you should delete/deallocate it in the destructor here
}

/**
 * @brief reset scheme
 *
 * Reset this paging scheme to beginning/initial state
 */
void ClockPageReplacementScheme::resetScheme()
{
  // clock unit test task 2, initialze the member variables
  // to the values you need to perform the clock algorithm.
  // You should dynamically allocate an array of some type
  // to represent the use bit for each frame.  You should
  // initialize your use bits here as well.  Since clock
  // replacement begins after memory is full, you probably need
  // to initialize all use bits to 1, in anticipation of the
  // initial load of each page into the empty frame.
  // Also, there is a member variable named sys that is
  // a pointer to the PagingSystem instance that this scheme
  // is working with.  You can use this variable to access
  // information about the paging system simulation, for example
  // you might need to know the number of physical frames in the
  // simulation, so you can do sys->getMemorySize() to determine
  // this information.
}

/**
 * @brief record page hit
 *
 * For the clock replacement scheme, the use bit should be set
 * anytime a page is loaded, or a page hit occurs.  We set
 * use bit 1 here whenever a page hit refere is made.
 *
 * @param frame The frame number of the frame that was just
 *   hit by a page reference.  Set the related use bit to 0
 *   for this frame.
 */
void ClockPageReplacementScheme::pageHit(FrameNumber frame)
{
  // clock unit test task 3.  This method is called whenever
  // a page hit occurs in the paging system.  For the clock
  // algorithm, we need to set the use bit to 1 for the frame/page
  // that was just hit.
}

/**
 * @brief get scheme status
 *
 * This function returns a string with a representation of the current
 * status of this page replacement scheme.  This is used as a hook
 * by the simulator so we can see inside of a page replacement scheme
 * and get a sense of its internal state and decision making process.
 * For clock, we display the memory contents and indicate where the frame
 * pointer is currently pointing, and we give an indicate of the current
 * use bit setting.
 *
 * @returns string Returns a string representation of the current status
 *   of the clock page replacement algorithm.
 */
string ClockPageReplacementScheme::getSchemeStatus()
{
  // clock unit test task 5, implement this method so that full
  // system tests will display the status of the clock page
  // replacement algoritm.  Start by copying the implementation
  // of the FifoPageReplacementScheme.getSchemeStatus() method
  // here, then add in the information about the use bit for each
  // frame to the output string that is returned.
  return "";
}

/**
 * @brief make replacement decision
 *
 * This method is called by the paging simulator whenever a
 * page replacement decision is needed.  The fifo scheme
 * keeps track of the next frame in memory using a simple
 * frame pointer, and replaces the next page in fifo
 * (round robin) fashion.  The memory frames are treated as
 * a circular buffer, so if we wrap around the end of memory,
 * we need to circle back to frame 0.
 *
 * @returns FrameNumber the frame number selected to
 *   be replaced by the fifo scheme.
 */
FrameNumber ClockPageReplacementScheme::makeReplacementDecision()
{
  // clock unit test 4,  You need to have a frame pointer and
  // a use bit for each frame.  The clock algorithm starts by
  // scanning at the current frame pointed to by the frame pointer.
  // If the frame use bit is 1, it is flipped to 0 and you advance
  // to the next frame. (When advancing frames, make sure you wrap
  // back around to frame 0 when you get to the end of memory).
  // You should stop when you find a use bit of 0 and select that
  // frame for replacement.

  // After you determine which frame to replace, don't forget to
  // do two other tasks.  The use bit for the frame that will be
  // replaced should be set to 1 in anticipation of loading a
  // new page to the frame.  Also the frame pointer needs to point
  // to the frame after the one that will be replaced, so that
  // you correctly start scanning at the next frame the next
  // time a replacement decision needs to be made.

  // return the frame selected for replacement
  return 0;
}