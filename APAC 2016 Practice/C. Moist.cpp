#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)

int T, N;
string inp[105];

void solve(int tc) {
	int ans = 0, idx;
	string temp;
	rep(i, 1, N) {
		idx = -1;
		per(j, i - 1, 0)
			if (inp[i] > inp[j]) { idx = j; break; }
		++idx;
		if (idx == i) continue;
		temp = inp[i];
		per(j, i, idx + 1)
			inp[j] = inp[j - 1];
		inp[idx] = temp;
		++ans;
	}
	//puts("sorted");
	//rep(i, 0, N) printf("%s\n", inp[i].c_str());
	printf("Case #%d: %d\n", tc, ans);
}

int main() {
	freopen("../APAC 2016 Practice/C-small-practice-2.in", "r", stdin);
	freopen("../APAC 2016 Practice/C-small-practice-2.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d\n", &N);
		rep(i, 0, N) getline(cin, inp[i]);
		solve(tc);
	}
	return 0;
}