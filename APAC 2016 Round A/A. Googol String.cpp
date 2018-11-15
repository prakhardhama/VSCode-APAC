#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef long long ll;

int T;
ll K;

void solve(int tc) {
	int idx = 1;
	ll p = 1;
	//cout << K << endl;
	while (p <= K) p = (p << 1) + 1, ++idx;
	int b = 0; 
	ll l, r;
	l = 0, r = p - 1;
	//cout << l << " " << r << endl;
	while (1) {
		ll mid = (l + r) >> 1;
		if (K == mid) break;
		else if (K < mid) r = mid - 1, b = 0;
		else l = mid + 1, b = 1;
	}
	printf("Case #%d: %d\n", tc, b);
}

int main() {
	freopen("../APAC 2016 Round A/A-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round A/A-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%lld", &K); --K;
		solve(i + 1);
	}
}