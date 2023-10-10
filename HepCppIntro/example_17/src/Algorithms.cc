/* W. H. Bell
** A program to demonstrate basic algorithms.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int>, char []);

int main() {
  int numberList[] = {1,4,2,5,7,2,5,4,9,4,2,7,8,0};
  std::vector<int> numbers(numberList,numberList+sizeof(numberList)/sizeof(int));
  std::vector<int>::iterator first;
  std::vector<int>::iterator last;

  printVector(numbers,"numbers");

  first = numbers.begin();
  last = numbers.end();
  std::sort(first,last);
  
  printVector(numbers,"numbers");

  return 0;
}

void printVector(std::vector<int> vec, char name[]) {
  std::vector<int>::iterator itr;

  std::cout << name <<"={";
  for(itr=vec.begin();itr != vec.end(); itr++) {
    std::cout << *itr;
    if((itr+1) != vec.end()) std::cout << ",";
  }
  std::cout << "}" << std::endl;
}  
