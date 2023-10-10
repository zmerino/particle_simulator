/* W. H. Bell
** An example program using the HepMC package to generate 
** 
** pi^0 -> gamma, gamma 
**
** decays.
*/

#include <iostream>
#include <cmath>
#include "HepMC/GenEvent.h"
#include "HepMC/GenVertex.h"
#include "HepMC/GenParticle.h"
#include "HepMC/SimpleVector.h"
#include "MonteCarlo.h"

int main() {
  // Create the event container
  HepMC::GenEvent *evt = new HepMC::GenEvent(20, 1);

  // Generate a pi0
  HepMC::GenParticle pi0 = MonteCarlo::generate();
  
  // Produce (pi0 -> gamma gamma) decay.
  MonteCarlo::twoBody(evt,&pi0,22,22,0.,0.);

  evt->print();

  return 0;
}
