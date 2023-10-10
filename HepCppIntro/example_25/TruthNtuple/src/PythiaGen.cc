#include "PythiaGen.h"

#include "HepMC/GenEvent.h"
#include "HepMC/IO_HEPEVT.h"
#include "HepMC/HEPEVT_Wrapper.h"

#include "pythia/pythia.h"

PythiaGen::PythiaGen(void) {
  
  // Set the common block sizes to match this version of PYTHIA.
  HepMC::HEPEVT_Wrapper::set_max_number_entries(4000);
  HepMC::HEPEVT_Wrapper::set_sizeof_real(8);
  
  // Setup HEPEVT IO
  m_hepevtio = new HepMC::IO_HEPEVT();
}

//---------------------------------------------------------------------

PythiaGen::~PythiaGen() {
  // Print out PYTHIA stats.
  int mstat=1;
  pystat_(&mstat);

  if(m_hepevtio) delete m_hepevtio;
}

//---------------------------------------------------------------------

int PythiaGen::initialise(void) {
  double ecm;

  ecm=10000.0; // 10 TeV  
  pysubs_.msel=1; // Select inelastic non-diffractive

  // Initialise PYTHIA as p-p at the given beam energy 
  pyinit_("CMS","p","p",&ecm,3,1,1);
  
  return 0;
}

//---------------------------------------------------------------------

HepMC::GenEvent* PythiaGen::generate(void) {
  int i;

  pyevnt_(); // Generate a PYTHIA event.
  i=1;
  pyhepc_(&i); // Convert PYTHIA data to HEPEVT
  return m_hepevtio->read_next_event();
}

//---------------------------------------------------------------------
