#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int sol(string cakes) {
	cakes += '+';
	int i;
	int step = 0;
	for (i = cakes.length() - 2; i >= 0; i--) {
		if (cakes[i] != cakes[i + 1])
			step++;
	}
	return step;
}

int main() {
	int T;
	int i;
	scanf("%d", &T);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (i = 1; i <= T; i++) {
		string str;
		cin >> str;
		printf("Case #%d: %d\n", i, sol(str));
	}
}