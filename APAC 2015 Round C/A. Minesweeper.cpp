#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

int T, N;
char mt[305][305];

int ans;
bool vis[305][305];
int dr[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dc[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

bool valid(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

bool isZero(int x, int y) {
	bool flag = true;
	int p, q;
	rep(i, 0, 8) {
		p = x + dr[i], q = y + dc[i];
		if (!valid(p, q)) continue;
		if (mt[p][q] == '*') { flag = false; break; }
	}
	return flag;
}

void rec(int x, int y) {
	int p, q;
	vis[x][y] = true;
	rep(i, 0, 8) {
		p = x + dr[i], q = y + dc[i];
		if (!valid(p, q)) continue;
		if (!vis[p][q] && mt[p][q] != '*' && isZero(p, q)) rec(p, q);
		vis[p][q] = true;
	}
}

void solve(int tc) {
	ans = 0;
	memset(vis, 0, sizeof(vis));
	rep(i, 0, N)
	rep(j, 0, N)
		if (!vis[i][j] && mt[i][j] != '*' && isZero(i, j))
			rec(i, j), ans++;
	rep(i, 0, N)
	rep(j, 0, N)
		if (!vis[i][j] && mt[i][j] != '*') ans++;
	printf("Case #%d: %d\n", tc, ans);
}

int main() {
	freopen("../APAC 2015 Round C/A-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round C/A-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d\n", &N);
		rep(i, 0, N) {
			rep(j, 0, N) scanf("%c", &mt[i][j]);
			scanf("\n");
		}
		solve(tc);
	}
	return 0;
}