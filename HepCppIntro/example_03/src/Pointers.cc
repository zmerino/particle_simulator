/* W. H. Bell
** This simple program demonstrates the principle of using pointers in C++
*/

#include <iostream>

using namespace std;

void fun(int, int *);

int main() {
  int np = 1, p = 1;

  cout << "Before fun(): np=" << np << " p=" << p << endl;
  fun(np, &p);
  cout << "After fun(): np=" << np << " p=" << p << endl;

  int v[] = {1,2,3,4};
  int *pv = &v[0];

  cout << endl;
  for(int i=0;i<4;i++) {
    cout << "v[" << i << "]=" << *pv << 
	 "\t &v[" << i << "]=" << pv << endl;
    pv++;
  }
}

void fun(int np, int *p) {
  np = 2;
  *p = 2;
}
