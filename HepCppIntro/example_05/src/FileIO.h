/* W. H. Bell
** A header file demonstrating preprocessor directives and predefining
** FileIO functions.
*/ 

#ifndef FILEIO_H
#define FILEIO_H

/** A function to write an ascii file containing integers */
void fileWrite(char *filename);

/** A function to read an ascii file containing integers */
void fileRead(char *filename);

#endif
