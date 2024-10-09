CC=g++
CFLAGS=-g -Wall -std=c++11
OBJS=ppm_example.o
TARGET=make_picture.exe

$(TARGET): $(OBJS) 
		$(CC) $(OBJS) -o $(TARGET)

ppm_example.o: ppm_example.cpp
		$(CC) $(CFLAGS) -c ppm_example.cpp

clean:
	rm -f *.o $(TARGET) image.ppm