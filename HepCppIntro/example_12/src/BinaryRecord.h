/*
** W. H. Bell
** 
** A binary file implementation of the IDataRecord interface.
*/

#ifndef BINARY_RECORD_H
#define BINARY_RECORD_H

// Include the base class
#include "IDataRecord.h"

#include <fstream>

// Inherit from the IDataRecord interface
class BinaryRecord : public IDataRecord {
 public:

  /** Construct an Ascii record of a given file name and number 
  ** of columns.  This opens an output file stream. */
  BinaryRecord(char *filename, int columns);

  /** A destructor to close the output file stream. */
  ~BinaryRecord(void);

  /** A function to append a row of data to this record.  
  ** The number of elements in the rowData array must be greater 
  ** than or equal to the number of columns. */ 
  virtual int appendRow(int *rowData);

 private:
  /** A data member to store the output file stream */
  std::ofstream m_ofstream;

  /** A data member to store the number of columns in this record. */
  int m_cols;
};

#endif
