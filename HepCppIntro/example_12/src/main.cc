/*
** W. H. Bell
**
** A program to introduce interfaces.
*/

#include <iostream>
#include <cstring>

#include "IDataRecord.h"
#include "BinaryRecord.h"
#include "AsciiRecord.h"

void usage(char *);
void fillRecord(IDataRecord *);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv[0]);
    return 1;
  }

  IDataRecord *dataRecord;
  if(!strcmp(argv[1],"-a")) {
    dataRecord = new AsciiRecord("ascii_file.txt",10);
  }
  else if(!strcmp(argv[1],"-b")) {
    dataRecord = new BinaryRecord("binary_file.bin",10);
  }
  else {
    usage(argv[0]);
    return 1;
  }

  fillRecord(dataRecord);

  delete dataRecord;
}

void usage(char *exename) {
  std::cout << " Usage: " << exename << " <-a/-b>" << std::endl;
  std::cout << " where -a selects an ascii record and -b a binary record" << std::endl;
}

void fillRecord(IDataRecord *record) {
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  record->appendRow(arr);
}
