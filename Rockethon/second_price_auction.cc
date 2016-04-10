#include <cstdio>
#include <climits>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int com[5][2];
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d%d", &com[i][0], &com[i][1]);
	int maxR = INT_MIN;
	int minR = INT_MIN;
	int maxP = INT_MIN;
	for (i = 0; i < N; i++)
		maxP = max(maxP, com[i][1]);
    for (i = 0; i < N; i++) {
    	if (com[i][1] != maxP) {
    		//maxR = min(maxR, com[i][1]);
    		minR = max(minR, com[i][0]);
    		if (com[i][1] < maxP)
    			maxR = max(maxR, com[i][1]);
    	}
    }
    printf("%d %d\n", minR, maxR);
    int sum = 0;
    //int maxSum = 0;
    int deg = 0;
    //int maxDeg = 0;
    vector<pair<int, int> > MaxNs;
    for (i = 0; i < N; i++) { 
    	if (com[i][1] >= minR && com[i][0] <= maxR) {	
    		int maxT = min(maxR, com[i][1]);
    		int minT = max(minR, com[i][0]);
    		int tmp = maxT - minT + 1;
    		sum += tmp;
    		deg += (maxT + minT) * tmp / 2;
    	}
    	// else if (com[i][1] == maxP){
    	// 	int minT = max(minR, com[i][0]);
    	// 	int tmp = com[i][1] - minT + 1;
    	// 	MaxNs.push_back(make_pair(tmp, (com[i][1] + minT) * tmp / 2));
    	// 	maxSum += tmp;
    	// 	maxDeg += (com[i][1] + minT) * tmp / 2;
    	// }
    }
    double exp;
    //if (MaxNs.size() <= 1)
    	exp = (double)deg / sum;
    // else {
    // 	printf("HERE\n");
    // 	for (i = 0; i < MaxNs.size(); i++) {
    // 		exp += ((double)deg + maxDeg - MaxNs[i].second) / ((double)sum + maxSum - MaxNs[i].first);
    // 	}
    // 	exp /= MaxNs.size();
    // }
	printf("%.10f", exp);
}