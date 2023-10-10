# W. H. Bell
# A Makefile to build PythiaBmesons.exe

CC=g++
TARGET = PythiaBmesons
OBJECTS = RootDictionary.o BmesonGenerator.o HepevtTree.o main.o

# Assuming the version of ROOT was build in 32 bit mode.
INCFLAGS=-m32 -I$(shell root-config --incdir) -O
ROOTLIBS = $(shell root-config --libs) 

LIBS=-m32 $(ROOTLIBS) -ldl

SUPPORT_DIR=../../support

# Set PYTHIA_DIR by hand to use a version other than the one build in the
# support directory.
PYTHIA_DIR=$(SUPPORT_DIR)
INCFLAGS += -I$(PYTHIA_DIR)/include
# Lib path for gfortran is needed on Redhat LINUX
LIBS += -L/usr/lib/gcc/i386-redhat-linux5E/4.1.2/
LIBS += -L$(PYTHIA_DIR)/lib -lpythia -lgfortran

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

RootDictionary.cxx: LinkDef.h
	@echo "**"
	@echo "** Creating Root dictionary"
	@echo "**"
	rootcint -f RootDictionary.cxx -c $<

RootDictionary.o: RootDictionary.cxx
	@echo "**"
	@echo "** Compiling C++ Source"
	@echo "**"
	$(CC) -c $(INCFLAGS) RootDictionary.cxx
