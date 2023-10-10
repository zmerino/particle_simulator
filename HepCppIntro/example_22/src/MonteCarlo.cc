/* W. H. Bell
** A class containing useful Monte Carlo functions.
*/

#include <cmath>
#include "MonteCarlo.h"
#include "HepMC/GenEvent.h"
#include "HepMC/GenVertex.h"
#include "HepMC/SimpleVector.h"
#include "LorentzBoost.h"

void MonteCarlo::twoBody(HepMC::GenEvent *evt,
			 HepMC::GenParticle *parent, 
			 HepMC::GenParticle *daughter1, 
			 HepMC::GenParticle *daughter2,
			 int particleId1,
			 int particleId2,
			 double daughterMass1,
			 double daughterMass2) {

  // Create a vertex and add parent particle to it:
  HepMC::GenVertex *vert = new HepMC::GenVertex();
  vert->add_particle_in(parent);

  // Get the parent mass
  double parentMass = parent->generatedMass();
  
  // Calculate energy of first daughter particle in the rest frame 
  // of the parent.
  double daughterE1 = (std::pow(parentMass,2)+
		       std::pow(daughterMass1,2)-
		       std::pow(daughterMass2,2))/(2.*parentMass);

  // Momentum |p| of daughter 1
  double daughterP1 = std::sqrt(std::pow(daughterE1,2)-std::pow(daughterMass1,2));

  // Energy of the second daughter
  double daughterE2 = parentMass-daughterE1;
  
  // Generate cottheta and phi for one daughter.
  double phi1 = 2.0*M_PI*(double)rand()/RAND_MAX;
  double costh1 = 2.0*(double)rand()/RAND_MAX-1.0;

  // Calculate pt for the first daughter.
  double pt1 = std::sqrt(1.0-std::pow(costh1,2))*daughterP1;

  // Assemble daughter one fourvector.
  HepMC::FourVector fvecDaughter1(pt1*std::cos(phi1),
                                  pt1*std::sin(phi1),
                                  daughterP1*costh1,
                                  daughterE1);
  
  // Other daughter is produced back to back.
  HepMC::FourVector fvecDaughter2(-fvecDaughter1.px(),
		        	  -fvecDaughter1.py(),
                                  -fvecDaughter1.pz(),
                                  fvecDaughter1.e());
  
  // Create boost vector
  HepMC::FourVector fvecParent = parent->momentum();
  HepMC::FourVector boost(-fvecParent.px(),
	   	          -fvecParent.py(),
		          -fvecParent.pz(),
                          fvecParent.e());

  // Boost both daughters into lab frame.
  fvecDaughter1 = LorentzBoost::lorentzBoost(boost,fvecDaughter1);
  fvecDaughter2 = LorentzBoost::lorentzBoost(boost,fvecDaughter2);

  // Add daughter particles to the vertex.
  vert->add_particle_out(new HepMC::GenParticle(fvecDaughter1,
						particleId1,1));

  vert->add_particle_out(new HepMC::GenParticle(fvecDaughter2,
						particleId2,1));

  // Add the vertex to the event container.
  evt->add_vertex(vert);
}

void MonteCarlo::twoBody(HepMC::GenEvent *evt,
			 HepMC::GenParticle *parent,
			 int particleId1,
			 int particleId2,
			 double daughterMass1,
			 double daughterMass2) {
  HepMC::GenParticle *daughter1;
  HepMC::GenParticle *daughter2;

  twoBody(evt,parent,daughter1,daughter2,
	  particleId1,particleId2,
	  daughterMass1,daughterMass2);
}

HepMC::GenParticle MonteCarlo::generate() {
  double pt, rapidity, E_pz, pz, phi;
  double ranNum = (double)rand()/RAND_MAX;
  
  // Spectrum.
  const double prob[] = {0., 0.4, 0.6, 0.7, 0.75, 0.775, 0.8, 1.0};
  const double ptspectrum[] = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
  const double pi0mass = 0.1349766;

  // Generate pt from spectrum
  int i=0;
  while(i<sizeof(prob)/sizeof(int) && prob[i]<ranNum) i++;
  pt = ptspectrum[i];
  
  // Pick a random rapidity (flat distribution)
  rapidity=6.0*(double)rand()/RAND_MAX - 3.0;
  if(rapidity!=0) {
    E_pz = (std::exp(2.*rapidity)+1.)/(std::exp(2.*rapidity)-1.); // E/pz
    pz=std::sqrt((std::pow(pi0mass,2)+std::pow(pt,2))/(std::pow(E_pz,2)-1.));
    if(rapidity<0.) pz=-pz;
  }
  else {
    pz=0.;
  }
  
  // Generate flat phi between 0 and 2PI.
  phi=2.0*M_PI*(double)rand()/RAND_MAX;
  
  HepMC::FourVector fvec(pt*cos(phi),
                    pt*sin(phi),
                    pz,
                    std::sqrt(std::pow(pi0mass,2)+std::pow(pt,2)+std::pow(pz,2)));
  
  return  HepMC::GenParticle(fvec,111,3);
}
