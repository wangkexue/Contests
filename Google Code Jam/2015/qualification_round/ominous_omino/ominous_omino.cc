#include <cstdio>
#include <algorithm>
using namespace std;
/**
 true if Gabriel can fill the hole
*/
bool sol(int x, int r, int c) {
  switch (x) {
  	case 1:
  		return true;
  	case 2:
  		return r % 2 == 0 || c % 2 == 0;
  	case 3:
  		return min(r, c) >= 2 && (r % 3 == 0 || c % 3 == 0);
  	case 4:
  		return min(r, c) >= 3 && (r % 4 == 0 || c % 4 == 0);
  	case 5:
  		return min(r, c) >= 4 && (r % 5 == 0 || c % 5 == 0);
  	case 6:
  		return min(r, c) >= 5 && (r % 6 == 0 || c % 6 == 0);
  	//( >= 7)
  	default:
  		return false;
  }
}

int main() {
	int T, X, R, C;
	int i, j;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d %d %d", &X, &R, &C);
		if (sol(X, R, C))
			printf("Case #%d: GABRIEL\n", i);
		else
			printf("Case #%d: RICHARD\n", i);
	}
}