/*
** W. H. Bell
**
** A program to perform translations in 2D.
*/

#include <iostream>
#include <cstring>

#include "ITranslation.h"
#include "OffsetTranslation.h"
#include "RotationTranslation.h"

void usage(char *);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv[0]);
    return 1;
  }

  ITranslation *translation;
  if(!strcmp(argv[1],"-o")) {
    double offset[2] = {5., 3.};
    translation = new OffsetTranslation(offset);
  }
  else if(!strcmp(argv[1],"-r")) {
    translation = new RotationTranslation(0.785); // Pi/4 about pivot
  }
  else {
    usage(argv[0]);
    return 1;
  }

  double spacePoint[2] = {1., 1.};

  translation->translate(spacePoint);
  std::cout << "After translation: spacePoint = {" << spacePoint[0] << ", "
	    <<  spacePoint[1] << "}" << std::endl;
  
  translation->reverse(spacePoint);
  std::cout << "Before translation: spacePoint = {" << spacePoint[0] << ", "
	    <<  spacePoint[1] << "}" << std::endl;

  delete translation;
}


void usage(char *exename) {
  std::cout << " Usage: " << exename << " <-r/-o>" << std::endl;
  std::cout << " where -r selects a rotation and -o an offset" << std
::endl;
}
