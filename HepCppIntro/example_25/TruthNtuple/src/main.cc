/*
** W. H. Bell
** 
** An example to demonstrate storage and retrieval of simple variables
** from a root tree.
*/


#include <iostream>

#include "PythiaGen.h"
#include "TruthTree.h"
#include "HepMC/GenEvent.h"

int main(int argc, char *argv[]) {
  int ret_val, i;

  HepMC::GenEvent *genEvent;

  PythiaGen pythiaGen;
  TruthTree truthTree("pythia.root");
  
  if((ret_val=truthTree.open()) != 0) { 
    std::cerr << "Failed to open output TFile" << std::endl;
    return ret_val;
  }

  if((ret_val=truthTree.book()) != 0) {
    std::cerr << "Failed to book TTree" << std::endl;
    return ret_val;
  }

  if((ret_val=pythiaGen.initialise()) != 0) {
    std::cerr << "Failed to initialise PythiaGen" << std::endl;
    return ret_val;
  }
  
  for(i=0;i<5000;i++) {
    genEvent = pythiaGen.generate();
    if(!genEvent) {
      std::cerr << "GenEvent returned from PythiaGen is null!" << std::endl;
      return 1;
    }

    if((ret_val=truthTree.fill(genEvent)) != 0) return ret_val;
    delete genEvent;

    if(i%100 == 0 && i>0) {
      std::cout << "\t" << i << " events have been generated" << std::endl;
    }
  }
  
  std::cout << "Loop complete.  " << i << " events have been generated" << std::endl;

  if((ret_val=truthTree.save()) != 0) { 
    std::cerr << "Failed to save TFile" << std::endl;
    return ret_val;
  }

  return 0;
}
