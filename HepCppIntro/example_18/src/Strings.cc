/**
 * W. H. Bell
 *
 * An example demonstrating some of the functionality of the string
 * class.
 *
 * The string class is an STL container and can therefore be
 * accessed using iterators too.
 */

#include <string>
#include <iostream>

int main () {
  // Create three strings: two on the stack and one on the heap.
  std::string str1("C++ was written by Bjarne Stroustrup");
  std::string str2("Bjarne works for AT&T");
  std::string *str3 = new std::string();

  // Append ".  " to the end of the first string.
  str1.append(".  ");

  // Append '.' to the end of the second string.
  str2.push_back('.');

  // Assign the first string to the third string.
  *str3 = str1;

  // Append the second string to the third string.
  str3->append(str2);

  // Print out the contents of the three strings.
  std::cout << "str1 = \"" << str1 << "\"" << std::endl;
  std::cout << "str2 = \"" << str2 << "\"" << std::endl;
  std::cout << "str3 = \"" << *str3 << "\"" << std::endl << std::endl;

  // Print the length of each string.
  std::cout << "str1.length() = " << str1.length() << std::endl;
  std::cout << "str2.length() = " << str2.length() << std::endl;
  std::cout << "str3.length() = " << str3->length() << std::endl << std::endl;

  // Find all the positions of "Bjarne" within the third string
  int pos;
  int offset = 0;
  while ((pos = str3->find("Bjarne",offset)) != std::string::npos) {
    std::cout << "Found \"Bjarne\" in str3 at character " << pos << std::endl;
    offset = pos+1; // pos points at the first character of "Bjarne"
  }
  std::cout << std::endl;

  // If the third string does not equal the first string assign the
  // first string to it.
  if(*str3 != str1)
    *str3 = str1;

  // Check if str3 and str1 are equal.
  if(*str3 == str1) 
    std::cout << "str1 and *str3 are now the same." << std::endl << std::endl;

  // Remove the "++" from str3
  str3->erase(1,2);

  // Replace sections of str3
  std::string strtmp("written");
  str3->replace(str3->find(strtmp), strtmp.length(), "developed");
  strtmp.assign("Bjarne Stroustrup");
  str3->replace(str3->find(strtmp), strtmp.length(), "Dennis Ritchie");

  // Print out str3
  std::cout << "str3 = \"" << *str3 << "\"" << std::endl << std::endl;

  // Delete the string that was created on the heap.
  delete str3;

  return 0;
}


