/* W. H. Bell
**
** A program to demonstrate inheritance with three classes.
*/

#include <iostream>
#include "Particle.h"
#include "DetParticle.h"
#include "CalParticle.h"

using namespace std;

void printArray(double *p3vec);

int main() {
  double p3vec1[] = {1.5, 1.2, 0.5};
  Particle *particle = new Particle(111, p3vec1);

  double p3vec2[] = {7.0, 2.0, 0.1};
  DetParticle *detParticle = new DetParticle(11, p3vec2, 49);

  double p3vec3[] = {1.5, 2.2, 0.01};
  CalParticle *calParticle = new CalParticle(22, 0., p3vec3, 2.22); 


  double *p3vec;

  cout << "Particle (id, p3vec) = (" 
       << particle->id() << ", {" ;

  p3vec = particle->p3vec();
  printArray(p3vec);

  cout << "})" << endl;

  delete p3vec;

  
  cout << "DetParticle (id, p3vec, trackId) = (" 
       << detParticle->id() << ", {" ;

  p3vec = detParticle->p3vec();
  printArray(p3vec);

  cout << "}";
  cout << ", " << detParticle->trackId() << ")" << endl;

  delete p3vec;


  cout << endl;

  delete particle;
  delete detParticle;
  delete calParticle;

  return 0;
}

void printArray(double *p3vec) {
  for (int i=0; i<3; i++, p3vec++) {
    cout << *p3vec;
    if(i!=2) cout << ", ";
  }
}
