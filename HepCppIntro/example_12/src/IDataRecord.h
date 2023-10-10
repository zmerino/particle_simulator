/*
** W. H. Bell
**
** A DataRecord interface.
*/

#ifndef IDATA_RECORD_H
#define IDATA_RECORD_H

class IDataRecord {
 public:
  /** A function to append a row of data to a record. */
  virtual int appendRow(int *rowData) = 0;
};

#endif
