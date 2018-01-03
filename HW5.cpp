//Shivani Singh
//Referenced: https://www.programmingalgorithms.com/
//Referenced: https://www.programmingalgorithms.com/algorithm/fnv-hash
//Referenced: https://en.wikipedia.org/wiki/List_of_hash_functions#Non-cryptographic_hash_functions
#include "MyBloomFilter.h"
#include <vector>
#include <string>

#include <iostream>
using namespace std;

int my_hash(string my_string, int this_length);

void MyBloomFilter::insert(string item)
{
    int this_length = x.size();
    int place = my_hash(item, this_length);
    //for(int i=0;i<this_length;i++)
    //x[i];
    x[place] = 1;
}

bool MyBloomFilter::exists(string item)
{
    int this_length = x.size();
    int place = my_hash(item, this_length);

    if (x[place]!= 1)
      return false;

    else
      return true;
}


string MyBloomFilter::output(void)
{
    string output;
    //for (int i = 0; i < this_length; i++)
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i]!= 1)
          output.push_back('0');

        else
          output.push_back('1');
    }
    return output;
}

MyBloomFilter::MyBloomFilter(int this_length):BloomFilter(this_length)
{
    for (int i = 0; i < this_length; i++)
        x.push_back(0);
}

int my_hash(string my_string, int this_length)
{
    const unsigned int prime = 0x811C9DC5;
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int c = my_string.length();

    for (i = 0; i < c; i++)
    {
        hash = hash * prime;
        hash ^= (my_string[i]);
    }
    //return hash;
    return hash % this_length;
}



/*int hash_one(string first, int x)
{
  int hash = 0;

  for(int i = 0; i < first.this_length(); i++)
    hash = hash + first[i];

  return hash % x;

}

int hash_two(string first, int x)
{
  int hash = 3;

  for(int i = 0; i < first.this_length(); i++)
  {
    int here = first[i];
 		hash = ((hash << 5) + hash) ^ first;
  }

  return hash % x;
}

bloom_one::bloom_one(int len):BloomFilter(len);
//bloom_one::bloom_one(string):BloomFilter(item);
//void myBloom::insert(string item)

bool bloom_one::exists(string item)
{

}
*/
