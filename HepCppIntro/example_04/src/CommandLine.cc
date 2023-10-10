/* W. H. Bell
** A very simple C++ program to read arguments from the command line
** and print them.
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "argc=" << argc << " (argc => size of argv array)" << endl;
  for(int i=0;i<argc;i++) {
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }
  return 0;
}
