#include<bits/stdc++.h>
using namespace std;

#define MXK 1000000000000010LL
#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;

int T, N;
ll P[101], K[101];

pll bisection(int idx) {
	pll ret;
	ll low = 0, high = MXK, mid;
	while (low < high) {
		mid = (low + high) >> 1;
		if (mid && (K[idx] * 100) / mid > P[idx]) low = mid + 1;
		else high = mid, ret.first = high;
	}
	low = 0, high = MXK;
	while (low < high) {
		mid = (low + high) >> 1; ++mid;
		if ((K[idx] * 100) / mid < P[idx]) high = mid - 1;
		else low = mid, ret.second = low;
	}
	return ret;
}

void solve(int tc) {
	printf("Case #%d: ", tc);
	if (P[N - 1] == 100) { printf("%lld\n", K[N - 1]); return; }
	pll ans = pll(-MXK, MXK);
	rep(i, 0, N) {
		pll ret = bisection(i);
		//printf("%lld: %lld %lld\n", P[i], ret.first, ret.second);
		ans.first = max(ans.first, ret.first);
		ans.second = min(ans.second, ret.second);
	}
	if (ans.first != ans.second) puts("-1");
	else printf("%lld\n", ans.first);
}

int main() {
	//freopen("../APAC 2016 Round C/B-large-practice.in", "r", stdin);
	//freopen("../APAC 2016 Round C/B-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d", &N);
		rep(j, 0, N)
			scanf("%lld %lld", P + j, K + j);
		solve(i + 1);
	}
	return 0;
}