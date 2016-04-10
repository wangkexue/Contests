#include <cstdio>
//#include <vector>
#include <string>
#include <iostream>
//#include <cstring>
//#include <unordered_map>
using namespace std;

// unordered_map<char, int> dict;
// dict['i'] = 1;
// dict['j'] = 2;
// dict['k'] = 3;
char mul(char a, char b, bool &sign) {
	if (a == '1')
		return b;
	if (b == '1')
		return a;
	if (a == b) {
		sign = !sign;
		return '1';
	}
	char rst = 'i' + 'j' + 'k' - a - b;
	if (a > b)
		sign = !sign;
	if (rst == 'j')
		sign = !sign;
	//cout << rst << endl;
	return rst;
}

char rDiv(char a, char b, bool &sign) {
	// if (a == 1) {
	// 	sign = !sign;
	// 	return b;
	// }
	// if (a == b)
	// 	return 1;
	// //if (b == 1)
	// //	return a;
	// char rst = 'i' + 'j' + 'k' - a - b;

	// return rst;
	sign = !sign;
	char r = mul(a, b, sign);
	//sign = ssign;
	return r;
}

char lDiv(char a, char b, bool &sign) {
	if (a == '1' || a == b·)
		return rDiv(a, b, sign);
	return mul(a, b, sign);
}

bool sol(string &str) {
	if (str.size() < 3)
		return false;
	int i, j;
	char left, mid, right;
	bool leftS, midS, rightS;
	left = right = mid = '1';
	leftS = midS = rightS = true;

	// mid = 'i', midS = true;
	// cout << lDiv(mid, 'k', midS) << endl;
	// cout << midS << endl;
	// return false;
	//cout << div('i', 'j', midS) << endl;
	for (i = 0; i < str.size(); i++) {
		mid = mul(mid, str[i], midS);
		//cout << mid << endl;
	}
	//cout << midS << " " << mid << endl;
	//cout << mid << endl;
	for (i = 1; i <= str.size() - 2; i++) {
		left = mul(left, str[i-1], leftS);
		mid = lDiv(mid, str[i-1], midS);
		for (j = str.size() - 2; j >= i; j--) {
			right = mul(str[j+1], right, rightS);
			mid = rDiv(mid, str[j+1], midS);
			//printf("%d %d | %d %d | %d %d\n", leftS, left, midS, mid, rightS, right);
			if (left == 'i' && mid == 'j' && right == 'k' &&
				leftS && midS && rightS)
				return true;
		}
	}
	return false;
}

int main() {
	int T, L, X;
	int i, j, k;
	scanf("%d", &T);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (i = 1; i <= T; i++) {
		scanf("%d%d", &L, &X);
		//printf("%d %d\n", L, X);
		//vector<char> str(L*X);
		//for (j = 0; j < L; j++) {
		//	scanf("%c", &str[j]);
		//}
		//cout << L << X << "\n";
		string str;
		cin >> str;
		str.resize(L*X);
		for (k = 1; k < X; k++) 
			for (j = 0; j < L; j++)
				str[k * L + j] = str[j];
		if (sol(str))
			printf("Case #%d: YES\n", i);
		else
			printf("Case #%d: NO\n", i);
	}
}