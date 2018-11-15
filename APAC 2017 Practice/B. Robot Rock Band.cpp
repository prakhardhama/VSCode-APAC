#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define MXS 1005
#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef long long ll;

int T, N, K;
int A[MXS], B[MXS], C[MXS], D[MXS];

void solve(int tc) {
	vector<int> TP;
	rep(i, 0, N)
	rep(j, 0, N) 
		TP.push_back(A[i] ^ B[j]);

	TP.push_back(1 << 31);
	sort(TP.begin(), TP.end());

	ll ans = 0;
	rep(i, 0, N)
	rep(j, 0, N) {
		int x = C[i] ^ D[j] ^ K, p1, p2;
		auto it = lower_bound(TP.begin(), TP.end(), x);
		if (*it != x) continue;
		p1 = it - TP.begin();
		it = upper_bound(TP.begin(), TP.end(), x);
		p2 = it - TP.begin();
		ans += p2 - p1;
	}

	printf("Case #%d: %lld\n", tc, ans);
}

int main() {
	freopen("../APAC 2017 Practice/B-large-practice.in", "r", stdin);
	freopen("../APAC 2017 Practice/B-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d", &N, &K);
		rep(i, 0, N) scanf("%d", &A[i]);
		rep(i, 0, N) scanf("%d", &B[i]);
		rep(i, 0, N) scanf("%d", &C[i]);
		rep(i, 0, N) scanf("%d", &D[i]);
		fprintf(stderr, "solve %d\n", i + 1);
		solve(i + 1);
	}
	return 0;
}
