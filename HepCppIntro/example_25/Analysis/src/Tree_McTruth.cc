#include "Tree_McTruth.h"

#include <cmath>
#include <cfloat>
#include <iostream>

//---------------------------------------------------------------------

Tree_McTruth::Tree_McTruth(std::list<std::string> fileList, std::string treePath): Tree_base(fileList,treePath),
                                                                                   m_transientConversionEnabled(false) {
}

//---------------------------------------------------------------------

Tree_McTruth::~Tree_McTruth() {

  // Delete transient data
  delete truth_part_pt;
  delete truth_part_eta;
  delete truth_part_phi;
  delete truth_part_m;
}

//---------------------------------------------------------------------

int Tree_McTruth::initialize() {
  // If the TChain can not be created return an error code.
  if(createChain() != 0) {
    return 100;
  }

  if(setupBranches() != 0) {
    return 200;
  }

  return 0;
}

//---------------------------------------------------------------------

int Tree_McTruth::setupBranches() {
  truth_part_pt = new std::vector<float>();
  truth_part_eta = new std::vector<float>();
  truth_part_phi = new std::vector<float>();
  truth_part_m = new std::vector<float>();

  // Initialise variables
  truth_npart = 0;
  truth_nvtx = 0;


  // Initialise pointers (these can be copied from MakeClass)
  truth_part_px = 0;
  truth_part_py = 0;
  truth_part_pz = 0;
  truth_part_e = 0;
  truth_part_status = 0;
  truth_part_pdgId = 0;
  truth_part_barcode = 0;
  truth_part_charge = 0;
  truth_part_prod_vtx = 0;
  truth_part_end_vtx = 0;
  truth_vtx_x = 0;
  truth_vtx_y = 0;
  truth_vtx_z = 0;
  truth_vtx_t = 0;
  truth_vtx_id = 0;
  truth_vtx_barcode = 0;

  if(isBranchInTree("truth_npart")) m_tree->SetBranchAddress("truth_npart", &truth_npart);
  if(isBranchInTree("truth_part_px")) m_tree->SetBranchAddress("truth_part_px", &truth_part_px);
  if(isBranchInTree("truth_part_py")) m_tree->SetBranchAddress("truth_part_py", &truth_part_py);
  if(isBranchInTree("truth_part_pz")) m_tree->SetBranchAddress("truth_part_pz", &truth_part_pz);
  if(isBranchInTree("truth_part_e")) m_tree->SetBranchAddress("truth_part_e", &truth_part_e);
  if(isBranchInTree("truth_part_status")) m_tree->SetBranchAddress("truth_part_status", &truth_part_status);
  if(isBranchInTree("truth_part_pdgId")) m_tree->SetBranchAddress("truth_part_pdgId", &truth_part_pdgId);
  if(isBranchInTree("truth_part_barcode")) m_tree->SetBranchAddress("truth_part_barcode", &truth_part_barcode);
  if(isBranchInTree("truth_part_charge")) m_tree->SetBranchAddress("truth_part_charge", &truth_part_charge);
  if(isBranchInTree("truth_part_prod_vtx")) m_tree->SetBranchAddress("truth_part_prod_vtx", &truth_part_prod_vtx);
  if(isBranchInTree("truth_part_end_vtx")) m_tree->SetBranchAddress("truth_part_end_vtx", &truth_part_end_vtx);
  if(isBranchInTree("truth_nvtx")) m_tree->SetBranchAddress("truth_nvtx", &truth_nvtx);
  if(isBranchInTree("truth_vtx_x")) m_tree->SetBranchAddress("truth_vtx_x", &truth_vtx_x);
  if(isBranchInTree("truth_vtx_y")) m_tree->SetBranchAddress("truth_vtx_y", &truth_vtx_y);
  if(isBranchInTree("truth_vtx_z")) m_tree->SetBranchAddress("truth_vtx_z", &truth_vtx_z);
  if(isBranchInTree("truth_vtx_t")) m_tree->SetBranchAddress("truth_vtx_t", &truth_vtx_t);
  if(isBranchInTree("truth_vtx_id")) m_tree->SetBranchAddress("truth_vtx_id", &truth_vtx_id);
  if(isBranchInTree("truth_vtx_barcode")) m_tree->SetBranchAddress("truth_vtx_barcode", &truth_vtx_barcode);

  std::string branchNamesCh[4] = {"truth_part_px",
				  "truth_part_py",
				  "truth_part_pz",
				  "truth_part_e"};
  std::vector<std::string> branchNames(branchNamesCh,branchNamesCh+4);
  
  if(areBranchesInTree(&branchNames)) m_transientConversionEnabled = true;

  return 0;
}

//---------------------------------------------------------------------

int Tree_McTruth::fillTransientVariables() {
  if(!m_transientConversionEnabled) return 0; // Skip if needed branches are not present.

  int ret_val;
  
  double pt_sq, p_sq, m_sq, p;
  int ipart;

  // Resize the vectors ready to be filled.
  truth_part_pt->resize(truth_npart,0.);
  truth_part_eta->resize(truth_npart,0.);
  truth_part_phi->resize(truth_npart,0.);
  truth_part_m->resize(truth_npart,0.);
  
  // Similar to SimpleVector.icc methods from HepMC

  // Loop over the truth particles in the event
  ipart = 0;
  while(ipart<truth_npart) {
    
    // Calculate pt
    pt_sq = (*truth_part_px)[ipart]*(*truth_part_px)[ipart] + (*truth_part_py)[ipart]*(*truth_part_py)[ipart];
    if(pt_sq>0.) {
      (*truth_part_pt)[ipart] = std::sqrt(pt_sq);
    }
    else {
      (*truth_part_pt)[ipart] = 0.;
    }

    // Calculate phi
    if((*truth_part_px)[ipart]==0.0 && (*truth_part_py)[ipart]== 0.0) {
      (*truth_part_phi)[ipart] = 0.;
    }
    else {
      (*truth_part_phi)[ipart] = std::atan2((*truth_part_py)[ipart],(*truth_part_px)[ipart]);
    }

    // Calculate |p|^2
    p_sq = (*truth_part_px)[ipart]*(*truth_part_px)[ipart] + (*truth_part_py)[ipart]*(*truth_part_py)[ipart] + (*truth_part_pz)[ipart]*(*truth_part_pz)[ipart];
    
    // Calculate mass
    m_sq = (*truth_part_e)[ipart]*(*truth_part_e)[ipart]- p_sq;
    if(m_sq>0.) {
      (*truth_part_m)[ipart] = std::sqrt(m_sq);
    }
    else {
      (*truth_part_m)[ipart] = 0.;
    }
    
    // Calculate eta
    if(p_sq>0.) {
      p = std::sqrt(p_sq);
    }
    else {
      p = 0;
    }

    if (p==0) {
      (*truth_part_eta)[ipart] = 0;
    }
    else if(p==(*truth_part_pz)[ipart]) {
      (*truth_part_eta)[ipart] = FLT_MAX; // float limit
    }
    else if(p==-(*truth_part_pz)[ipart]) {
       (*truth_part_eta)[ipart] = -FLT_MAX; // - float limit
    }
    else {
      (*truth_part_eta)[ipart] = 0.5*log((p+(*truth_part_pz)[ipart])/(p-(*truth_part_pz)[ipart]));
    }

    ipart++;
  }
  
  return 0;
}

//---------------------------------------------------------------------

int Tree_McTruth::print(void) {
  int ipart;

  // A printout similar to the GenEvent::print member function
  std::cout << std::endl << std::endl;
  std::cout << "truth_npart=" << truth_npart << std::endl;
  ipart = 0;
  while(ipart < truth_npart) {
    // Print in the same order as the GenEvent dump
    std::cout << (*truth_part_barcode)[ipart] << "\t";
    std::cout << (*truth_part_pdgId)[ipart] << " ";
    std::cout << (*truth_part_px)[ipart] << ",";
    std::cout << (*truth_part_py)[ipart] << ",";
    std::cout << (*truth_part_pz)[ipart] << ",";
    std::cout << (*truth_part_e)[ipart] << "   ";
    std::cout << (*truth_part_status)[ipart] << "\t";
    if((*truth_part_end_vtx)[ipart]>=0) {
      std::cout << (*truth_vtx_barcode)[(*truth_part_end_vtx)[ipart]] << " ";
    }
    else {
      std::cout << "(nil) ";
    }
    std::cout << (*truth_part_charge)[ipart] << " ";
    if((*truth_part_prod_vtx)[ipart]>=0) {
      std::cout << (*truth_vtx_barcode)[(*truth_part_prod_vtx)[ipart]];
    }
    else {
      std::cout << "(nil) ";
    }
    std::cout << std::endl;
    ipart++;
  }
  std::cout << std::endl;
  int ivtx = 0;
  while(ivtx < truth_nvtx) {
    std::cout << "Vertex:      " << (*truth_vtx_barcode)[ivtx];
    std::cout << " ID:  " << (*truth_vtx_id)[ivtx];
    std::cout << " (X,cT)=" << (*truth_vtx_x)[ivtx] << ",";
    std::cout << (*truth_vtx_y)[ivtx] << ",";
    std::cout << (*truth_vtx_z)[ivtx] << ",";
    std::cout << (*truth_vtx_t)[ivtx] << std::endl;
    ivtx++;
  }
  std::cout << std::endl;

  return 0;
}

//---------------------------------------------------------------------

