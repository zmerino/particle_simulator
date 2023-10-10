/* W. H. Bell
** A program to introduce the Standard Template Library through the
** use of the vector class.
*/

#include <iostream>
#include <vector>
#define NUM 7

int main() {
  std::vector<int> intVector;

  std::cout << " Building Vector..." << std::endl;
  std::cout << "  >> vector size=" << intVector.size() << std::endl;
  for(int i=0;i<NUM;i++) {
    intVector.push_back(i);
    std::cout << "  >> vector size=" << intVector.size() << std::endl;
  }
  std::cout << std::endl;

  std::cout << " Popping Vector..." << std::endl;
  do {
    std::cout << "  >> Popping element with value=" 
              << intVector.back() << std::endl;
    intVector.pop_back();
  } while(!intVector.empty());

  return 0;
}
