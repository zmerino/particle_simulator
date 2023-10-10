/* W. H. Bell
** A program to demonstrate the usage of an iterator with the list class.
*/

#include <iostream>
#include <list>

using namespace std;

int main() {
  char interatorsString[] = "Iterators";
  list<char> charList;

  for(int i=0;i<strlen(interatorsString);i++) {
    charList.push_back(interatorsString[i]);
  }

  // Declare list iterator 
  list<char>::iterator itr;

  // returns a bidirectional iterator that points at the first element
  // of the sequence
  itr = charList.begin();
  
  // Print out the contents of the linked list using the iterator
  cout << endl;
  while (itr != charList.end()) {
    cout << *itr << " ";
    itr++;
  }
  cout << endl;

  return 0;
}
