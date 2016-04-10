#include <cstdio>

int main() {
  int T, i, SMax, j, count, numFriend, tmp;
  scanf("%d", &T);
  for (i = 1; i <= T; i++) {
    scanf("%d", &SMax);
    count = numFriend = 0;
    for (j = 0; j <= SMax; j++) {
      scanf("%1d", &tmp);
      if (count >= j) 
	count += tmp;
      else {
	numFriend += j - count;
	count = j + tmp;
      }
    }
    printf("Case #%d: %d\n", i, numFriend);
  }
}
