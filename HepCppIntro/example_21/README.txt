This file can be built into an executable by typing:

cd src/; make

The executable can then be run by typing

./Wrap.exe

-----------------------------------------------------------------------

This example has been tested with gfortran on OSX and LINUX.  The 
example can be made to work with g77 and an older version of g++.  The 
crucial part to making the example work is that the generated symbols in 
main.o must match those in fortran.o.  The symbols can be checked by 
using the nm command.  Refer to the nm manual page for more details.

