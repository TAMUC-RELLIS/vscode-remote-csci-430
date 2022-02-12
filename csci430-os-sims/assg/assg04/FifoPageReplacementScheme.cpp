/** @file FifoPageReplacementScheme.hpp
 * @brief FifoPageReplacementScheme class implementation file
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our FifoPageReplacementScheme class.  This concrete
 * child class implements a fifo page replacement scheme for the
 * PagingSystem simulator
 */
#include "FifoPageReplacementScheme.hpp"
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
FifoPageReplacementScheme::FifoPageReplacementScheme(PagingSystem* sys)
  : PageReplacementScheme(sys)
{
  // make sure we reset the fifo scheme to an initial state when first
  // creating the instnac
  resetScheme();
}

/**
 * @brief reset scheme
 *
 * Reset this paging scheme to beginning/initial state
 */
void FifoPageReplacementScheme::resetScheme()
{
  this->framePointer = 0;
}

/**
 * @brief record page hit
 *
 * For the fifo replacement scheme, page hits do not effect
 * our placement decisions, so we ignore page hits.
 *
 * @param frame The frame number that received a hit.
 */
void FifoPageReplacementScheme::pageHit(FrameNumber frame)
{
  // nothing to do for fifo on a page hit
}

/**
 * @brief get scheme status
 *
 * This function returns a string with a representation of the current
 * status of this page replacement scheme.  This is used as a hook
 * by the simulator so we can see inside of a page replacement scheme
 * and get a sense of its internal state and decision making process.
 * For fifo, we display the memory contents and indicate where the frame
 * pointer is currently pointing.
 *
 * @returns string Returns a string representation of the current status
 *   of the fifo page replacement algorithm.
 */
string FifoPageReplacementScheme::getSchemeStatus()
{
  stringstream out;

  // iterate through all memory frames, displaying their content
  for (int frame = 0; frame < sys->getMemorySize(); frame++)
  {
    out << "frame[" << setfill('0') << setw(3) << frame << "] ";

    // if frame is actually currently empty, give more human readable
    // description of the content
    int pageNumber = sys->peekMemory(frame);
    if (pageNumber == 0)
    {
      out << setfill(' ') << setw(5) << "EMPTY";
    }
    // otherwise just show the page number loaded in this frame
    else
    {
      out << setfill(' ') << setw(5) << pageNumber;
    }

    // indicate current location of frame pointer
    if (frame == framePointer)
    {
      out << " <-- framePointer";
    }
    out << endl;
  }

  // return the resulting string
  return out.str();
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
FrameNumber FifoPageReplacementScheme::makeReplacementDecision()
{
  // keep track of the actual frame we want to have replaced
  FrameNumber frameToReplace = framePointer;

  // update frame pointer for our next replacement decision
  framePointer = (framePointer + 1) % sys->getMemorySize();

  // return the frame selected for replacement
  return frameToReplace;
}