#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

int T, N, P, ct[5005];

int main() {
	freopen("../APAC 2015 Round D/B-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round D/B-large-practice.out", "w", stdout);
	int a, b, q;
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d", &N);
		memset(ct, 0, sizeof(ct));
		rep(i, 0, N) {
			scanf("%d %d", &a, &b);
			rep(j, a, b + 1) ct[j]++;
		}
		scanf("%d", &P);
		printf("Case #%d:", tc);
		rep(i, 0, P) {
			scanf("%d", &q);
			printf(" %d", ct[q]);
		}
		puts("");
	}
	return 0;
}