/* W. H. Bell
** An example implementing the complex templated class
*/

#include <iostream>
#include <complex>

int main() {
  std::complex<float> complexFloat(3,4);
  std::complex<double> complexDouble(-1,0);
  
  std::cout << " complexFloat = " << complexFloat << std::endl;
  std::cout << " complexDouble = " << complexDouble << std::endl << std::endl;

  std::cout << " Real part of complexFloat = " << complexFloat.real() 
	    << std::endl;
  std::cout << " Imaginary part of complexFloat = " << complexFloat.imag() 
	    << std::endl;
  std::cout << " Modulus of complexFloat = " << abs(complexFloat) 
	    << std::endl;

  std::cout << " Argument of complexFloat = " << arg(complexFloat)
	    << std::endl << std::endl;

  
  std::cout << " Im(sqrt(complexDouble)) = " 
	    << sqrt(complexDouble).imag() << std::endl << std::endl;

  std::cout << " complexFloat*complexDouble = "
	    << complexFloat*(std::complex<float>)complexDouble << std::endl;
  

  return 0;
}
