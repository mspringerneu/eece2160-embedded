#ifndef BED_H
#define BED_H

#include "Bed.h"

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
  
  string bedSize;
  
public:
  
  // constructor
  Bed(string name, string sz) : Furniture(name) {
    switch (sz) {
      case "Twin":
        bedSize = sz;
        break;
      case "Full":
        bedSize = sz;
        break;
      case "Queen":
        bedSize = sz;
        break;
      case "King":
        bedSize = sz;
        break;
      default:
        cout << "Bed size must be one of: 'Twin', 'Full', 'Queen', or 'King'"
        << endl;
    }
    read
  }
  
  // destructor
  ~Bed();
  
  /*
   *  Function: print
   *
   *  Purpose:  print information about the bed to stdout
   */
  void Print();
};

#endif
