//Shivani Singh
//In Collaboration with Boxi Huang
//Reference cplusplus.com, stackoverflow, various googling
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "Problem3.h"
using namespace std;

void MaxIncSeq(int *nums, int len)
{//const size_t len = sizeof(myVector) / sizeof(myVector[0]);
  //int maxLength;
  //int arr_1[50];
  //int a = (-1);
  vector<int> myVector[len];//initializing vector
  myVector[0].push_back(nums[0]);//adds elements to vector

  for(int i = 1; i < len; i++)//starts with 2nd element
  {
    for(int j = 0; j <= i-1; j++)//onwards until reaches second to last element (i-1)
    {
      if(nums[i] > nums[j] && myVector[i].size() < myVector[j].size())
        myVector[i] = myVector[j];//finds/assigns max/long sequence
        //cout<<"Hello";
        //reverse(myVector.begin(), myVector.end());
    }
      myVector[i].push_back(nums[i]);//adds number to end of vector
  }

  int j = 0;
  for (int i = 0; i < len; i++)
  {
  //cout<<"Hello";
  //int i=0;
    if(myVector[i].size() > myVector[j].size())

    //cout<<"Hello";
    j = i;
  //cout <<j;
  //cout << i << " ";

//for (int i: myVector[j])
//cout << i << " "; <===== The cout statement in here was giving me multiple prints of the array
  }
//  myVector[0].begin();

  for (vector<int>::const_iterator i = myVector[len-1].begin(); i != myVector[len-1].end(); ++i)
    cout << *i << ' ';
}

/*int main()
{
  //vector <int> myVector;
  int myArray[] = {1, 5, 3, 2, 4, 6, 12, 2, 4, 37}; //input-ed array
  const size_t len = sizeof(myArray) / sizeof(myArray[0]); //size of array
  MaxIncSeq(myArray, len);

}*/
