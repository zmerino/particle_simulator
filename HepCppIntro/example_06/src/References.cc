/* W. H. Bell
** This simple program demonstrates the principle of using references
** in C++.
**
** While references allow access to the memory addresses they are not
** as flexible as pointers.  Notice that the syntax of references is
** almost opposite that of pointers.  The address is accessed by using
** the '&'.  The value is accessed by dropping the '&'.
*/

#include <iostream>

using namespace std;

void fun(int, int &);

int main() {
  int nr = 1, r = 1;

  cout << "Before fun(): nr=" << nr << " r=" << r << endl;
  cout << "\t main: Address of r" << &r << endl;
  fun(nr, r);
  cout << "After fun(): nr=" << nr << " r=" << r << endl;
}

void fun(int nr, int &r) {
  nr = 2; // Assigning the value 2 to the local variable nr.

  r = 2;  // Assigning the value 2 to the memory address contained
	  // within the reference

  cout << "\t fun: Address of r" << &r << endl;
}
