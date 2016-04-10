#include <cstdio>
#include <vector>
#include <algorithm>
//#include <iostream>
//#include <queue>
#include <ctime>
//#include <functional>
using namespace std;

#define MAXN 200002
#define MAXK 18
int DP[MAXN][MAXK];

void dfs(vector<vector<int> > &nodes) {
	vector<int> S;
	S.push_back(1);
	int i, j;
	for(i = 0; i < S.size(); i++) {
		for (int x : nodes[S[i]])
			S.push_back(x);
	}
	int cost;
	for (auto x = S.rbegin(); x != S.rend(); x++) {
		for (i = 0; i < MAXK; i++) {
			DP[*x][i] = INT_MAX;
			for (j = 0; j < MAXK; j++) {
				if (j != i) {
					cost = j + 1;
					for (int y : nodes[*x])
						cost += DP[y][j];
					DP[*x][i] = min(DP[*x][i], cost);
				}
			}
		}
	}
}

int main() {
	int T, N, i, j;
	scanf("%d", &T);
	clock_t t = clock();
	for (i = 1; i <= T; i++) {
		scanf("%d", &N);
		vector<vector<int> > nodes(N+1);
		int num;
		for (j = 1; j <= N; j++) { 
			scanf("%d", &num);
			nodes[num].push_back(j);
		}
		
		dfs(nodes);
		// printf("++++++\n");
		// for (j = 1; j <= N; j++)
		// 	printf("%d: %d %d\n", j, DP[j][0], DP[j][1]);
		// printf("======\n");
		int sum = INT_MAX;
		for (j = 0; j < MAXK; j++) {
			sum = min(sum, DP[1][j]);
		}
		printf("Case #%d: %d\n", i, sum);
	}
	t = clock() - t;
  	printf("It took %f seconds.\n", (float)t / CLOCKS_PER_SEC);
  	return 0;
}