#ifndef PYTHIAGEN_H
#define PYTHIAGEN_H

// Forward declarations to reduce precompile time.
namespace HepMC {
  class GenEvent;
  class IO_HEPEVT;
}

class PythiaGen {
 public:

  /** The default constructor to setup the HepMC IO ready for a HEPEVT 
  ** record to be read. */
  PythiaGen();

  /** Destructor to delete the dynamically allocated HepMC IO class and 
  ** print out the PYTHIA event generation summary. */
  ~PythiaGen();

  /** A member function to initialise PYTHIA to produce inelastic 
  ** non-diffractive p-p interactions at 10TeV. */
  int initialise(void);

  /** Generate one PYTHIA event and copy the result into the 
  ** returned GenEvent. */
  HepMC::GenEvent* generate(void);

 private:
  /** A data member to store a pointer to the HepMC IO object. */
  HepMC::IO_HEPEVT *m_hepevtio;
};

#endif
