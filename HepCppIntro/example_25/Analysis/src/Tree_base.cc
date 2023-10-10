#include "Tree_base.h"

#include "TObjArray.h"

#include <iostream>
#include <fstream>
#include <algorithm>

// Needed for file parsing
const int MAX_LINE_LENGTH = 400;

//---------------------------------------------------------------------

Tree_base::Tree_base(std::list<std::string> fileList, 
		     std::string treePath): current_entry(0),
					    m_fileList(fileList),
					    m_treePath(treePath),
					    m_tree(0){
}

//---------------------------------------------------------------------

Tree_base::~Tree_base() {
}

//---------------------------------------------------------------------

int Tree_base::createChain() {
  m_tree = new TChain(m_treePath.c_str());

  for(std::list<std::string>::iterator itr = m_fileList.begin(); itr != m_fileList.end(); itr++) {
    m_tree->Add((*itr).c_str());
  }

  if (!m_tree) {
    std::cout << "Error TChain creation with path \"" << m_treePath << "\" failed" << std::endl;
    return 1;
  }
  nentries = m_tree->GetEntries();
  std::cout << "Created TChain with path \"" << m_treePath << "\"" << std::endl;
  std::cout << "Number of events in chain: " << nentries << std::endl;
  std::cout << std::endl;

  if(readBranchNames() != 0) {
    return 1;
  }

  return 0;
}

//---------------------------------------------------------------------

int Tree_base::readBranchNames() {
  int i, numberOfBranches;
  TObject *tObject;
  std::string branchName;

  m_branchNames.clear();

  TObjArray *listOfBranches = m_tree->GetListOfBranches();
  numberOfBranches = listOfBranches->GetEntries();
  
  for(i=0;i<numberOfBranches;i++) {
    tObject = (*listOfBranches)[i];
    if(tObject) {
      branchName = tObject->GetName();
      m_branchNames.push_back(branchName);
    }
  }

  return 0;
}

//---------------------------------------------------------------------

bool Tree_base::isBranchInTree(std::string branchName) {
  std::vector<std::string>::iterator itr = m_branchNames.begin();
  std::vector<std::string>::iterator itr_end = m_branchNames.end();
  
  if(find(itr,itr_end,branchName) != m_branchNames.end()) {
    return true;
  }
  
  return false;
}

//---------------------------------------------------------------------

bool Tree_base::areBranchesInTree(std::vector<std::string>* branchNames) {
  bool result = true;

  std::vector<std::string>::iterator itr = branchNames->begin();
  std::vector<std::string>::iterator itr_end = branchNames->end();

  // Require all branches are found.  If one is missing exit loop and
  // return false.
  while(itr!=itr_end && result) {
    result &= isBranchInTree((*itr));
    itr++;
  }

  return result;
}

//---------------------------------------------------------------------

int Tree_base::getEntry() {
  if (!m_tree) return -1;

  // Read contents of current_entry
  if(current_entry < nentries) {
    m_tree->GetEntry(current_entry);
    current_entry++;
    return fillTransientVariables();
  }
  else {
    return -1;
  }
}

//---------------------------------------------------------------------

int Tree_base::getEntry(Long64_t entry) {
  if (!m_tree) return -1;

  // Read contents of entry
  if(entry < nentries) {
    m_tree->GetEntry(entry);
    current_entry=entry;
    return fillTransientVariables();
  }
  else {
    return -1;
  }
}

//---------------------------------------------------------------------

int Tree_base::fillTransientVariables(void) {
  return 0;
}

//---------------------------------------------------------------------

std::list<std::string> Tree_base::readFileList(std::string fileName) {
  std::list<std::string> fileList;

  char line[MAX_LINE_LENGTH];
  
  ifstream file(fileName.c_str());
  if(!file) {
    std::cerr << "Error: could not open " << fileName << std::endl;
    return fileList;
  }
  
  while(file.getline(line,MAX_LINE_LENGTH)) {
    fileList.push_back(std::string(line));
  }
  
  return fileList;
}

//---------------------------------------------------------------------

