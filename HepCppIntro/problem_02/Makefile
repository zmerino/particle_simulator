
CC=g++
TARGET=solution_02
OBJECTS=solution_02.o cryptography.o

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "**"
	@echo "** EXECUTING: ./$(TARGET) private_message.txt -e -m 2 -k "ABC" -s 3"
	@echo "------------------------------------------------"
	./$(TARGET) private_message.txt -e -m 2 -k "ABC" -s 3

clean:
	@rm -f *.o *~
	@rm -f $(TARGET)

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 