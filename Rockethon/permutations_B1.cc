#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M, i;
	scanf("%d%d", &N, &M);
	//printf("%d %d\n", N, M);
	vector<int> nums;
	nums.reserve(N);
	for (i = 1; i <= N; i++)
		nums.push_back(i);
	for (i = 0; i < M-1; i++) 
		next_permutation(nums.begin(), nums.end());
	for (i = 0; i < N - 1; i++)
		printf("%d ", nums[i]);
	printf("%d", nums[i]);
	return 0;
}