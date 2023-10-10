/*
** W. H. Bell
** 
** An example to demonstrate storage and retrieval of simple variables
** from a root tree.
*/


#include <iostream>
#include <list>
#include <string>

#include "Tree_McTruth.h"

int main(int argc, char *argv[]) {
  int i;

  std::list<std::string> files;
  std::string defaultFile = "../../TruthNtuple/src/pythia.root";
  files.push_back(defaultFile);
  Tree_McTruth tree_McTruth(files,"mctree");
  
  if(tree_McTruth.initialize()) {
    std::cerr << "Tree_McTruth initialize() failed" << std::endl;
    return 1;
  }

  // Loop over all events
  i=0;
  while(tree_McTruth.getEntry()==0) {

    // Print out the 7th event to take a look at it.
    if(i==6) {
      tree_McTruth.print();
    }

    if(i%500 == 0 && i != 0) {
      std::cout << "  >> Processed " << i << " events." << std::endl;
    }
    i++;
  }

  return 0;
}
