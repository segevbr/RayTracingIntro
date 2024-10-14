CC=g++
CFLAGS=-g -Wall -std=c++11
OBJS=main.o
TARGET=make_picture.exe 
HEADERS=vec3.h color.h ray.h hittable.h sphere.h hittable_list.h rtweekend.h \
		interval.h camera.h

$(TARGET): $(OBJS) 
		$(CC) $(OBJS) -o $(TARGET)

main.o: main.cpp $(HEADERS)
		$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET) image.ppm