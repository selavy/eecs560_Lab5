#include <iostream>
#include <fstream>

#ifdef USEARRAY
#include "Array.hpp"
#else
#include "AVLTree.hpp"
#endif

using namespace std;

int main(int argc, char **argv) {
#ifdef USEARRAY
  Array arr;
#else
  AVLTree arr;
#endif
  ifstream in;

  if (argc == 2) {
    in.open (argv[1]);
  } else {
    in.open ("input2.txt");
  }

  if (!in.is_open()) {
    cerr << "unable to open input file!" << endl;
    exit (1);
  }

  string name;
  int x;
  int y;
  while( in >> name ) {
    in >> x;
    in >> y;
    
    City city;
    city.name = name;
    city.x = x;
    city.y = y;
    arr.insert(city);
    arr.print(); cout << endl;
  } 


  cout << "Now Deleting....\n\n" << endl;
  cout << "REMOVING A..." << endl;
  arr.remove("A");
  arr.print(); cout << endl;
  cout << "REMOVING B..." << endl;
  arr.remove("B");
  arr.print(); cout << endl;
  cout << "REMOVING C..." << endl;
  arr.remove("C");
  arr.print(); cout << endl;
  cout << "REMOVING D..." << endl;
  arr.remove("D");
  arr.print(); cout << endl;
  cout << "REMOVING E..." << endl;
  arr.remove("E");
  arr.print(); cout << endl;
  in.close();
  return 0;
}
