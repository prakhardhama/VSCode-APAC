#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)
typedef vector<int> vi;
typedef pair<double, double> dd;

int T, B, L, N;

vi pnt[82215];
void init() {
	int s = 0, l = 0;
	rep(i, 1, 80601) {
		if (!l) l = ++s;
		pnt[i].push_back(i);
		pnt[i + s].push_back(i);
		pnt[i + s + 1].push_back(i);
		--l;
	}
	/*rep(i, 1, 11) {
		printf("%d: ", i);
		rep(j, 0, pnt[i].size()) printf("%d ", pnt[i][j]);
		puts("");
	}*/
}

dd dp[405][82215];
dd spilled(int l, int n) {
	dd sp, ps; 
	double c;
	if (l == 1) {
		c = B*750;
		if (c <= 250) sp.first = 0, sp.second = c;
		else sp.first = (c - 250) / 3, sp.second = 250;
		//printf("l %d: sp %.5lf %.5lf\n", l, sp.first, sp.second);
		return dp[l][n] = sp;
	}
	int k = ((l - 1)*l) / 2;
	c = 0;
	rep(i, 0, (int)pnt[n].size()) {
		int p = pnt[n][i];
		if (p > k) continue;
		if (dp[l - 1][p] != dd(-1, -1)) ps = dp[l - 1][p];
		else ps = spilled(l - 1, p);
		c += ps.first;
	}
	if (c <= 250) sp.first = 0, sp.second = c;
	else sp.first = (c - 250) / 3, sp.second = 250;
	//printf("l %d: sp %.5lf %.5lf\n", l, sp.first, sp.second);
	return dp[l][n] = sp;
}

void solve(int tc) {
	rep(i, 0, L) {
		int k = ((i + 1)*(i + 2)) / 2;
		rep(j, 0, k) dp[i][j] = dd(-1, -1);
	}
	dd sp = spilled(L, N);
	printf("Case #%d: %.12lf\n", tc, sp.second);
}

int main() {
	freopen("../APAC 2015 Round B/B-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round B/B-large-practice.out", "w", stdout);
	init();
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d %d", &B, &L, &N);
		fprintf(stderr, "solve %d: %d %d %d\n", tc, B, L, N);
		solve(tc);
	}
	return 0;
}

/*
double dp[405][82215];
void solve_old(int tc) {
	rep(i, 0, L) {
		int k = ((i + 1)*(i + 2)) / 2;
		rep(j, 0, k) dp[i][j] = 0.0;
	}
	dp[0][0] = B * 750;
	rep(i, 0, L) {
		int k = ((i + 1)*(i + 2)) / 2, s = 0, l = 0;
		rep(j, 0, k) {
			double c = dp[i][j];
			if (c <= 250.0) continue;
			dp[i][j] = 250.0;
			c -= 250.0; c /= 3;
			if (!l) l = ++s;
			dp[i + 1][j] += c;
			dp[i + 1][j + s] += c;
			dp[i + 1][j + s + 1] += c;
			--l;
		}
	}
	
	rep(i, 0, L) {
		int k = ((i + 1)*(i + 2)) / 2;
		rep(j, 0, k) printf("%.12lf(%2d) ", dp[i][j], j + 1);
		puts("");
	}
	
	double ans = dp[L - 1][N - 1];
	printf("Case #%d: %.12lf\n", tc, ans);
	return;
}*/