all: libline.so

clean:
	rm -rf *.o *.so

libline.so:
	gcc -fPIC line.c point.c -shared -o libline.so

