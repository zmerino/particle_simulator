#include "BmesonGenerator.h"
#include "pythia/pythia.h"
#include "hepevt.h"

void BmesonGenerator::initialise() {
  double ecm = 14000.0; // Centre of mass energy = 14TeV
 
  // Select b, bbar production via hard scatter only.
  pysubs_.msel=5;

  // Initialise pythia for a p p collision at 14TeV.
  pyinit_("CMS","p","p",&ecm,3,1,1);
}

void BmesonGenerator::generate() {
  int b_mesons=0;
  int mconv=1;
  
  // Generate an event containing at least one B0 or B+ or Bs meson
  while(b_mesons==0) {
    
    // Generate an event
    pyevnt_();
    
    // Copy data into HEPEVT common block
    pyhepc_(&mconv);
    
    // Search for B0, B0bar, B+/-, Bs Bsbar mesons
    int particle_id, j = 0;
    while(b_mesons==0 && j<hepevt_.nhep) {
      particle_id = hepevt_.idhep[j];
      if(particle_id<0) particle_id = -particle_id;
      if(particle_id == 511 || particle_id == 521 || particle_id == 531) {
        b_mesons++;
      }
      j++;
    }
  }
}

