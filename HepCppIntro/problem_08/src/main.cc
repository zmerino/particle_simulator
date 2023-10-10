/* W. H. Bell
** Simple track instantiations. 
*/

#include <iostream>
#include "TrackContainer.h"

int main() {
  TrackContainer<float> muonTrack;
  TrackContainer<double> electronTrack;

  muonTrack.pt = 10.0;
  muonTrack.z0 = 0.200;
  std::cout << "Muon pt=" << muonTrack.pt << std::endl;
  std::cout << "Muon z0=" << muonTrack.z0 << std::endl;
  std::cout << "Electron phi0=" << electronTrack.phi0 << std::endl;

  return 0;
}
