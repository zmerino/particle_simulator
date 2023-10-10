# W. H. Bell
# A Makefile to build FileIO.exe

CC=g++
TARGET=read
OBJECTS=solution_01.cpp

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "**"
	@echo "** execute ./read particle.dat"
	./read particle.dat

