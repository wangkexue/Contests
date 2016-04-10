#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
//#include <iostream>
//#include <utility>
using namespace std;

int f(vector<int> per) {
	int i, j;
	int sum = 0;
	int mem[per.size()-1][per.size()-1];
	for (i = 0; i < per.size(); i++) {
		mem[i][i] = per[i];
		sum += mem[i][i];
	}
	for (i = 0; i < per.size(); i++) {
		for (j = i+1; j < per.size(); j++) {
			mem[i][j] = min(mem[i][j-1], per[j]);
			//printf("%d ", mem[i][j]);
			sum += mem[i][j];
		}
	}
	//printf("\n");
	return sum;
}

int fact(int n) {
	int res = 1;
	while (n > 1)
		res *= n--;
	return res;
}

int main() {
	int N, M, i;
	scanf("%d%d", &N, &M);
	//printf("%d %d\n", N, M);
	vector<int> nums;
	nums.reserve(N);
	int maxF = INT_MIN;
	vector<vector<int> > perms;
	for (i = 1; i <= N; i++)
		nums.push_back(i);
	int tmp = f(nums);
	//printf("%d\n", tmp);
	if (tmp == maxF)
		perms.push_back(nums);
	else if (tmp > maxF) {
		maxF = tmp;
		perms.clear();
		perms.push_back(nums);
	}
	for (i = 1; i < fact(N); i++) {
		next_permutation(nums.begin(), nums.end());
		tmp = f(nums);
		//printf("%d\n", tmp);
		if (tmp == maxF)
			perms.push_back(nums);
		else if (tmp > maxF) {
			maxF = tmp;
			perms.clear();
			perms.push_back(nums);
		}
	}
	// printf("%lu\n", perms.size());
	for (i = 0; i < N - 1; i++)
		printf("%d ", perms[M-1][i]);
	printf("%d\n", perms[M-1][i]);
	return 0;
}