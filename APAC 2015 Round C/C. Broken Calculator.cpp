#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define INF 100000000

int T, X, work[10];

int dp[1000010];
int writable(int x) {
	int s = 0, rem;
	while (x) {
		rem = x % 10;
		if (!work[rem]) return INF;
		x /= 10;
		s++;
	}
	return s;
}

void rec(int x) {
	int d = writable(x);
	if (d != INF) { dp[x] = d; return; }
	int mind = INF;
	rep(i, 2, floor(sqrt(x)) + 1)
	if (x%i == 0) {
		int a = i, b = x / i, s = 0;
		if (dp[a] == -1) rec(a);
		s += dp[a];
		if (dp[b] == -1) rec(b);
		s += dp[b];
		s += 1;
		if (s < mind) mind = s;
	}
	//printf("x %d: %d\n", x, mind);
	dp[x] = mind;
}

void solve(int tc) {
	memset(dp, -1, sizeof(dp));
	rec(X);
	int ans = dp[X] + 1;
	printf("Case #%d: ", tc);
	if (ans != INF + 1) printf("%d\n", ans);
	else puts("Impossible");
}

int main() {
	freopen("../APAC 2015 Round C/C-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round C/C-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		rep(i, 0, 10) scanf("%d", work + i);
		scanf("%d", &X);
		solve(tc);
	}
	return 0;
}