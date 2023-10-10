/* W. H. Bell
** A random number generator
*/

#ifndef LORENTZBOOST_H
#define LORENTZBOOST_H

#include "HepMC/SimpleVector.h"

class LorentzBoost {
public:

  /** A member function to lorentz boost a particle by a supplied boost 
  ** vector */
  static HepMC::FourVector lorentzBoost(HepMC::FourVector boost,
                                        HepMC::FourVector initial);
};

#endif
