/* W. H. Bell
** A program to demonstrate fortran wrappers.
*/

#include <cstdio>
#include <cstring>
#include "fortran.h"

void fillCommon(void);

int main() {
  // Fill common block FORCOM
  fillCommon();

  // Print values contained in common block
  commons_();

  // Call the fortran function CALL_BACK(A,NAME)
  float a=3.14159;
  char name[]="Wrapper";
  int size=sizeof(name)/sizeof(char);
  call_back_(&a,name,size);

  return 0;
}

void fillCommon(void) {
  for(int i=1;i<=2;i++) {
    for(int j=1;j<=3;j++) {
      forcom_.intarray[i-1][j-1] = i+j*10;
      forcom_.realarray[j-1][i-1] = j+(float)i*0.001;
    }
  }
  sprintf(forcom_.somestring,"C++ string");
}

// Provided for the fortran function CALL_BACK to call.
float mult_a_(float *a) {
  return (*a)*10.;
}
