#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
//#include <cmath>
using namespace std;

string solver(long long, string);

int main(int argc, char* argv[])
{
  string line, char_l;
  int case_no = 0;
  int t;
  long long n;
  
  ifstream in(argv[1]);
  ofstream out("out.txt");
  if(in.is_open())
    {
      while(getline(in, line))
	{
	  if(case_no==0)
	    {
	      t = atoi(line.c_str());
	      cout << t << endl;
	      case_no++;
	    }
	  else if(case_no > t)
	    break;
	  else
	    {
	      stringstream s(line);
	      s >> char_l;
	      s >> n;
	      //cout<<char_l<<'\t'<<n<<endl;
	      out<<"Case #"<<case_no<<": "<<solver(n, char_l)<<endl;
	      case_no++;
	    }
	}
    }
  return 0;
}

string solver(long long n, string char_l)
{
  string sol;
  long long ram = n;
  int len = char_l.length();
  long long k = len;
  long long num;
  //cout << len << endl;
  //cout << n << endl;
  int sol_len;
  int i, pos;
  //char cur;
  /* 
 for(i=1;;i++)
    {
      ram -= k;
      if(ram <= 0)
	{
	  sol_len = i;
	  break;
	}
      k *= len;
    }
  */
  ram = n;
  //k = len;
  while(ram)
    {
      num = ram % len;
      if(num==0)
	num = len;
      //cout << char_l.at(num);
      sol.push_back(char_l.at(num-1));
      //sol.insert(0, 1, char_l.at(num-1));
      ram = (ram-num) / len;
      //k *= len;
    }
  //cout << endl;
  //cout << "sol_len: "<< sol_len << endl;
  reverse(sol.begin(), sol.end());
  return sol;
}

