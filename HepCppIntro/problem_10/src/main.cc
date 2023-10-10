#include "BmesonGenerator.h"
#include "HepevtTree.h"
#include "pythia/pythia.h"

#include <iostream>

int main(void) {
  int i,ret_val;

  std::string outputFile = "bmesons.root";
  int nevents = 1000;

  HepevtTree hepevtTree(outputFile);
  if((ret_val = hepevtTree.open()) != 0 ) return ret_val;
  if((ret_val = hepevtTree.book()) != 0 ) return ret_val;

  // Initialise the pythia generator
  BmesonGenerator::initialise();

  while(i<nevents) {
    // Generate an event with 1 or more b mesons.
    BmesonGenerator::generate();
    
    // Save the HEPEVT common block in a TTree
    if((ret_val = hepevtTree.fill()) != 0 ) return ret_val;
    
    i++;
  }
  
  if((ret_val = hepevtTree.save()) != 0 ) return ret_val;

  std::cout << "\t Saved " << i << " from PYTHIA" << std::endl;

  // Print out PYTHIA stats.
  i=1;
  pystat_(&i);
  
  return 0;
}
