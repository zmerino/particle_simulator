# W. H. Bell
# A Makefile to build Trees.exe

CC=g++
TARGET=Trees
OBJECTS=Trees.o

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
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET).exe

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 
