#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
//#include <algorithm>
using namespace std;

int solver(int, int, int*);
int getsum(int*, int);
int getGCD(int, int);

int main(int argc, char* argv[])
{
  string line;
  int case_no = 0;
  int t;
  // n rows, m cols
  int n, k, i;
  int* childs;
  
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
	      s >> n;
	      s >> k;
	      childs = new int[n];
	      getline(in, line);
	      stringstream str(line);
	      for(i=0;i<n;i++)
		{
		  str >> childs[i];
		}
	      //cout<<char_l<<'\t'<<n<<endl;
	      out<<"Case #"<<case_no<<": "<<solver(n, k, childs)<<endl;
	      case_no++;
	    }
	}
    }
  return 0;
}

int solver(int n, int k, int* childs)
{
  int sol;
  /**
   */
  int old_sum = getsum(childs, n);
  int i, j, ii;
  for(i=0;i<n;i++)
    {
      while(childs[i]%k != 0)
	{
	  childs[i]++;
	}
    }
  for(i=0;i<n;i++)
    {
      //bool flag = true;
      while(1)
	{
	  int mem = childs[i];
	  for(j=0;j<i;j++)
	    {
	      if(childs[i]==0 && childs[j]==0)
		{  
		  childs[i] += k;
		  continue;
		}
	      else if(childs[i]==0 || childs[j]==0)
		continue;

	      while(getGCD(childs[i], childs[j]) > k)
		childs[i] += k;
	    }
	  if(childs[i] == mem)
	    break;
	}
    }
  sol = getsum(childs, n) - old_sum;
  return sol;
}

int getsum(int* childs, int n)
{
  int i;
  int sum = 0;
  for(i=0;i<n;i++)
    sum += childs[i];
  return sum;
}

int getGCD(int a, int b)
{
  if(a > b){
    if(a % b == 0){
      return b;
    }
    else{
      b = a % b;
      getGCD(a, b);
    }
  }
  else{
    if(b % a == 0){
      return a;
    }
    else{
      a = b % a;
      getGCD(a, b);
    }
  }
}

