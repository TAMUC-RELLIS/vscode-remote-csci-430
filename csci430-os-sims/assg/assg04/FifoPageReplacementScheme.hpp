/** @file FifoPageReplacementScheme.hpp
 * @brief FifoPageReplacementScheme class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our FifoPageReplacementScheme class.
 * This concrete child class implements a fifo page replacement
 * scheme for the PagingSystem simulator.
 */
#ifndef FIFO_PAGE_REPLACEMENT_SCHEME_HPP
#define FIFO_PAGE_REPLACEMENT_SCHEME_HPP

#include "PageReplacementScheme.hpp"

using namespace std;

/** @class FifoPageReplacementScheme
 * @brief FifoPageReplacementScheme abstract base class
 *
 */
class FifoPageReplacementScheme : public PageReplacementScheme
{
private:
  /// @brief The current frame pointer.  When a page replacement
  ///   decision needs to be made, the frame pointed to by the
  ///   frame pointer will be selected for replacement, and
  ///   it will be incremented to the next frame (using a circular
  ///   wrap around) for the next replacement decision.
  int framePointer;

public:
  FifoPageReplacementScheme(PagingSystem* sys);
  void resetScheme();
  void pageHit(FrameNumber frame);
  string getSchemeStatus();
  FrameNumber makeReplacementDecision();
};

#endif // FIFO_PAGE_REPLACEMENT_SCHEME_HPP