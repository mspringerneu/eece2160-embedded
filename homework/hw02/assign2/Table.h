#ifndef TABLE_H
#define TABLE_H

#include <string>

#include "Furniture.h"

/*
 *  Class Name:  Table
 *
 *  INHERITED MEMBERS FROM FURNITURE:
 *  @param  width   the width of the furniture
 *  @param  height  the height of the furniture
 *  @param  depth   the depth of the furniture
 *  @param  name    the unique name of the furniture
 *
 *  PRIVATE MEMBERS:
 *  @param  bedSize the type of wood ("Pine" or "Oak")
 */
class Table: public Furniture {
  
private:
  
  std::string wood;
  
public:
  
  // constructor
  Table(std::string nm, std::string wd);
  
  // destructor
  ~Table();
  
  /*
   *  Function: print
   *
   *  Purpose:  print information about the table to stdout
   */
  void print();
};

#endif
