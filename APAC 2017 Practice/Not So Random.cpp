#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

int T, N, X, K, A, B, C;

void solve(int tc) {
	map<int, double> mp_prev, mp;
	int a;
	mp[X&K] += (double)A / 100;
	mp[X|K] += (double)B / 100;
	mp[X^K] += (double)C / 100;
	rep(i, 1, N) {
		mp_prev = mp;
		mp.clear();
		for (auto e : mp_prev) {
			int a; double p;
			a = e.first; p = e.second;
			mp[a&K] += p * (double)A / 100;
			mp[a|K] += p * (double)B / 100;
			mp[a^K] += p * (double)C / 100;
		}
	}
	double s = 0.0;
	for (auto e : mp) s += e.first*e.second;
	printf("Case #%d: %.10lf\n", tc, s);
}

int main() {
	freopen("../Not So Random.in", "r", stdin);
	//freopen("../Not So Random.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d %d %d %d %d", &N, &X, &K, &A, &B, &C);
		solve(i + 1);
	}
	return 0;
}