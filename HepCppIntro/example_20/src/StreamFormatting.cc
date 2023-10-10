/**
 * W. H. Bell
 *
 * An example of different types of stream formatting statements.
 */

#include <string>
#include <iostream>

int main () {
  int i;
  double d_arr[] = {3., 3.1, 3.14, 3.142, 3.1416, 3.14159};
  double i_arr[] = {1, 12, 123, 1234, 12345, 123456};
  
  // Print out d_arr with precision 5.
  std::cout << "d_arr[] = ";
  std::cout.precision(5);
  for (i=0; i<6; i++) {
    std::cout << d_arr[i] << " ";
  }
  std::cout << std::endl << std::endl;
  
  // Set the precision back to the default of 6.
  std::cout.precision(6);

  // Print the last d_arr element with scientific formatting.
  std::cout << std::scientific << "d_arr[5] = " 
	    << d_arr[5] << std::endl << std::endl ;
  // or
  // std::cout.setf(std::ios_base::scientific,std::ios_base::floatfield);
  // std::cout << "d_arr[5]=" << d_arr[5] << std::endl;

  // Set the formatting back to the default.
  std::cout.unsetf(std::ios_base::scientific);

  // Print out i_arr filling out each number with '0' as necessary.
  std::cout << "i_arr[] = ";
  std::cout.fill('0');
  for (i=0; i<6; i++) {
    std::cout.width(4);  // Affects next cout only
    std::cout << i_arr[i] << " ";
  }
  std::cout << std::endl << std::endl;

  // Print the number 16 out both in decimal and hexadecimal
  std::cout << "Decimal " << 16;
  std::cout.setf(std::ios_base::hex,std::ios_base::basefield);
  std::cout << ", Hexadecimal " << 16 << std::endl;
  std::cout.setf(std::ios_base::dec,std::ios_base::basefield);

  // Add the prefix for the different bases.
  std::cout.setf(std::ios_base::showbase);

  // Print the number 16 out both in decimal and hexadecimal
  std::cout << "Decimal " << 16;
  std::cout.setf(std::ios_base::hex,std::ios_base::basefield);
  std::cout << ", Hexadecimal " << 16 << std::endl;
  std::cout.setf(std::ios_base::dec,std::ios_base::basefield);

  return 0;
}


