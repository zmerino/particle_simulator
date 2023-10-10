/*
** W. H. Bell
** 
** A binary file implementation of the IDataRecord interface.
*/

#include "BinaryRecord.h"
#include <iostream>

BinaryRecord::BinaryRecord(char *filename, int columns) {
  m_cols = columns;
  m_ofstream.open(filename, std::ios::out | std::ios::binary);
}

BinaryRecord::~BinaryRecord(void) {
  if(m_ofstream) {
    m_ofstream.close();
  }
}

int BinaryRecord::appendRow(int *rowData) {
  if(!m_ofstream) {
    std::cerr << "Error: could not open output stream" << std::endl;
    return 1;
  }

  std::cout << "Appending to an binary record" << std::endl;
  m_ofstream.write(reinterpret_cast<char*>(rowData), sizeof(int)*m_cols);

  m_ofstream.flush();
  return 0;
}
