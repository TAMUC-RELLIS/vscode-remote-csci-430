/** @file PageReplacementScheme.hpp
 * @brief PageReplacementScheme class implementation file
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation file for our PageReplacementScheme class.  The PageReplacementScheme
 * class is an abstract base class that defines the interface
 * for implementing different page replacement schemes.
 * Basically any page replacement scheme needs to be able to
 * select a physical frame of memory to be replaced, using whatever
 * algorithm the scheme implements.  This abstract interface
 * defines the api calls supported so that the PagingSystem
 * simulator can use any particular PageReplacementScheme.
 */
#include "PageReplacementScheme.hpp"

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
PageReplacementScheme::PageReplacementScheme(PagingSystem* sys)
{
  this->sys = sys;
}

/**
 * @brief destructor
 *
 * Define a concrete destructor.  This destructor has no work to do, but
 * base classes that need a destructor should define their own.
 */
PageReplacementScheme::~PageReplacementScheme() {}