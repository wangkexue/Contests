#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

long long sol(long long num) {
    if (num == 0) {
        return -1;
    }
    bool digits[10] = {0};
    int digitsSeen= 0;
    int n = 1;
    while(1) {
        long long tmp = num * n++;
        while (tmp) {
            int digit = tmp % 10;
            if (!digits[digit]) {
                digits[digit] = true;
                if (++digitsSeen > 9) {
                    return num * (n - 1);
                }
            }
            tmp /= 10;
        }
    }
}

int main() {
    int T;
    int i;
    scanf("%d", &T);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (i = 1; i <= T; i++) {
        long long input;
        cin >> input;
        long long output = sol(input);
        if (output == -1) {
            printf("Case #%d: INSOMNIA\n", i);
        } else {
            printf("Case #%d: %lld\n", i, output);
        }
    }
}