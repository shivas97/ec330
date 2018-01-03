#ifndef MYBLOOMFILTER_H
#define MYBLOOMFILTER_H

#include "BloomFilter.h"
#include <cstring>
#include <string>
#include <vector>

class MyBloomFilter:BloomFilter
{
public:
  MyBloomFilter(int len);
  void insert(string item);
  bool exists(string item);
  string output(void);

private:
vector <int> x;
};
#endif
