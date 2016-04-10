#include <cstdio>

int main() {
	int N1, N2, K1, K2;
	scanf("%d%d%d%d", &N1, &N2, &K1, &K2);
	if (N1 > N2)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}