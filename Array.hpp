#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include "City.hpp"
#include <cstdlib>
#include <iostream>

#define INIT_SIZE 120

class Array {
public:
  explicit Array(int size = INIT_SIZE);
  virtual ~Array();

  void insert(const City& coord);
  void remove(const std::string& name);
  void remove(int x, int y);
  void print() const;

private:
  int _size;
  int _curr;
  City * _arr;
};

#endif
