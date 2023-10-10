First read README-ROOT.txt.

Build the Ntuple creation code.

cd TruthNtuple/src/; make

Then link to a version of particle.tbl

ln -s ../../../support/data/particle.tbl

Run the Ntuple creation code to generate 5000 inelastic non-diffractive events
with the PYTHIA event generator. 

./PythiaTree.exe

Then build the analysis code.

cd ../../Analysis/src/; make

Run the analysis code.

./Analysis.exe 

Refer to the course guide for more information.
