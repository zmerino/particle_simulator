
#ifndef TRUTHTREE_H
#define TRUTHTREE_H

#include <string>
#include <map>
#include <vector>

// Forward declarations to reduce precompile time.
class TFile;
class TTree;
namespace HepMC {
  class GenEvent;
  class GenParticle;
  class GenVertex;
}
namespace HepPDT {
  class ParticleDataTable;
}

class TruthTree {  
 public:
 
  /** A constructor to assign an output file and setup an empty 
  ** particle data table. */
  TruthTree(std::string outputFile);

  /** A destructor to clean up the dynamically allocated memory. */
  ~TruthTree();

  /** A function to open the given TFile, create a new TTree and setup 
  ** the particle data table.  */
  int open(void);

  /** A function to setup dynamic memory and branch addresses for 
  ** TTree storage.  */
  int book(void);

  /** A function to copy the data from the supplied GenEvent into the 
  ** TTree. */
  int fill(HepMC::GenEvent *genEvent);

  /** A function to close the TFile. */
  int save(void);
  
 private:
  /** A function to find the vertex index for the supplied GenVertex 
  ** pointer */
  int findVertexIndex (std::map<HepMC::GenVertex *, long > *vertexIndexMap, 
		       HepMC::GenVertex *vtxPtr, long *index);

  /** A data member to store the output file name. */
  std::string m_outputFile;

  /** A data member to store a pointer to the output TFile. */
  TFile *m_tfile;

  /** A data member to store a pointer to the output TTree. */
  TTree *m_tree;

  /** A data member to store a pointer to the particle data table. */
  HepPDT::ParticleDataTable *m_particleDataTable;

  // TTree associated variables.
  int m_truth_npart; // Number of particles
  std::vector<float>* m_truth_part_px;
  std::vector<float>* m_truth_part_py;
  std::vector<float>* m_truth_part_pz;
  std::vector<float>* m_truth_part_e;
  std::vector<long>* m_truth_part_status;
  std::vector<long>* m_truth_part_pdgId;
  std::vector<long>* m_truth_part_barcode;
  std::vector<float>* m_truth_part_charge;
  std::vector<long>* m_truth_part_prod_vtx; // Index of the production vertex
  std::vector<long>* m_truth_part_end_vtx; // Index of the end vertex
  
  int m_truth_nvtx; // Number of vertices
  std::vector<float>* m_truth_vtx_x;
  std::vector<float>* m_truth_vtx_y;
  std::vector<float>* m_truth_vtx_z;
  std::vector<float>* m_truth_vtx_t;
  std::vector<long>* m_truth_vtx_id;
  std::vector<long>* m_truth_vtx_barcode;
};

#endif
