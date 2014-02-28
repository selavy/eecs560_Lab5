CPP = g++
CFLAGS = -Wall -Werror -pedantic -g

OBJS = main.o Array.o AVLTree.o

Lab5: $(OBJS)
	$(CPP) $(CFLAGS) -o Lab5 $(OBJS)
main.o: main.cpp
	$(CPP) $(CFLAGS) -c main.cpp
Array.o: Array.hpp Array.cpp
	$(CPP) $(CFLAGS) -c Array.cpp
AVLTree.o: AVLTree.hpp AVLTree.cpp
	$(CPP) $(CFLAGS) -c AVLTree.cpp
.PHONY:clean
clean:
	rm -rf *.o Lab5
