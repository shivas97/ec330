//Shivani Singh
//Collaborated with Boxi Huang
//With help of cplusplus.com, stackoverflow,https://www.daniweb.com
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 1)
    return 0; //empty file

  //if (argc > 1) //if file is not empty

  ifstream hwFile(argv[1]); // open file
  if (hwFile.is_open())
  {
    //string lineOne;
    string line = "";
    string result = "";
    int totalLength = 0;
    //string previousLine;

    while(getline(hwFile, line))
      {
        //while(!hwFile.eof( )) //for (int i=0; i<argc; i++)

            /*if (lineOne.size > line.size)
              longestLine = lineOne;
            else
              longestLine = line;
            else if (line.size > previousLine.size)*/
            if (line.length() > totalLength)
              {
                totalLength = line.length();
                result = line;
              }
        }
        hwFile.close();
        cout << result << endl;
    }

  return 0;
}
