# W. H. Bell
# A Makefile to build ParticleOper.exe

CC=g++
TARGET=ParticleOper
OBJECTS=main.o BasicParticle.o
INCFLAGS=

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) -o $(TARGET).exe

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET).exe

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 
