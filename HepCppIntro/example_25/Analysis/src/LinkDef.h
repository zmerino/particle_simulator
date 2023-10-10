/**
 * W. H. Bell
 *
 * A list of classes Root does not understand by default and have to
 * incorporated into a dictionary.
 */
#include <vector>
#ifdef __MAKECINT__
#pragma extra_include "vector";
#pragma link C++ class std::vector<long>+;
#pragma link C++ class std::vector<float>+;

#endif
