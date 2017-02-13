/*
 *  @file   Furniture.h
 *  @author Matthew Springer
 *  @date   February 7, 2016
 */

#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>

/*
 *  Class Name:  Furniture
 *
 *  PRIVATE MEMBERS:
 *  @param  width   the width of the furniture
 *  @param  height  the height of the furniture
 *  @param  depth   the depth of the furniture
 *  @param  name    the unique name of the furniture
 */
class Furniture {
  
private:
  
  float width;
  float height;
  float depth;
  std::string name;
  
public:
  
  // constructor
  Furniture(std::string nm);
  
  // destructor
  ~Furniture();
  
  /*
   *  Function: readDimensions
   *
   *  Purpose:  initialize width, height, and depth from user input
   */
  void readDimensions();
  
  /*
   *  Function: print
   *
   *  Purpose:  print information about the furniture to stdout
   */
  virtual void print();
};

#endif
