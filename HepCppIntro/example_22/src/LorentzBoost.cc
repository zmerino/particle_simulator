/* W. H. Bell
** A wrapper class for fortran lorentz boost function.
*/

#include "LorentzBoost.h"
#include <iostream>

extern "C" {
  void extern lorentz_(float [], float [], float []); // Fortran function
}

HepMC::FourVector LorentzBoost::lorentzBoost(HepMC::FourVector boost,
					     HepMC::FourVector initial) {
  float pb[] = {boost.px(), boost.py(), boost.pz(), boost.e()};
  float pi[] = {initial.px(), initial.py(), initial.pz(), initial.e()};
  float pf[] = {0., 0., 0., 0.};

  std::cout << "pb=";
  for(int i=0;i<4;i++) std::cout << pb[i] << " ";
  std::cout << std::endl;
  std::cout << "pi=";
  for(int i=0;i<4;i++) std::cout << pi[i] << " ";
  std::cout << std::endl;

  lorentz_(pb, pi, pf);

  std::cout << "pf=";
  for(int i=0;i<4;i++) std::cout << pf[i] << " ";
  std::cout << std::endl;

  return HepMC::FourVector(pf[0],pf[1],pf[2],pf[3]);
}
