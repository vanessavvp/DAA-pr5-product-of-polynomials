OBJECTS = main.o monomial.o polynomial.o classicMultiply.o dycMultiply.o multiplyStrategy.o
CFLAGS = -c -O3 -std=c++17 -I../include

exe: $(OBJECTS)
	g++  $(OBJECTS) -o exe
	mv *.o ../obj
	

main.o:
	g++ $(CFLAGS) ../src/main.cc

monomial.o:
	g++ $(CFLAGS) ../src/monomial.cc

polynomial.o:
	g++ $(CFLAGS) ../src/polynomial.cc

classicMultiply.o:
	g++ $(CFLAGS) ../src/classicMultiply.cc

dycMultiply.o:
	g++ $(CFLAGS) ../src/dycMultiply.cc

multiplyStrategy.o:
	g++ $(CFLAGS) ../src/multiplyStrategy.cc

.PHONY: clean

clean:
	rm -rf ../obj/*.o
	rm -rf ../bin/*
