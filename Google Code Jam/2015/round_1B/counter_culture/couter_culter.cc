#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

ll reverse(ll n) {
    //if (n < 9)
    //	return n;
    if ( n % 10 == 0 )
    	return LLONG_MAX;
    ll rev = 0;
    while (n) {
    	rev *= 10;
    	rev += n % 10;
    	n /= 10;
    }
    return rev;
}

int sol(int N) {
	if ( N < 10 )
		return N;
    int DP[N + 1];
    int i;
    int rev;
    for (i = 0; i < 10; i++) {
    	DP[i] = i;
    }
    for (i = 10; i <= N; i++) {
    	rev = reverse(i);
    	if (rev < i)
    		DP[i] = min(DP[i - 1], DP[rev]) + 1;
    	else
    		DP[i] = DP[i - 1] + 1;
    	//printf("%d: %d\n", i, DP[i]);
    }
    return DP[N];
}

ll sol2(ll N) {
	ll step = 0;
	ll tmp;
	ll base = 1;
	while ( base * base <= N )
		base *= 10;
	while (N > 20) {
	    while ( base / 10 * (base / 10) > N )
	    	base /= 10;
	    tmp = N % base;
	    if ( tmp == 0 ) {
	    	N--;
	    	step++;
	    } else {
	    	step += tmp;
	    	N -= tmp - 1;
	    	tmp = reverse(N);
	    	N = ( tmp != N ) ? tmp : N - 1;
	    }
	}
	return step + N;
}

int main() {
	int T;
	ll N;
	int i;
	scanf("%d", &T);
    for (i = 1; i <= T; i++) {
    	scanf("%lld", &N);
    	//printf("%d\n", T);
    	printf("Case #%d: %lld\n", i, sol2(N));
    	//printf("%d\n", reverse(N));
    }
}