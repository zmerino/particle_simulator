
CC=g++
TARGET=encoder
OBJECTS=solution_02.o cryptography.o

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "**"
	@echo "** execute ./encoder private_message.txt -e"
	./encoder private_message.txt -e

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET)

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 