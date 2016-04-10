#include <cstdio>
//#include <cstring>
#include <numeric>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

struct Nqueue {
	int pos;
	int customer;
	long long mins;
	Nqueue (int p, int c,  long long m) : pos(p), customer(c), mins(m) {}
};

int gcd(int a, int b) {
    for (;;) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b) {
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

class mycomp {
public:
	bool operator() (const Nqueue &lhs, const Nqueue &rhs) const {
		if (lhs.mins == rhs.mins) //{
			//if (lhs.pos > rhs.pos)
			//	return true;
			//else
				return lhs.pos >
				 rhs.pos;
		//}
		else
			return lhs.mins > rhs.mins;
	}
};

int sol(int N, int B, int* Ms) {
	int LCM = Ms[0];
	int j, k;
	int SPEC[B];		
	for ( j = 1; j < B; j++ )
		LCM = lcm(LCM, Ms[j]);
	int sum = 0;
	for ( j = 0; j < B; j++) {
		sum += LCM / Ms[j];
		//sum += SPEC[j];
	}
	//printf("SUM: %d\n", sum);
	N %= sum;
	if ( N == 0 )
		N = sum;
	if ( N <= B)
		return N;
	N -= B;
	//printf("N - B = %d\n", N);
	vector<Nqueue> tmp;
	tmp.reserve(B);
	for ( j = 0; j < B; j++ )
		tmp.push_back(Nqueue(j + 1, j, Ms[j]));
	priority_queue<Nqueue, vector<Nqueue>, mycomp> pq(tmp.begin(), tmp.end());
	for ( j = B; j < N - 1 + B; j++ ) {
		Nqueue t = pq.top();
		//printf("%lld\n", t.mins);
		pq.pop();
		t.mins += Ms[t.pos - 1];
		t.customer = j;
		pq.push(t);
	}
	return pq.top().pos;
}


int main() {
	int T, B, N;
	int i, j, k;
	int y;
	scanf("%d", &T);
	for ( i = 1; i <= T; i++ ) {
		scanf("%d", &B);
		scanf("%d", &N);
		int Ms[B];
		for ( j = 0; j < B; j++ ) {
			scanf("%d", &Ms[j]);
		}
		y = sol(N, B, Ms);
		printf("Case #%d: %d\n", i, y);
	}
}