#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

int T, N, mt[1001][1001];

int dp[1001][1001];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool valid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void rec(int x, int y) {
	int curr = mt[x][y], s = 1;
	rep(i, 0, 4) {
		int p = x + dr[i], q = y + dc[i];
		if (!valid(p, q) || mt[p][q] != curr + 1) continue;
		if (dp[p][q] == -1) rec(p, q);
		s += dp[p][q];
		break;
	}
	dp[x][y] = s;
}

void solve(int tc) {
	memset(dp, -1, sizeof(dp));
	rep(i, 0, N)
	rep(j, 0, N)
		if (dp[i][j] == -1) rec(i, j);
	int d = 0, r;
	rep(i, 0, N)
	rep(j, 0, N)
		if (dp[i][j] > d) d = dp[i][j], r = mt[i][j];
		else if (dp[i][j] == d && mt[i][j] < r) r = mt[i][j];
	printf("Case #%d: %d %d\n", tc, r, d);
}

int main() {
	freopen("../APAC 2015 Round D/A-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round D/A-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d", &N);
		rep(i, 0, N)
		rep(j, 0, N)
			scanf("%d", &mt[i][j]);
		solve(tc);
	}
	return 0;
}