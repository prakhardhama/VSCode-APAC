#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef vector<int> vi;
typedef long long ll;

int T, N, Q;
vi arr;

void solve(int tc) {
	printf("Case #%d:\n", tc);
	vector<ll> sub;
	rep(i, 0, N) {
		ll s = 0;
		rep(j, i, N) {
			s += (ll)arr[j];
			sub.push_back(s);
		}
	}
	sort(sub.begin(), sub.end());
	rep(i, 0, Q) {
		int l, r;
		ll s = 0;
		scanf("%d %d", &l, &r); --l; --r;
		rep(j, l, r + 1) s += sub[j];
		printf("%lld\n", s);
	}
}

int main() {
	freopen("../APAC 2017 Practice/D-small-attempt1.in", "r", stdin);
	freopen("../APAC 2017 Practice/D-small-attempt1.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d", &N, &Q);
		arr.resize(N);
		rep(j, 0, N) scanf("%d", &arr[j]);
		solve(i + 1);
		arr.clear();
	}
	return 0;
}