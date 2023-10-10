First read README-ROOT.txt.  The executable can be built by typing:

cd src/; make

The program can be run by typing

./Trees.exe

The program can be used to write or read a TTree.  In macros/ there is a ROOT
macro which can be used to plot data stored in the TTree via

root
.x ../macros/plot.C("plot.ps");

Refer to the course guide for more information.
