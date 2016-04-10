#include <set>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// failed in case 1122
long join(vector<int> nums, vector<int> &idx) {
	int i;
	for (i = 0; i < nums.size(); i++) {
		if (idx[i] != i && nums[i] != nums[idx[i]]) {
			swap(nums[i], nums[idx[i]]);
			break;
		}
	}
	
	long r = 0;
	long base = 1;
	for (i = nums.size() - 1; i >= 0; i--, base *= 10) {
		r += nums[i] * base;
	}
	
	return r;
}

void solve(long &mini, long &maxi) {
	long n;
	scanf("%ld", &n);
	long tmp = n;
	if (n == 0)  {
		mini = maxi = 0;
		return;
	}
	// convert num to list
	vector<int> nums;
	nums.reserve(10);
	set<int> digits;
	while (n) {
		int d = n % 10;
		nums.insert(nums.begin(), d);
		digits.insert(d);
		n /= 10;
	}
	// simply check cases: 9999 or 1
	if (digits.size() == 1) {
		mini = maxi = tmp;
		return;
	}
	// dp
	vector<int> minIdx(nums.size());
	vector<int> maxIdx(nums.size());
	int minD, maxD;
	minD = 10, maxD = 0;
	int min_idx, max_idx;
	min_idx = max_idx = 10;
	int i;
	for (i = nums.size() - 1; i >= 0; i--) {
		if (nums[i] > maxD) {
			maxD = nums[i];
			max_idx = i;
		}
		if (nums[i] < minD) {
			minD = nums[i];
			min_idx = i;
		}
		minIdx[i] = min_idx;
		maxIdx[i] = max_idx;
	}
	// avoid 901 -> 091
	// note! 109 -> 109
	minD = 10;
	if (nums[minIdx[0]] == 0) {
		for (i = 0; i < nums.size(); i++) {
			if (nums[i] <= minD && nums[i] != 0) {
				minD = nums[i];
				minIdx[0] = i;
			}
		}
	}
	// create mini
	if (nums[minIdx[0]] == 0)
		mini = tmp;
	else 
		mini = join(nums, minIdx);
	// create maxi
	maxi = join(nums, maxIdx);	
}



int main() {
	int t;
	scanf("%d", &t);
	int i;
	long mini, maxi;
	for(i = 1; i <= t; i++) {
		solve(mini, maxi);
		printf("Case #%d: %ld %ld\n", i, mini, maxi);
	}
}