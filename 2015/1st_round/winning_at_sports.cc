#include <cstdio>
//#include <climits>
#include <cstring>
#include <cmath>
using namespace std;
// dp our_score opp_score [0] ways of stress free win
//                         [1] ways of stressful win
//#define 0x3fffffff INF;
long long dp[2001][2001][2];
bool visited[2001][2001][2];

long long StressFree(int our_score, int opp_score) {
	//printf("%d-%d: ", our_score, opp_score);
	if (our_score <= opp_score ) {
		//printf("%d\n", 0); 
		return 0;
	}
	if (visited[our_score][opp_score][0]) {
		//printf("%lld\n", dp[our_score][opp_score][0]); 
		return dp[our_score][opp_score][0];
	}
	if (our_score <= opp_score ) {
		//printf("%d\n", 0); 
		return 0;
	}
	dp[our_score][opp_score][0] = (StressFree(our_score - 1, opp_score) + StressFree(our_score, opp_score - 1)) % 1000000007;
	visited[our_score][opp_score][0] = true;
	//printf("%lld\n", dp[our_score][opp_score][0]); 
	return dp[our_score][opp_score][0];
}

long long Stressful(int our_score, int opp_score, int final_score) {
	//printf("%d-%d: ", our_score, opp_score);
	if (opp_score == 0 && final_score == 0)
		return 1;
	if (opp_score != final_score && our_score > opp_score) {
		//printf("%d\n", 0);
		return 0;
	}
	if (visited[our_score][opp_score][1]) {
		//printf("%lld\n", dp[our_score][opp_score][1]); 
		return dp[our_score][opp_score][1];
	}
	dp[our_score][opp_score][1] = (Stressful(our_score - 1, opp_score, final_score) + Stressful(our_score, opp_score - 1, final_score)) % 1000000007;
	visited[our_score][opp_score][1] = true;
	//printf("%lld\n", dp[our_score][opp_score][1]); 
	return dp[our_score][opp_score][1];
}

// long solve(int our_score, int opp_score, long &free_ways, long& ful_ways) {
// 	int i, j;
// 	for (i = 1; i <= our_score; i++) {
// 		for (j = 0; j <= opp_score; j++) {

// 		}
// 	}
// }

int main() {
	int T, i;
	scanf("%d", &T);
	int our_score, opp_score;
	memset(dp, 0, sizeof dp);
	memset(visited, false, sizeof visited);
	visited[0][0][0] = visited[0][0][1] = true;
	dp[0][0][1] = 1;
	for (i = 1; i < 2001; i++) {
		dp[i][0][0] = dp[0][i][1] = 1;
		visited[i][0][0] = visited[i][0][1] = visited[0][i][0] = visited[0][i][1] = true;
	}
	for (i = 1; i <= T; i++) {
		scanf("%d-%d", &our_score, &opp_score);
		//printf("%d %d\n", our_score, opp_score);
		long long num_free, num_ful;
		//StressFree(our_score, opp_score);
		//printf("%lld\n", dp[11][10][0]);
		num_free = StressFree(our_score, opp_score);
		num_ful = Stressful(our_score, opp_score, opp_score);
		printf("Case #%d: %lld %lld\n", i, num_free, num_ful);
	}
}