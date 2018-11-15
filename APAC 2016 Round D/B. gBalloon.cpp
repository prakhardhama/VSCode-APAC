#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

int T, N, M, Q, W[1005], P[105], H[105];

int pos(int tp) {
	int q = Q, mint = -1, en, t;
	rep(i, 0, N) {
		en = -1;
		if (P[i] == 0) en = 0;
		else
		rep(j, 0, M) {
			if (W[j] == 0) continue;
			if (P[i] * W[j] < 0) {
				t = (int)ceil(double(abs(P[i])) / abs(W[j]));
				if (t > tp) continue;
				//printf("b %d Pi %d Wj %d t %d Hi %d j %d eg %d\n", i, P[i], W[j], t, H[i], j, abs(H[i] - j));
				if (en == -1) en = abs(H[i] - j);
				else en = min(en, abs(H[i] - j));
			}
		}
		//printf("balloon %d min energy %d latest by %d\n", i, en, tp);
		if (en == -1 || en > q) return 0;
		q -= en;
	}
	return 1;
}

void solve(int tc) {
	int low = 0, high = 10010, ans = -1, mid;
	while (low < high) {
		mid = (low + high) >> 1;
		if (pos(mid)) ans = mid, high = mid;
		else low = mid + 1;
	}
	printf("Case #%d: ", tc);
	if (ans == -1) puts("IMPOSSIBLE");
	else printf("%d\n", ans);
}

int main() {
	//freopen("../APAC 2016 Round D/B-large-practice.in", "r", stdin);
	//freopen("../APAC 2016 Round D/B-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d %d", &N, &M, &Q);
		rep(i, 0, M) scanf("%d", W + i);
		rep(i, 0, N) scanf("%d %d", P + i, H + i);
		solve(tc);
	}
	return 0;
}