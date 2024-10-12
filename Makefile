CC=g++
CFLAGS=-g -Wall -std=c++11
OBJS=main.o
TARGET=make_picture.exe 

$(TARGET): $(OBJS) 
		$(CC) $(OBJS) -o $(TARGET)

main.o: main.cpp vec3.h color.h ray.h hittable.h sphere.h hittable_list.h
		$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET) image.ppm