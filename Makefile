lab5 : HugeInt.o lab5.o
	g++ -o HugeInt HugeInt.o lab5.o
lab5.o:lab5.cpp HugeInt.h
	g++ -c lab5.cpp
HugeInt.o:HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp
clean:
	rm HugeInt*.o
	rm lab5*.o
