/*
** W. H. Bell
** 
** An example to demonstrate storage and retrieval of simple variables
** from a root tree.
*/

#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
#include "TRandom.h"
#include <iostream>

void usage(char *);
void writeTree(char *);
void readTree(char *);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv[0]);
    return 1;
  }

  if(!strcmp(argv[1],"-w")) {
    writeTree("tree.root");
  }
  else if (!strcmp(argv[1],"-r")) {
    readTree("tree.root");
  }
  else {
    usage(argv[0]);
    return 1;
  }
}

void writeTree(char *filename) {
  Float_t x, y, z;
  Int_t run, event;
  
  // Open a root file
  TFile *root_file = TFile::Open(filename,"RECREATE");
  if(!root_file) {
    std::cerr << "Error: could not open root file " << filename << std::endl;
  }
  else {
    // Create a new tree
    TTree *tree = new TTree("tree","test tree");
    
    // Add five branches to the tree
    tree->Branch("Run",&run,"Run/I");
    tree->Branch("Event",&event,"Event/I");
    tree->Branch("x",&x,"x/F");
    tree->Branch("y",&y,"y/F");
    tree->Branch("z",&z,"z/F");
    
    TRandom r;
    for (Int_t i=0;i<10000;i++) {
      if (i < 5000) {
	run = 1;
      }
      else {
	run = 2;
      }
      event = i;
      x = r.Gaus(10,1);
      y = r.Gaus(20,2);
      z = r.Landau(2,1);
      tree->Fill();
    }
    
    tree->Print();
    root_file->Write();
    delete root_file;
  }
}

void readTree(char *filename) {
  // Open a root file
  TFile *root_file = TFile::Open(filename,"READ");
  if(!root_file) {
    std::cerr << "Error: could not open root file " << filename << std::endl;
  }
  else {
    // Use the tree name to collect the correct TObject from the root
    // file.
    TTree *tree = (TTree*)root_file->Get("tree");

    // Print the number of entries
    Int_t entries = tree->GetEntries();
    std::cout << "This tree contains " << entries << " entries" 
	      << std::endl;

    // Collect a pointer to each of the branches
    TBranch *run_branch = tree->GetBranch("Run");
    TBranch *event_branch = tree->GetBranch("Event");
    TBranch *x_branch = tree->GetBranch("x");
    TBranch *y_branch = tree->GetBranch("y");
    TBranch *z_branch = tree->GetBranch("z");
    if(!run_branch) {
      std::cerr << "Error: the Run branch does not exist" << std::endl;
    }
    else if (!event_branch) {
      std::cerr << "Error: the Event branch does not exist" << std::endl;
    }
    else if (!x_branch) {
      std::cerr << "Error: the x branch does not exist" << std::endl;
    }
    else if (!y_branch) {
      std::cerr << "Error: the y branch does not exist" << std::endl;
    }
    else if (!z_branch) {
      std::cerr << "Error: the z branch does not exist" << std::endl;
    }
    else {
      Float_t x, y, z;
      Int_t run, event;
      
      // Set the branch addresses ready for the entries to be read.
      run_branch->SetAddress(&run);
      event_branch->SetAddress(&event);
      x_branch->SetAddress(&x);
      y_branch->SetAddress(&y);
      z_branch->SetAddress(&z);
      
      // Print the first 10 events from the tree
      std::cout << "Printing the first 10 events from this tree." << std::endl;
      std::cout << "| event  | run  | x | y | z |" << std::endl;
      for (Int_t i=0;i<10;i++) {
	tree->GetEvent(i); 
	std::cout << event << " " << run << " " 
		  << x << " " << y << " " << z << std::endl;
      }
    }      

    delete root_file;
  }
}

void usage(char *exename) {
  std::cout << " Usage: " << exename << " <-w/-r>" << std::endl;
  std::cout << " where -w => write root file and -r => read root file" << std::endl;
}
