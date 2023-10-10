This file can be built into an executable by typing:

cd src/; make

The executable can then be run by typing

./Array.exe

-----------------------------------------------------------------------

Explicit template definitions are used to be robust against compiler 
specifics.  Refer to the gnu documentation for more information:

http://gcc.gnu.org/onlinedocs/gcc-3.2.3/gcc/Template-Instantiation.html
http://gcc.gnu.org/onlinedocs/gcc-4.0.4/gcc/Template-Instantiation.html
http://gcc.gnu.org/onlinedocs/gcc-4.4.0/gcc/Template-Instantiation.html

where gcc-4.4.0 is the compiler version.
