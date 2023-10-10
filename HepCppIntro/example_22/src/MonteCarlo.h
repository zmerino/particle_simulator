/* W. H. Bell
** A class providing a pi0 generator and two body decays
*/

#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "HepMC/GenParticle.h"

// Forward declaration to save precompiler time.
namespace HepMC {
  class GenEvent;
}

class MonteCarlo {
public:
  /** A function to generate pi0 particles with a given pt 
  ** distribution. */
  static HepMC::GenParticle generate(void);

  /** A member function to perform a two body decay */
  static void twoBody(HepMC::GenEvent *evt,
		      HepMC::GenParticle *parent, 
		      HepMC::GenParticle *daughter1, 
		      HepMC::GenParticle *daughter2,
		      int particleId1,
		      int particleId2,
		      double daughterMass1,
		      double daughterMass2);

  /** A member function to perform a two body decay */
  static void twoBody(HepMC::GenEvent *evt,
		      HepMC::GenParticle *parent, 
		      int particleId1,
		      int particleId2,
		      double daughterMass1,
		      double daughterMass2);
};

#endif
