/* W. H. Bell
**
** A program to demonstrate the use of operator overloading using an array 
** container class.
**
*/

#include <iostream>
#include "DataContainer.h"

using namespace std;

int main() {
  DATA_TYPE numbers1[] = {1,2,3,4,5,6,7,8,9,10};
  DATA_TYPE numbers2[] = {10,9,8,7,6,5,4,3,2,1};

  DataContainer *dataContainer1 = new DataContainer(numbers1,10);
  DataContainer *dataContainer2 = new DataContainer(numbers2,10);

  dataContainer1->printArray();
  dataContainer2->printArray();

  cout << ">> Multiplication:" << endl;
  (*dataContainer1 * (*dataContainer2)).printArray();

  cout << ">> Addition:" << endl;
  (*dataContainer1 + (*dataContainer2)).printArray();
  
  cout << ">> Division:" << endl;
  (*dataContainer1 / (*dataContainer2)).printArray();

  delete dataContainer1;
  delete dataContainer2;

  return 0;
}
