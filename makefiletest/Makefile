CC= gcc
CFAGS = -W -Wall
TARGET = test_exe
OBJECTS = main.o hi.o bye.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFAGS) -o $@ $^

clean :
	rm *.o test_exe
