#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  string line;
  int line_no = 1;
  int t, n;
  ifstream in(argv[0]);
  ofstream out("out.txt")
  if(in.is_open())
    {
      
      while(getline(in, line))
	{
	  
	}
      in.close();
    }
  else
    cout<< "Can't open the file"<<endl;
  return 0;
}
