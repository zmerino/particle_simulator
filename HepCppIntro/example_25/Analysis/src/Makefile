# W. H. Bell
# A Makefile to build Analysis.exe

CC=g++
TARGET=Analysis
OBJECTS=Tree_base.o Tree_McTruth.o RootDictionary.o main.o

# Assuming the version of ROOT was build in 32 bit mode.
INCFLAGS=-m32 -I$(shell root-config --incdir) -O
ROOTLIBS = $(shell root-config --libs) 

LIBS=-m32 $(ROOTLIBS) -ldl


$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) $(LIBS) -o $(TARGET).exe

clean:
	@rm -f *.o *~ RootDictionary.cxx RootDictionary.h

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

