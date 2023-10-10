Before building this example a recent version of ROOT must be installed.
The simplest way to install ROOT is to download a binary version from
http://root.cern.ch/.  If no binary version exists then a recent
version can be installed by

cd ../support/install-scripts/
./build-ROOT.sh

(Note the example assumes ROOT has been built as a 32 bit library)

Then setup the environment by adding

if [[ -z $ROOTSYS ]]; then
  export ROOTSYS=path_from_script

  export PATH=$ROOTSYS/bin:$PATH
  export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
  export DYLD_LIBRARY_PATH=$ROOTSYS/lib:$DYLD_LIBRARY_PATH
  export MANPATH=$ROOTSYS/man
fi

to ~/.bashrc and opening a new shell window, where path_from_script is
printed at the end of the build-ROOT.sh script and the DYLD_LIBRARY_PATH
line is only needed for OSX.

