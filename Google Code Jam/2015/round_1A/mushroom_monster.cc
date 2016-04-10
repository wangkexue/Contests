#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int method1(int N, int *nums) {
	int i;
	int count = 0;
	for ( i = 0; i < N - 1; i++ ) {
		if (nums[i] > nums[i+1])
			count += nums[i] - nums[i+1];
	}
	return count;
}

int method2(int N, int *nums) {
	int i;
	int Max = 0;
	int count = 0;
	for ( i = 0; i < N - 1; i++ ) {
		Max = max(Max, nums[i] - nums[i+1]);
	}
	//printf("%d\n", Max);
	for ( i = 0; i < N - 1; i++ ) {
		if (nums[i] > Max)
			count += Max;
		else
			count += nums[i];
	}
	return count;
}

int main() {
	int T, N;
	int i, j;
	int x, y;
	scanf("%d", &T);
	for ( i = 1; i <= T; i++ ) {
		scanf("%d", &N);
		int nums[N];
		for (j = 0; j < N; j++)
			scanf("%d", &nums[j]);
		x = method1(N, nums);
		y = method2(N, nums);
		printf("Case #%d: %d %d\n", i, x, y);
	}
}