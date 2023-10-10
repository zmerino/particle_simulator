/* W. H. Bell
**
** A set of C functions to provide random number distributions. */
*/

#ifndef RANDOM_DIST_H
#define RANDOM_DIST_H

/** A function to set the seed of the random number generator */
void set_seed(unsigned int seed);

/** A function to generate one random number within a linear distribution 
** between 0. and 1.0 */
double random_dist_flat(void);

/** A function to generate one random number within a normal distribution 
** of a given sigma.  */
double random_dist_gaus(double sigma);

#endif
