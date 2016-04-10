#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int nonPrime(long long num) {
	for (int i = 2; i <= sqrt(num); i += 1) {
		//if (i % 2 == 0)
		//	i++;

		if (num % i == 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	int T, N, J;
	int i, j, k;
	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d %d", &N, &J);
		printf("Case #%d:\n", i);

		int d[9] = {0};
		int found = 0;
		string s (N, '0');
		s[0] = '1';
		s[N-1] = '1';
		queue<string> q;
		q.push(s);
		while (found < J) {
			s = q.front(); q.pop();
			//printf("%s|", s.c_str());
			for (k = 1; k < s.length() && s[k] != '1'; k++) {
				string tmp = s;
				tmp[k] = '1';
				q.push(tmp);
			}
			for (k = 10; k >= 2; k--) {
				d[k - 2] = nonPrime(stoll(s, 0, k));
				if (d[k - 2] == -1)
					break;
			}
			if (k == 1) {
				printf("%s", s.c_str());
				for (k = 0; k < 9; k++) {
					printf(" %d", d[k]);
				}
				printf("\n");
				found++;
			}
		}
	}
}