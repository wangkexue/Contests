#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int sol(int R, int C, int W) {
  return C / W * R + min(C % W, 1) + W - 1;
}

int main() {
	int T, R, C, W;
	int i;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d%d%d", &R, &C, &W);
		printf("Case #%d: %d\n", i, sol(R, C, W));
	}
}
