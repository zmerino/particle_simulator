/* W. H. Bell
** A program to write and read a file.  The file name is specified at 
** the command line.  The program can either be used to write or read 
** the output file.
*/

#include "FileIO.h"
#include <iostream>
#include <cstring>

using namespace std;

void usage(char *);

int main(int argc, char *argv[]) {
  char ioFlag[50];

  if(argc < 2 || argc > 3) {
    usage(argv[0]);
    return 0;
  }
  else if(argc==2) {
    strcpy(ioFlag, "-w");
  }
  else {
    strcpy(ioFlag, argv[2]);
  }
  
  if(!strcmp(ioFlag,"-w")) {
    cout << "Writing new file named " << argv[1] << endl;
    fileWrite(argv[1]);
  }
  else if(!strcmp(ioFlag,"-r")) {
    cout << "Reading from file named " << argv[1] << endl;
    fileRead(argv[1]);
  }
  else {
    cout << "Error: unknown file ioFlag \'" << ioFlag << "\'" << endl;
    usage(argv[0]);
  }

  return 0;
} 

void usage(char *exename) {
  cout << "Usage: " << exename << " <file name> [<file io flag>]" << endl;
  cout << " where <file io flag> = -w (write) or -r (read)." << endl;
}
