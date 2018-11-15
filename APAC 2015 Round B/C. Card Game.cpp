#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)

int T, N, K, arr[105];

int ptr[105], dp[105];
void solve(int tc) {
	int a, b, c, o1, o2;
	dp[N] = 0;
	arr[N] = -1;
	rep(i, 0, N + 1) ptr[i] = i;
	per(i, N - 1, 0) {
		a = arr[ptr[i]];
		b = arr[ptr[i + 1]]; 
		if (b == -1) { dp[i] = 1 + dp[i + 1]; continue; }
		c = arr[ptr[i + 2]];
		if (c == -1) { dp[i] = 1 + dp[i + 1]; continue; }
		if (b - a != K || c - b != K) { dp[i] = 1 + dp[i + 1]; continue; }
		o1 = 1 + dp[i + 1];
		o2 = dp[ptr[i + 2] + 1];
		if (o1 < o2) dp[i] = o1; 
		else {
			dp[i] = o2;
			ptr[i] = ptr[i + 3];
			ptr[i + 1] = ptr[ptr[i] + 1];
			ptr[i + 2] = ptr[ptr[i + 1] + 1];
		}
	}
	//printf("dp: ");
	//rep(i, 0, N) printf("%d(%d) ", dp[i], arr[i]); puts("");
	printf("Case #%d: %d\n", tc, dp[0]);
}

int main() {
	freopen("../APAC 2015 Round B/C-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round B/C-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d", &N, &K);
		rep(i, 0, N) scanf("%d", arr + i);
		fprintf(stderr, "solve tc: %d\n", tc);
		solve(tc);
	}
	return 0;
}