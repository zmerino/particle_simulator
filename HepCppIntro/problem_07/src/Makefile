# W. H. Bell
# A Makefile to build Transform.exe

CC=g++
TARGET=Transform
OBJECTS=main.o RotationTranslation.o OffsetTranslation.o
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
