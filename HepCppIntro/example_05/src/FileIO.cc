/* W. H. Bell
** Two simple functions to write and read integers from a file.  The
** integers are stored in ascii format.
*/

#include <iostream>
#include <fstream>

using namespace std;

void fileWrite(char *filename) {
  ofstream file(filename);

  for(int i=1;i<=20;i++) {
    file << i;
    if(i%5==0) {
      file << endl;
    }
    else {
      file << " ";
    }
  }
  file.close();
}

void fileRead(char *filename) {
  int i;
  ifstream file(filename);

  if(!file) {
    cerr << "Error: could not open " << filename << endl;
  }
  else {
    cout << "Reading file " << filename << endl;
    while(!file.eof()) {
      file >> i;
      cout << i << " ";
      if(i%5==0) cout << endl;
    }
    file.close();
  }
}
