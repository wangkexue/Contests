#include <cstdio>
//using std::scanf;
//using std::printf;

int main() {
  int n, i, j, count;
  scanf("%d\n", &n);
  if (n < 5) {
    printf("no");
    return 0;
  }
  char* level = new char[n];
  for (i = 0; i < n; i++)
    scanf("%c", &level[i]);
  for (i = 0; i < n - 4; i++)
    for (j = 1; j <=  n / 4; j++) {
      count = 0;
      int tmp = i;
      while(tmp < n && level[tmp] == '*') {
        count++;
	tmp += j;
        if (count > 4) {
	   printf("yes");
	   return 0;
	}
      }
      if (count > 4) {
	printf("yes");
	return 0;
      }
    }
  printf("no");
  delete[] level;
  return 0;
}
