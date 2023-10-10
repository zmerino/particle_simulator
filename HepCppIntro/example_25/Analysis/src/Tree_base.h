/* W. H. Bell
** A base class to provide functionality for TTree reading 
*/ 

#ifndef TREE_BASE_H
#define TREE_BASE_H

#include <TObject.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <string>
#include <list>
#include <vector>

//---------------------------------------------------------------------

class Tree_base {
 public:
  /** Construct Tree_base with a given list of files and a treePath. */
  Tree_base(std::list<std::string> fileList, std::string treePath);

  /** Default destructor */
  virtual ~Tree_base();

  /** A function to set branch addresses. */
  virtual int initialize(void)=0;

  /** A function to check if a given branch is in this version of 
  ** the TTree */
  bool isBranchInTree(std::string branchName);

  /** A function to check all of the supplied brance names are present 
  ** in this version of the TTree. */
  bool areBranchesInTree(std::vector<std::string>* branchNames);

  /** Read the current entry from the TTree and increment to the 
  ** next entry. */
  int getEntry(void);

  /** Set the current entry, read it and increment to the 
  ** next entry. */
  int getEntry(Long64_t entry); // Read a specified entry
  
  /** A data member to store the number of entries in the TChain. */
  Long64_t nentries;

  /** A data member to store the current entry. */
  Long64_t current_entry; // Current entry
  
  /** A member function to create a list of files names 
  ** from a text file. */
  static std::list<std::string> readFileList(std::string fileName); 

 protected:
  /** Create a TChain from the given file name list and TTree path */
  int createChain(void);

  /** Fill any transient information. */
  virtual int fillTransientVariables(void);
  
  /** A data member to store the list of ROOT files in the TChain. */
  std::list<std::string> m_fileList;

  /** The path to the TTree within the TFile. */
  std::string m_treePath;

  /** A data member to store a pointer to the constructed TChain. */
  TChain *m_tree;

  /** A data member to store the list of branch names in this version 
  ** of the TTree. */
  std::vector<std::string> m_branchNames;

 private:
  /** Read the list of branch names from the TChain. */
  int readBranchNames(void);
};

#endif
