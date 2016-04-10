#include <cstdio>
#include <cstring>

const int MAXLEN = 1e7 + 1;
int g_count[MAXLEN];

void preCompute() {
    int i, j;
    for (i = 2; i <= MAXLEN; i++) 
        if (g_count[i] == 0) 
            for (j = i; j <= MAXLEN; j += i)
                g_count[j]++;
}

int solve(int A, int B, int K) {
	int i;
	int acc = 0;
        for (i = A; i <= B; i++)
            if (g_count[i] == K)
                acc++;
        return acc;
}

int main() {
	int T;
	scanf("%d", &T);
	int result, A, B, K, i;
	memset(g_count, 0, sizeof g_count);
	preCompute();
 	for (i = 1; i <= T; i++) {
		scanf("%d%d%d", &A, &B, &K);
		result = solve(A, B, K);
		printf("Case #%d: %d\n", i, result);
	}
}
