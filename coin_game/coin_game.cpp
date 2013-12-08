#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
//#include <algorithm>
using namespace std;

long long solver(long long, long long, long long);

int main(int argc, char* argv[])
{
  string line;
  int case_no = 0;
  int t;
  long long n, c, k;
  
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
	      s >> c;
	      cout<<"jars: "<<n<<'\t'<<"coins: "<<k<<'\t'<<"c: "<<c<<endl;
	      out<<"Case #"<<case_no<<": "<<solver(n, k, c)<<endl;
	      case_no++;
	    }
	}
    }
  return 0;
}
/**
 * n = number of jars
 * k = number of coins
 * c = number of coins to win
*/
long long solver(long long n, long long k, long long c)
{
  long long sol, ram, can1, can2, i;
  // when c is small we can put each jar k/n 
  // when k%n=0, we know how many coins a jar contains
  // in both case we can get c coins, by c attempts.
  if(c <= (k/n)*n || k%n == 0)
    sol = c;
  // if c > (k/n)*n, that means the first (k/n)*n we can get by
  // getting k/n coins from one jar
  // then there are ram coins left(ram < n)
  // if we put 
  else
    {
      for(i=n;i>0;i--)
	{
	  if(k%i == 0)
	    {
	      can1 = c + n - i;
	      break;
	    }
	}
      
      ram = k - (k/n)*n;
      //can = c + n - ram;
      for(i=n;i>0;i--)
	{
	  if(ram % i==0)
	    {
	      can2 = c + n-i;
	      cout <<"ram: "<< ram << endl;
	      cout <<"i: "<< i << endl;
	      break;
	    }
	}
      if(can2 < can1)
	sol = can2;
      else
	sol = can1;
    }
  return sol;
}

