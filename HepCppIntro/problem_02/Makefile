
CC=g++
TARGET=xor_cypher
OBJECTS=xor_cypher.o cryptography.o

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "**"
	@echo "** EXECUTING: ./$(TARGET) private_message.txt -e -m 2 -k "ABC" -s 3"
	@echo "------------------------------------------------"
	# ./$(TARGET) private_message.txt -e -m 2 -k "ABC" -s 3
	#./$(TARGET) --help
	./$(TARGET) --defaults
	# ./$(TARGET) private_message.txt -e -m 2 -k "ABC" -s 3
	# ./$(TARGET) private_message_encrypted.txt -e -m 2 -k "ABC" -s 3
	# ./$(TARGET) private_message.txt

clean:
	@rm -f *.o *~
	@rm -f $(TARGET)

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 