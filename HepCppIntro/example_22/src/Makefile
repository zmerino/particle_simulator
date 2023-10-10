# W. H. Bell
# A Makefile to build Pi0Decay.exe

CC=g++
F77=gfortran
TARGET=Pi0Decay
OBJECTS=main.o MonteCarlo.o LorentzBoost.o lorentz.o 

# Needed if g77 is used rather than gfortran
#LIBS = -lg2c

# The path to the library is needed on Redhat LINUX
LIBS = -L/usr/lib/gcc/i386-redhat-linux5E/4.1.2/ -lgfortran

#LIBS = -lgfortran

# Support directory.
SUPPORT_DIR=../../support

# Set HEPMC_DIR by hand to use a version other than the one build in the
# support directory.
HEPMC_DIR=$(SUPPORT_DIR)

INCFLAGS=-I$(HEPMC_DIR)/include

LIBS += -L$(HEPMC_DIR)/lib -lHepMC 

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) $(LIBS) -o $(TARGET).exe

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET).exe

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 

%.o: %.for
	@echo "**"
	@echo "** Compiling Fortran Source"
	@echo "**"
	$(F77) -c $(F77_OPTS) $<
