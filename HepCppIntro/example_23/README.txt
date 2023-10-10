First read README-ROOT.txt.  The executable can be built by typing:

cd src/; make

The program can be run by typing

./Histograms.exe

The program then writes one histogram to the file name specified.  To view 
the histogram open a Root prompt by typing root at the command line.  Then 
open a new TBrowser by typing

new TBrowser();

at the root prompt.  Then double click on the filename.root created.
This will load the root file into the root environment.  Select the
"ROOT Files" folder and double click on filename.root.  Double click
on histo;1.
