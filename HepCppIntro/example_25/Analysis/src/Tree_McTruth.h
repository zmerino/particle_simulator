#ifndef TREE_MCTRUTH_H
#define TREE_MCTRUTH_H

#include <TROOT.h>
#include <TChain.h>
#include <vector>

// Include the base class
#include "Tree_base.h"

// Inherit from the Tree_base base class.
class Tree_McTruth: public Tree_base {
 public:

  /** A constructor to set the fileList and treePath */
  Tree_McTruth(std::list<std::string> fileList, std::string treePath);

  /** A destructor to delete dynamically allocated memory. */
  virtual ~Tree_McTruth();

  /** A member function to set the branch addresses */
  virtual int initialize(void);

  /** A data member to print the contents of this entry */
  int print(void);

  // Transient variables
  // These variables are calculated when an event is read.
  std::vector<float> *truth_part_pt;
  std::vector<float> *truth_part_eta;
  std::vector<float> *truth_part_phi;
  std::vector<float> *truth_part_m;
 

  // Declaration of leaf types 
  //
  // (This is just copy-pasted from the output of
  // Tracks->MakeClass and should therefore be updated when
  // the tree is updated)

  // Declaration of leave types
  Int_t           truth_npart;
  std::vector<float>   *truth_part_px;
  std::vector<float>   *truth_part_py;
  std::vector<float>   *truth_part_pz;
  std::vector<float>   *truth_part_e;
  std::vector<long>    *truth_part_status;
  std::vector<long>    *truth_part_pdgId;
  std::vector<long>    *truth_part_barcode;
  std::vector<float>   *truth_part_charge;
  std::vector<long>    *truth_part_prod_vtx;
  std::vector<long>    *truth_part_end_vtx;
  Int_t           truth_nvtx;
  std::vector<float>   *truth_vtx_x;
  std::vector<float>   *truth_vtx_y;
  std::vector<float>   *truth_vtx_z;
  std::vector<float>   *truth_vtx_t;
  std::vector<long>    *truth_vtx_id;
  std::vector<long>    *truth_vtx_barcode;
 
 protected:
  /** A function to fill transient data variables. */
  virtual int fillTransientVariables(void);

 private:
  /** A member function to initialise pointers and set the 
  ** branch addresses */ 
  int setupBranches(void);

  /** A data member to flag if the transient data calculation 
  ** is enabled or not. */
  bool m_transientConversionEnabled;
};

#endif
