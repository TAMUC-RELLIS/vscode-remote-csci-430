/** @file ClockPageReplacementScheme.hpp
 * @brief ClockPageReplacementScheme class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our ClockPageReplacementScheme class.
 * This concrete child class implements a clock page replacement
 * scheme for the PagingSystem simulator.
 */
#ifndef CLOCK_PAGE_REPLACEMENT_SCHEME_HPP
#define CLOCK_PAGE_REPLACEMENT_SCHEME_HPP

#include "PageReplacementScheme.hpp"

using namespace std;

/** @class ClockPageReplacementScheme
 * @brief ClockPageReplacementScheme abstract base class
 *
 */
class ClockPageReplacementScheme : public PageReplacementScheme
{
private:
  /// @brief The current frame pointer.  When a page replacement
  ///   decision needs to be made for the clock scheme
  ///   we first check if the use bit is 0 or 1.  If it is 0,
  ///   we select that frame for replcement.  If it is 1, we instead
  ///   set the use bit to 0 and skip this frame and check the next
  ///   frame.
  int framePointer;

  /// @brief clock unit test task 1, you will need an array
  ///   of int or bool types to represent a use bit for each
  ///   frame of memory.  The actual array should be allocated
  ///   dynamically in the resetScheme() function as described.
  ///   But since this should be a dynamic allocation, you actually
  ///   need a pointer to an int or bool here so that you can
  ///   dynamically allocate a block of memory and assign the block
  ///   to the name you use for your use bits.

public:
  ClockPageReplacementScheme(PagingSystem* sys);
  ~ClockPageReplacementScheme();
  void resetScheme();
  void pageHit(FrameNumber frame);
  string getSchemeStatus();
  FrameNumber makeReplacementDecision();
};

#endif // CLOCK_PAGE_REPLACEMENT_SCHEME_HPP