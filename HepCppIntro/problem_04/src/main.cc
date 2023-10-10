/* W. H. Bell
**
** A program to histogram data and save the data in a format suitable for 
** plotting with gnuplot.
*/
extern "C" {
  #include "random_dist.h"
}
#include "Histogram.h"

int main() {
  
  // Create a histogram
  Histogram flat("data.hst", 30, -6.0, 6.0);

  for(int i=0;i<1000;i++) {
    // Add an entry to the histogram
    flat.book(random_dist_gaus(2.0),1.0);
  }

  // Save the contents of the histogram to a file.
  flat.saveHisto();
  
  return 0;
}
