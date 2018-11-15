#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)

int T, M, N;
int K[13], L[13];
int A[13][11], C[13][11];

int mxp;
void rec(int idx, int rem, int powr) {
	if (idx == N) {
		//printf("%d %d %d\n", idx, rem, powr);
		mxp = max(mxp, powr);
		//printf("mxp %d\n", mxp);
		return;
	}
	int lev = L[idx];
	rec(idx + 1, rem, powr + A[idx][lev]);
	rep(i, lev, K[idx] - 1) {
		if (C[idx][i] <= rem) {
			rec(idx + 1, rem - C[idx][i], powr + A[idx][i + 1]);
		}
	}
}

void solve(int tc) {
	//printf("M %d N %d\n", M, N);
	//rep(i, 0, N) printf("K %d L %d\n", K[i], L[i]);
	mxp = -1;
	rec(0, M, 0);
	printf("Case #%d: %d\n", tc, mxp);
}

int main() {
	freopen("Clash Royale.in", "r", stdin);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d", &M, &N);
		rep(j, 0, N) {
			scanf("%d %d", &K[j], &L[j]);
			rep(k, 0, K[j]) scanf("%d", &A[j][k]);
			rep(k, 0, K[j]-1) scanf("%d", &C[j][k]);
		}
		solve(i + 1);
	}
	return 0;
}