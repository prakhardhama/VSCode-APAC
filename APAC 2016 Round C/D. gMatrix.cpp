#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef long long ll;

int T, N, K, C, X;
ll A[3005], B[3005], mt[3005][3005];

ll ST[12020][12020];

void build1d(int p, int q, int C, int R1, int R2) {
	int lt, rt, mid;
	if (R1 == R2) {
		ST[p][q] = mt[R1][C];
		return;
	}
	lt = (q<<1) + 1, rt = lt + 1;
	mid = (R1 + R2) >> 1;
	build1d(p, lt, C, R1, mid);
	build1d(p, rt, C, mid + 1, R2);
	ST[p][q] = max(ST[p][lt], ST[p][rt]);
}

void build2d(int p, int C1, int C2) {
	int lt, rt, mid;
	if (C1 == C2) {
		build1d(p, 0, C1, 0, N - 1);
		//printf("column %d max: %lld\n", C1, ST[p][0]);
		return;
	}
	lt = (p << 1) + 1, rt = lt + 1;
	mid = (C1 + C2) >> 1;
	build2d(lt, C1, mid);
	build2d(rt, mid + 1, C2);
	rep(j, 0, 4*N)
		ST[p][j] = max(ST[lt][j], ST[rt][j]);
}

int xa, ya, xb, yb;

ll rmq1d(int p, int q, int R1, int R2) {
	ll ret; int lt, rt, mid;
	if (R1 > xb || R2 < xa) return -1;
	if (R1 >= xa && R2 <= xb) return ST[p][q];
	lt = (q << 1) + 1, rt = lt + 1;
	mid = (R1 + R2) >> 1;
	ret = max(rmq1d(p, lt, R1, mid), rmq1d(p, rt, mid + 1, R2));
	return ret;
}

ll rmq2d(int p, int C1, int C2) {
	ll ret; int lt, rt, mid;
	if (C1 > yb || C2 < ya) return -1;
	if (C1 >= ya && C2 <= yb) return rmq1d(p, 0, 0, N - 1);
	lt = (p << 1) + 1, rt = lt + 1;
	mid = (C1 + C2) >> 1;
	ret = max(rmq2d(lt, C1, mid), rmq2d(rt, mid + 1, C2));
	return ret;
}

void solve(int tc) {
	/*puts("MT:");
	rep(i, 0, N) {
		rep(j, 0, N) printf("%lld ", mt[i][j]);
		puts("");
	}*/
	build2d(0, 0, N - 1);
	ll ans = 0, ret;
	rep(i, 0, N - K + 1)
	rep(j, 0, N - K + 1) {
		xa = i, ya = j, xb = i + K - 1, yb = j + K - 1;
		ret = rmq2d(0, 0, N - 1);
		//printf("max in %d,%d - %d,%d: %lld\n", xa, ya, xb, yb, ret);
		ans += ret;
	}
	printf("Case #%d: %lld\n", tc, ans);
}

int main() {
	freopen("../APAC 2016 Round C/D-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round C/D-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d %d %d", &N, &K, &C, &X);
		rep(i, 0, N) scanf("%lld", A + i);
		rep(i, 0, N) scanf("%lld", B + i);
		rep(i, 0, N)
		rep(j, 0, N)
			mt[i][j] = (A[i]*(i + 1) + B[j]*(j + 1) + C) % X;
		fprintf(stderr, "solve %d\n", tc);
		solve(tc);
	}
	return 0;
}