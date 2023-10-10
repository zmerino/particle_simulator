// W. H. Bell
// A root function to read a root file containing an TTree called
// tree and plot the associated data objects.
//
// Root features:
//   (1) /* */ comments are not allowed within a macro
//   (2) Closing ; after a command is obligatory after a command
//       unlike using it on at the root prompt.
//   (3) Methods can be accessed with . or -> whether or not the object 
//       is a pointer.
//
int plot(char *output_ps_file) {
  // Do a reset to clear memory.
  gROOT->Reset();             

  // Open the file
  TFile f1("tree.root");

  // List the contents of the file.
  f1.ls();                   	

  // Print the contents of the TNtuple object called random_dat
  tree->Print("all"); 

  // Plot all of the values of x contained in the TTree into a new
  // histogram h1.
  tree->Draw("x>>h1");   

  // Get a pointer to the histogram
  TH1F *h1 = (TH1F*)gDirectory->Get("h1");

  // Draw this histogram.      
  h1->Draw();

  // Plot x vs y for all of the values in the TTree, where the values
  // of y are less than 20, into the h2 histogram.  The h2 histogram
  // is defined with bin sizes.
  tree->Draw("x:y>>h2(20,14.0,22.0,20,7.0,13.0)","y<20"); 

  // Get a pointer to this histogram.
  TH2F *h2 = (TH2F*)gDirectory->Get("h2");

  // Open postscript file
  TPostScript ps(output_ps_file,-111); 

  // Draw the h2 histogram into the postscript file.
  h2->Draw();

  // Close postscript file
  ps.Close();

  // Open a new TFile.
  TFile f2("histos.root","RECREATE","Analysis Histograms");

  // Save the h2 histogram into this TFile.
  f2.WriteTObject(h2);

  // Close the TFile.
  f2.Close();

  // Close the TFile containing the TTree.
  f1.Close();                  

  return 0; // Success                    
}
