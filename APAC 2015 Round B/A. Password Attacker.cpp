#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define MOD 1000000007
typedef long long ll;


int T, M, N;
ll dp[105][105];

void init() {
	memset(dp, 0, sizeof(dp));
	rep(j, 1, 105) dp[1][j] = 1;
	
	rep(i, 2, 105)
	rep(j, i, 105)
		dp[i][j] = i*(dp[i][j - 1] + dp[i - 1][j - 1]),
		dp[i][j] %= MOD;
}

int main() {
	freopen("../APAC 2015 Round B/A-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round B/A-large-practice.out", "w", stdout);
	init();
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d", &M, &N);
		printf("Case #%d: %lld\n", tc, dp[M][N]);
	}
	return 0;
}