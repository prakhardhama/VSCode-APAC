#include<bits/stdc++.h>
using namespace std;

#define MX 101
#define rep($, a, b) for(int $=(a); $<(b); ++$)

typedef vector<bool> vb;

int T, R, C, N;
char mat[MX][MX];

int NC;
vector<vb> vis;
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

bool valid(int p, int q) {
	return p >= 0 && p < R && q >= 0 && q < C && !vis[p][q];
}

void rec(int p, int q) {
	vis[p][q] = 1;
	rep(i, 0, 4) {
		int x = p + dr[i], y = q + dc[i];
		if (valid(x, y) && mat[x][y] == '1') rec(x, y);
	}
}

void connect() {
	NC = 0;
	vis.assign(R, vb(C, 0));
	rep(i, 0, R)
		rep(j, 0, C)
		if (!vis[i][j] && mat[i][j] == '1') rec(i, j), ++NC;
	printf("%d\n", NC);
}

void solve(int tc) {
	/*rep(i, 0, R) {
		rep(j, 0, C) printf("%c", mat[i][j]);
		printf("\n");
	}*/
	printf("Case #%d:\n", tc);
	rep(i, 0, N) {
		char ch; int x, y, z;
		scanf("%c", &ch);
		(ch == 'M') ? (scanf("%d %d %d\n", &x, &y, &z), mat[x][y] = z + '0') : (scanf("\n"), connect());
	}
}

int main() {
	freopen("../APAC 2016 Round D/A-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round D/A-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d\n", &R, &C);
		rep(j, 0, R) {
			rep(k, 0, C) scanf("%c", &mat[j][k]);
			scanf("\n");
		}
		scanf("%d\n", &N);
		solve(i + 1);
	}
	return 0;
}