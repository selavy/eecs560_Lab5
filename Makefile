CPP = g++
CFLAGS = -Wall -Werror -pedantic -g

ARR = Array.o
TREE = AVLTree.o
OBJS = main.o
ARROBJS = arrmain.o $(ARR)
TREEOBJS = $(OBJS) $(TREE)


Lab5: $(TREEOBJS)
	$(CPP) $(CFLAGS) -o Lab5 $(TREEOBJS)
ArrayLab5: $(ARROBJS)
	$(CPP) $(CFLAGS) -o ArrayLab5 $(ARROBJS) 
arrmain.o: main.cpp
	$(CPP) $(CFLAGS) -DUSEARRAY -c main.cpp -o arrmain.o
main.o: main.cpp
	$(CPP) $(CFLAGS) -c main.cpp
Array.o: Array.hpp Array.cpp
	$(CPP) $(CFLAGS) -c Array.cpp
AVLTree.o: AVLTree.hpp AVLTree.cpp
	$(CPP) $(CFLAGS) -c AVLTree.cpp
.PHONY:clean
clean:
	rm -rf *.o Lab5 ArrayLab5
