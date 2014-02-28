#include "Array.hpp"

Array::Array(int size) : _size(size), _curr(0) {
  _arr = new City[size];
}

Array::~Array() {
  delete [] _arr;
}

void Array::insert(const City& coord) {
  // copy constructor fine?
  _arr[_curr] = coord;
  ++_curr;

  if(_curr >= _size) {
    _size *= 2;
    City * new_arr = new City[_size];
    for(int i=0; i < _curr; ++i) {
      new_arr[i] = _arr[i];
    }
    delete [] _arr;
    _arr = new_arr;
  }
}

void Array::remove(const std::string& name) {
  for(int i=0; i < _curr; ++i) {
    if(_arr[i].name == name) {
      --_curr;
      for(int j=i; j < _curr; ++j) {
	_arr[j] = _arr[j+1];
      }
    }
  }
}

void Array::remove(int x, int y) {
  for(int i=0; i < _curr; ++i) {
    if((_arr[i].x == x) && (_arr[i].y == y)) {
      --_curr;
      for(int j=i; j < _curr; ++j) {
	_arr[j] = _arr[j+1];
      }
    }
  }
}

void Array::print() const {
  for(int i = 0; i < _curr; ++i) {
    std::cout << "(" << _arr[i].x << "," << _arr[i].y << ")" << " ";
  }
}

