/*
 *  @file   Bed.h
 *  @author Matthew Springer
 *  @date   February 7, 2016
 */

#ifndef BED_H
#define BED_H

#include <string>

#include "Furniture.h"

/*
 *  Class Name:  Bed
 *
 *  INHERITED MEMBERS FROM FURNITURE:
 *  @param  width   the width of the furniture
 *  @param  height  the height of the furniture
 *  @param  depth   the depth of the furniture
 *  @param  name    the unique name of the furniture
 *
 *  PRIVATE MEMBERS:
 *  @param  bedSize the size of the bed ("Twin", "Full", "Queen", or "King")
 */
class Bed: public Furniture {
  
private:
  
  std::string bedSize;
  
public:
  
  // constructor
  Bed(std::string nm, std::string sz);
  
  // destructor
  ~Bed();
  
  /*
   *  Function: print
   *
   *  Purpose:  print information about the bed to stdout
   */
  void print();
};

#endif
