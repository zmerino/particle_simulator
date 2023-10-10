# W. H. Bell
# A Makefile to build Histogram

CC=g++
C=gcc
TARGET=Histogram
OBJECTS=main.o Histogram.o random_dist.o

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

%.o: %.c
	@echo "**"
	@echo "** Compiling C Source" 
	@echo "**"
	$(C) -c $(INCFLAGS) $<
