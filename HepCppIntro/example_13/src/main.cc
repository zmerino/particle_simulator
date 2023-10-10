/* W. H. Bell
** An example implementing a simple templated class
*/

#include <iostream>
#include "Array.h"

#define N 10

int main() {
  int i;
  
  Array<int> arrayInt(N);
  Array<double> arrayDouble(N);

  for(i=0;i<N;i++) {
    arrayInt.setElement(i,i);
    arrayDouble.setElement(i,(double)i/N);
  } 

  for(i=0;i<N;i++) {
    std::cout << " arrayInt=" << arrayInt.getElement(i) 
	      << " \t arrayDouble = " << arrayDouble.getElement(i)
	      << std::endl;
  }
  
  return 0;
}
