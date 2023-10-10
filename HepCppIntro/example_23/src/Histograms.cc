/* W. H. Bell
** A program demonstrating the use of 1d Root histogramming
** methods.
*/

#include <iostream>
#include <cmath>
#include <TROOT.h>
#include <TFile.h>
#include <TH1.h>

using namespace std;

void usage(char *);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv[0]);
    return 0;
  }

  // Create static memory object
  TROOT simple("histos","Histogram Examples");

  // Open new Root file
  cout << "Opening root file: " << argv[1] << endl;
  TFile *rfile = new TFile(argv[1],"RECREATE","Histogram Example");
  if(rfile==0) {
    cout << "Could not create root file: " << argv[1] << endl;
    return 0;
  }

  // Create new 1d histogram
  Int_t nbinsx = 100;
  Axis_t xlow = 0.0;
  Axis_t xup = M_PI;
  TH1F *histo = new TH1F("histo","Sine Wave",nbinsx,xlow,xup);

  // Fill the histogram with data
  Axis_t x;
  Stat_t w;
  for(int i=1;i<=100;i++) {
    x = M_PI/100.0*((double)i);
    w = std::sin((double)x);
    
    histo->Fill(x,w);
  }

  // Close root file
  rfile->Write();

  return 0;
}

void usage(char *exename) {
  cout << "Usage: " << exename << " <file name>" << endl;
  cout << " where <file name> is the root file to be written." << endl;
}
