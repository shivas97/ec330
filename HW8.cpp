//Shivani Singh, U93079237
//Resources: geeksforgeeks.org/printing-longest-common-subsequence
#include <iostream>
//#include <string>

using namespace std;

// Given two sequences A and B, finds the longest sequence C such that
// C is a subsequence (not necessarily contiguous) of both A and B
string findMaxSubSeq(string str1, string str2)
{
	// the maximum common subsequence
	//string subseq = "TestSubsequence";

	// TODO: implement your algorithm here
  int one = str1.size();
  int two = str2.size();

  int subseq2[one + 1][two + 2];

  for (int i = 0; i <= one; i++)
  {
    for (int j = 0; j <= two; j++)
    {
      if (i == 0 || j == 0)

        subseq2[i][j] = 0; //first row and column = 0

      else if (str1[i-1] == str2[j-1])

        subseq2[i][j] = subseq2[i-1][j-1]+1;

      else subseq2[i][j] = max(subseq2[i-1][j], subseq2[i][j-1]);
    }
  }

        int marker = subseq2[one][two];

        char val[marker + 1]; //char array that stores string
        val[marker] = '\0';

       // Go from last elem of matrix and store char one by one
        int i = one;
        int j = two;

        while (i > 0 && j > 0)
        {
          if (str1[i-1] == str2[j-1])// If current character are same, then its part of maxsub
          {
            val[marker-1] = str1[i-1];
            i--;
            j--;
            marker--;
          }

          else if (subseq2[i-1][j] > subseq2[i][j-1]) i--;

          else j--;

        }
        string subseq(val);

        return subseq;
}


// (sample) main to test findMaxSubSeq
// The actual test cases may be different, this file is for demonstration of format only
int main(int argc, char const *argv[])
{
	// example sequences A, B
//string a = "dynamic";
//string b = "programming";

	// TODO: add code to read two inputs, a and b, from the command-line,
        //    and remove the above sample sequences
      string a = argv[1];
      string b = argv[2];


	// maximum subsequence in example sequences
	string maxSubSeq = findMaxSubSeq(a,b);

	cout << "Maximum common subsequence for " << a << " and " << b << " : " << maxSubSeq << endl;

	return 0;
}
