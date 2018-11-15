#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

int T, N, M;
int arr[1010];

void solve(int tc) {
	printf("Case #%d:\n", tc);
	int l, r;
	rep(i, 0, M) {
		double ans = 1.0;
		scanf("%d %d", &l, &r);
		double sz = r - l + 1;
		rep(j, l, r + 1) ans *= pow(arr[j], 1 / sz);
		printf("%.9lf\n", ans);
	}
}

int main() {
	freopen("../APAC 2016 Round A/B-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round A/B-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d", &N, &M);
		rep(j, 0, N) scanf("%d", arr + j);
		solve(i + 1);
	}
	return 0;
}