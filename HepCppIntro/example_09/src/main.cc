/* W. H. Bell
** A program to demonstrate the usage of operator overloading
*/

#include <iostream>
#include "BasicParticle.h"

using namespace std;

int main() {
  double fourvector1[4] = {3.0, 4.0, 5.0, 7.35};
  double fourvector2[4] = {2.0, 2.0, 1.0, 3.0};
  double fourvector3[4];

  BasicParticle *particle1 = new BasicParticle(fourvector1);
  BasicParticle *particle2 = new BasicParticle(fourvector2);
  BasicParticle particle3 = *particle1 + (*particle2);
  
  particle3.getFourVector(fourvector3);
  for (int i=0;i<4;i++) 
    cout << "fourvector3[" << i << "]="
  	 << fourvector3[i] << endl;
  cout << "particle 3 mass = " << particle3.getMass() << endl;
  cout << "particle 3 pt = " << particle3.getPt() << endl;

  delete particle1;
  delete particle2;

  return 0;
}
