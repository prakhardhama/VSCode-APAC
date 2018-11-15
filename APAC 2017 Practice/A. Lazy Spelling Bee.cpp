#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define MX 1000000007
typedef long long ll;

int T;
string str;

void solve(int tc) {
	//cout << str << endl;
	ll ans = 1;
	int N = (int)str.size();
	if (N > 1 && str[0] != str[1]) ans *= 2;
	if (N > 1 && str[N - 2] != str[N - 1]) ans *= 2;
	rep(i, 1, N - 1) {
		if (str[i - 1] == str[i] && str[i] == str[i + 1]) continue;
		else if (str[i - 1] != str[i] && str[i] != str[i + 1] && str[i - 1] != str[i + 1]) ans *= 3;
		else ans *= 2;
		ans %= MX;
	}
	printf("Case #%d: %lld\n", tc, ans);
}

int main() {
	freopen("../A-large.in", "r", stdin);
	freopen("../A-large.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		cin >> str;
		solve(i + 1);
	}
	return 0;
}