#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
//#include <utility>
using namespace std;

int abs(int a) {
	return a < 0 ? -a : a;
}

int main() {
	int N, K, i, j;
	int res = 0;
	int tmp = 0;
	scanf("%d%d", &N, &K);
	int nums[N];
	for (i = 0; i < N; i++) 
		scanf("%d", &nums[i]);
	// dp[i, j, k] = {0-i processed subarray,i-j last subarray, k number of subarray}
	int dp[N][N][K][2];
	memset(dp, 0, sizeof dp);
	for (i = 0; i < N; i++) {

	}	
	printf("%.10f", dp[N-1][N-1][K-1][0]);
}