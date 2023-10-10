/*
** W. H. Bell
** 
** An ascii file implementation of the IDataRecord interface.
*/

#include "AsciiRecord.h"
#include <iostream>

AsciiRecord::AsciiRecord(char *filename, int columns) {
  m_cols = columns;
  m_ofstream.open(filename);
}

AsciiRecord::~AsciiRecord(void) {
  if(m_ofstream) {
    m_ofstream.close();
  }
}

int AsciiRecord::appendRow(int *rowData) {
  if(!m_ofstream) {
    std::cerr << "Error: could not open output stream" << std::endl;
    return 1;
  }

  std::cout << "Appending to an ascii record" << std::endl;

  for (int i=0;i<m_cols;i++) {
    m_ofstream << rowData[i] << " ";
  }

  m_ofstream << std::endl;

  return 0;
}
