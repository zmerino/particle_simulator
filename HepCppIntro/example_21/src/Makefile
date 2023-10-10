# W. H. Bell
# A Makefile to build Wrap.exe

CC=g++
F77=gfortran
TARGET=Wrap
OBJECTS=main.o fortran.o 

# Needed if g77 is used rather than gfortran
#LIBS = -lg2c

# The path to the library is needed on Redhat LINUX
LIBS = -L/usr/lib/gcc/i386-redhat-linux5E/4.1.2/ -lgfortran

#LIBS = -lgfortran

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) $(LIBS) -o $(TARGET).exe

clean:
	@rm -f *.o *~

veryclean: clean
	@rm $(TARGET).exe

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
