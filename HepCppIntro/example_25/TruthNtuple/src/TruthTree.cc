#include "TruthTree.h"

#include <fstream>
#include "HepMC/GenEvent.h"
#include "HepMC/GenVertex.h"
#include "HepMC/GenParticle.h"
#include "HepPDT/ParticleData.hh"
#include "HepPDT/ParticleDataTable.hh"
#include "HepPDT/TableBuilder.hh"
#include "TFile.h"
#include "TTree.h"

//---------------------------------------------------------------------

TruthTree::TruthTree(std::string outputFile):
  m_outputFile(outputFile),
  m_tfile(0),
  m_tree(0) {
  m_particleDataTable = new HepPDT::ParticleDataTable("Generic Particle Table");
}

//---------------------------------------------------------------------

TruthTree::~TruthTree() {
  if(m_tfile) delete m_tfile;
  if(m_particleDataTable) delete m_particleDataTable;
}

//---------------------------------------------------------------------

int TruthTree::open(void) {
  m_tfile = new TFile(m_outputFile.c_str(),"RECREATE");
  if(!m_tfile) {
    std::cerr << "Error: could not open root file " << m_outputFile << std::endl;
    return 1;
  }
  
  // Create a new tree
  m_tree = new TTree("mctree","Pythia Data");
 
  // Read in particle.tbl
  std::string ptbl = "particle.tbl";
  std::ifstream pdFile(ptbl.c_str());
  if(!pdFile) {
    std::cerr << "Cannot open " << ptbl << " for reading!" << std::endl;
    return 1;
  }

  HepPDT::TableBuilder tb(*m_particleDataTable);
  if(!addParticleTable(pdFile,tb)) {
    std::cerr << "Cannot add particle table" << std::endl;
    return 2;
  } 
 
  return 0;
}

//---------------------------------------------------------------------

int TruthTree::save(void) {
  m_tfile->Write();
  
  return 0;
}

//---------------------------------------------------------------------

int TruthTree::book(void) {
  // Create new objects but do not delete them such that they can be
  // stored in the TTree
  m_truth_part_px = new std::vector<float>();
  m_truth_part_py = new std::vector<float>();
  m_truth_part_pz = new std::vector<float>();
  m_truth_part_e = new std::vector<float>();
  m_truth_part_status = new std::vector<long>();
  m_truth_part_pdgId = new std::vector<long>();
  m_truth_part_barcode = new std::vector<long>();
  m_truth_part_charge = new std::vector<float>();
  m_truth_part_prod_vtx = new std::vector<long>();
  m_truth_part_end_vtx = new std::vector<long>();
  m_truth_vtx_x = new std::vector<float>();
  m_truth_vtx_y = new std::vector<float>();
  m_truth_vtx_z = new std::vector<float>();
  m_truth_vtx_t = new std::vector<float>();
  m_truth_vtx_id = new std::vector<long>();
  m_truth_vtx_barcode = new std::vector<long>();

  // Assign the branch addresses of particle and vertex variables.
  m_tree->Branch("truth_npart",        &m_truth_npart, "truth_npart/I");
  m_tree->Branch("truth_part_px",      &m_truth_part_px);
  m_tree->Branch("truth_part_py",      &m_truth_part_py);
  m_tree->Branch("truth_part_pz",      &m_truth_part_pz);
  m_tree->Branch("truth_part_e",       &m_truth_part_e);
  m_tree->Branch("truth_part_status",  &m_truth_part_status);
  m_tree->Branch("truth_part_pdgId",   &m_truth_part_pdgId);
  m_tree->Branch("truth_part_barcode", &m_truth_part_barcode);
  m_tree->Branch("truth_part_charge",  &m_truth_part_charge);
  m_tree->Branch("truth_part_prod_vtx",&m_truth_part_prod_vtx);
  m_tree->Branch("truth_part_end_vtx", &m_truth_part_end_vtx);
  
  m_tree->Branch("truth_nvtx",         &m_truth_nvtx, "truth_nvtx/I");
  m_tree->Branch("truth_vtx_x",        &m_truth_vtx_x);
  m_tree->Branch("truth_vtx_y",        &m_truth_vtx_y);
  m_tree->Branch("truth_vtx_z",        &m_truth_vtx_z);
  m_tree->Branch("truth_vtx_t",        &m_truth_vtx_t);
  m_tree->Branch("truth_vtx_id",       &m_truth_vtx_id);
  m_tree->Branch("truth_vtx_barcode",  &m_truth_vtx_barcode);

  return 0;
}

//---------------------------------------------------------------------

int TruthTree::fill(HepMC::GenEvent *genEvent) {
  long ipart = 0, ivtx = 0; 
  int ret_val;

  // Instantiate iterators needed in this member function. 
  HepMC::GenEvent::particle_const_iterator hepmc_part_itr;
  HepMC::GenEvent::vertex_const_iterator hepmc_vtx_itr;

  // Clear the TTree associated vectors
  m_truth_part_px->clear(); 
  m_truth_part_py->clear();
  m_truth_part_pz->clear();
  m_truth_part_e->clear();
  m_truth_part_status->clear();
  m_truth_part_pdgId->clear();
  m_truth_part_barcode->clear();
  m_truth_part_charge->clear();
  m_truth_part_prod_vtx->clear();
  m_truth_part_end_vtx->clear();
  m_truth_vtx_x->clear();
  m_truth_vtx_y->clear();
  m_truth_vtx_z->clear();
  m_truth_vtx_t->clear();
  m_truth_vtx_id->clear();
  m_truth_vtx_barcode->clear();

  // Clear the number of particles and vertices.
  m_truth_npart = 0;
  m_truth_nvtx = 0;

  // Create maps used to map indices to pointers.
  std::map<HepMC::GenParticle *, long > particleIndexMap;
  std::map<HepMC::GenVertex *, long > vertexIndexMap;

  // Loop over all particles and build up the particle-index map.  
  for (hepmc_part_itr = genEvent->particles_begin(); 
       hepmc_part_itr != genEvent->particles_end();
       hepmc_part_itr++) {
    particleIndexMap.insert(std::make_pair((*hepmc_part_itr),ipart));
    ipart++;
  }
      
  // Record the total number of particles
  m_truth_npart = ipart;
      
  // Loop over the vertices and build up the vertex-index map.
  for (hepmc_vtx_itr = genEvent->vertices_begin();
       hepmc_vtx_itr != genEvent->vertices_end();
       hepmc_vtx_itr++) {
    vertexIndexMap.insert(std::make_pair((*hepmc_vtx_itr),ivtx));
    ivtx++;
  }
      
  // Record the total number of vertices
  m_truth_nvtx = ivtx;
  
  // Increase the size of the TTree vectors to the number of particles
  // in this event.
  m_truth_part_px->resize(m_truth_npart,0.);
  m_truth_part_py->resize(m_truth_npart,0.);
  m_truth_part_pz->resize(m_truth_npart,0.);
  m_truth_part_e->resize(m_truth_npart,0.);
  m_truth_part_status->resize(m_truth_npart,0);
  m_truth_part_pdgId->resize(m_truth_npart,0);
  m_truth_part_barcode->resize(m_truth_npart,0);
  m_truth_part_charge->resize(m_truth_npart,0.);
  m_truth_part_prod_vtx->resize(m_truth_npart,0);
  m_truth_part_end_vtx->resize(m_truth_npart,0);

  // Write out the event.
      
  // Loop over the GenParticle map and fill the vectors storing
  // particle quantities.
  std::map<HepMC::GenParticle *, long >::iterator part_index_itr;
  for (part_index_itr = particleIndexMap.begin(); 
       part_index_itr != particleIndexMap.end(); 
       part_index_itr++) {
    
    // Get the particle index
    ipart = (*part_index_itr).second;

    // Fill the particle entries
    (*m_truth_part_px)[ipart] = (*part_index_itr).first->momentum().px();
    (*m_truth_part_py)[ipart] = (*part_index_itr).first->momentum().py();
    (*m_truth_part_pz)[ipart] = (*part_index_itr).first->momentum().pz();
    (*m_truth_part_e)[ipart] = (*part_index_itr).first->momentum().e();
    (*m_truth_part_status)[ipart] = (*part_index_itr).first->status();
    (*m_truth_part_pdgId)[ipart] = (*part_index_itr).first->pdg_id();
    (*m_truth_part_barcode)[ipart] = (*part_index_itr).first->barcode();
	
    // Find the index of the production vertex
    ret_val= findVertexIndex (&vertexIndexMap, 
			      (*part_index_itr).first->production_vertex(),
			      &(*m_truth_part_prod_vtx)[ipart]);
    if(ret_val) return ret_val;
    
    
    // Find the index of the end vertex
    ret_val = findVertexIndex (&vertexIndexMap, 
			       (*part_index_itr).first->end_vertex(),
			       &(*m_truth_part_end_vtx)[ipart]);
    if(ret_val) return ret_val;
    
	
    // Record the charge if the PDG id is known
    (*m_truth_part_charge)[ipart]=-999.0;
    const HepPDT::ParticleData* particleData = m_particleDataTable->particle(HepPDT::ParticleID(abs((*part_index_itr).first->pdg_id())));
    if(particleData) {
      (*m_truth_part_charge)[ipart] = particleData->charge();
      if ((*part_index_itr).first->pdg_id()<0) {
	(*m_truth_part_charge)[ipart] = -(*m_truth_part_charge)[ipart];
      }
    }
  }

  // Increase the size of the TTree vectors associated with vectices
  // to match the number of vertices in this event.
  m_truth_vtx_x->resize(m_truth_nvtx, 0.);
  m_truth_vtx_y->resize(m_truth_nvtx, 0.);
  m_truth_vtx_z->resize(m_truth_nvtx, 0.);
  m_truth_vtx_t->resize(m_truth_nvtx, 0.);
  m_truth_vtx_id->resize(m_truth_nvtx, 0);
  m_truth_vtx_barcode->resize(m_truth_nvtx, 0);
      
  // Write out the GenVertex object data.
  std::map<HepMC::GenVertex *, long >::iterator vtx_index_itr;
  std::vector<long > attachedParticles;
  for (vtx_index_itr = vertexIndexMap.begin(); 
       vtx_index_itr != vertexIndexMap.end(); 
       vtx_index_itr++) {
    
    // Get the vertex index
    ivtx = (*vtx_index_itr).second;
    
    // Fill the vertex entries
    (*m_truth_vtx_x)[ivtx] = (*vtx_index_itr).first->position().x();
    (*m_truth_vtx_y)[ivtx] = (*vtx_index_itr).first->position().y();
    (*m_truth_vtx_z)[ivtx] = (*vtx_index_itr).first->position().z();
    (*m_truth_vtx_t)[ivtx] = (*vtx_index_itr).first->position().t();
    (*m_truth_vtx_id)[ivtx] = (*vtx_index_itr).first->id();
    (*m_truth_vtx_barcode)[ivtx] = (*vtx_index_itr).first->barcode();
  }

  // Copy this entry into the TTree;
  m_tree->Fill();

  return 0;
}
							  
//---------------------------------------------------------------------

int TruthTree::findVertexIndex (std::map<HepMC::GenVertex *, long > *vertexIndexMap, 
				HepMC::GenVertex *vtxPtr, long *index) {
  std::map<HepMC::GenVertex *, long >::iterator vtx_index_itr;
  
  // Test if the vertex pointer is null or not.
  if(vtxPtr) {
    
    // Find the vertex in the map
    vtx_index_itr = vertexIndexMap->find(vtxPtr);
    
    if(vtx_index_itr==vertexIndexMap->end()) {
      std::cerr << "Error: the vertex does not exist in the map" << std::endl;
      *index = -999;
      return 1;
    }
    
    // Assign the index of this vertex;
    *index = (*vtx_index_itr).second;
  }
  else {
    // There is no vertex assign -1;
    *index = -1;
  }
  
  return 0;
}

