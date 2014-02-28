#include <iostream>
#include <fstream>
//#include "Array.hpp"
#include "AVLTree.hpp"

using namespace std;

int main(int argc, char **argv) {
  //Array arr;
  AVLTree arr;
  ifstream in;

  if (argc == 2) {
    in.open (argv[1]);
  } else {
    in.open ("input.txt");
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
  } 

  arr.print ();
  cout << endl;
  /*
  arr.remove ("III");
  arr.remove ("Lawrence");
  arr.remove (400, 200);
  arr.print ();
  cout << endl;
  */
  in.close();
  return 0;
}
