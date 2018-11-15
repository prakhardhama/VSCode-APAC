#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef vector<int> vi;

int T, N;
vi adj;
map<string, int> mp;
map<int, string> pm;

void solve(int tc, int S) {
	int ptr = S;
	printf("Case #%d:", tc);
	while (adj[ptr] != -1) {
		printf(" %s-%s", pm[ptr].c_str(), pm[adj[ptr]].c_str());
		ptr = adj[ptr];
	}
	puts("");
}

int main() {
	freopen("../APAC 2015 Round D/C-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round D/C-large-practice.out", "w", stdout);
	int k, u, v, src;
	string s1, s2;
	set<int> dest;
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d\n", &N);
		k = 0;
		adj.assign(N + 1, -1);
		rep(i, 0, N) {
			getline(cin, s1);
			getline(cin, s2);
			if (mp.find(s1) == mp.end()) mp[s1] = u = k, pm[k++] = s1;
			else u = mp[s1];
			if (mp.find(s2) == mp.end()) mp[s2] = v = k, pm[k++] = s2;
			else v = mp[s2];
			adj[u] = v;
			dest.insert(v);
		}
		rep(i, 0, N+1) 
			if (dest.find(i) == dest.end()) { src = i; break; }
		solve(tc, src);
		mp.clear(); pm.clear(); dest.clear(); adj.clear();
	}
	return 0;
}