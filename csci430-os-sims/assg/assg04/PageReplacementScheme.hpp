/** @file PageReplacementScheme.hpp
 * @brief PageReplacementScheme class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our PageReplacementScheme class.  The
 * PageReplacementScheme class is an abstract base class that defines
 * the interface for implementing different page replacement schemes.
 * Basically any page replacement scheme needs to be able to select a
 * physical frame of memory to be replaced, using whatever algorithm
 * the scheme implements.  This abstract interface defines the api
 * calls supported so that the PagingSystem simulator can use any
 * particular PageReplacementScheme.
 */
#ifndef PAGE_REPLACEMENT_SCHEME_HPP
#define PAGE_REPLACEMENT_SCHEME_HPP

#include "PagingSystem.hpp"
#include <string>

// forward declaration needed for circular references
class PagingSystem;

/// @brief FrameNumber are the valid frame number references used for
///   for this simulation.  Valid FrameNumber range from 0 to N.
///   Negative frame numbers are invalid, and may be used as error flags.
typedef int FrameNumber;

using namespace std;

/** @class PageReplacementScheme
 * @brief PageReplacementScheme abstract base class
 *
 * This class defines the interface or API for the helper page
 * replacement scheme.  A PagingSystem simulation will instanciate
 * a derived class of this API, and will expect it to implement the
 * interface defined by this abstract base class.
 */
class PageReplacementScheme
{
protected: // derived classes need to be able to access the sys member instance
  /// @brief The paging system that this paging scheme is
  ///   supporting
  PagingSystem* sys;

public:
  PageReplacementScheme(PagingSystem* sys);

  // virtual function, concrete subclasses can override if needed
  virtual ~PageReplacementScheme();

  // pure virtual functions, concrete subclasses must implement
  virtual void resetScheme() = 0;
  virtual void pageHit(FrameNumber frame) = 0;
  virtual string getSchemeStatus() = 0;
  virtual FrameNumber makeReplacementDecision() = 0;
};

#endif // PAGE_REPLACEMENT_SCHEME_HPP