#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); $++)
typedef vector<int> vi;
typedef vector<vi> vvi;

int T, M, N;
map<string, int> mp;
vvi adj;

vi col;
bool flag;

void rec(int u, int c) {
	int v;
	rep(i, 0, adj[u].size()) {
		if (!flag) return;
		v = adj[u][i];
		if (col[v] != -1) {
			if (col[v] != 1 - c) { flag = false; return; }
		}
		else {
			col[v] = 1 - c;
			rec(v, 1 - c);
		}
	}
}

void solve(int tc) {
	col.assign(N, -1);
	flag = true;
	rep(i, 0, N)
		if (!flag) break;
		else if (col[i] == -1) col[i] = 0, rec(i, 0);
	printf("Case #%d: %s\n", tc, flag ? "Yes" : "No");
}

int main() {
	freopen("../APAC 2016 Practice/A-small-practice-2.in", "r", stdin);
	freopen("../APAC 2016 Practice/A-small-practice-2.out", "w", stdout);
	int k, u, v;
	string s1, s2;
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d", &M);
		k = 0;
		adj.resize(2 * M);
		rep(i, 0, M) {
			cin >> s1 >> s2;
			if (mp.find(s1) == mp.end()) mp[s1] = u = k++;
			else u = mp[s1];
			if (mp.find(s2) == mp.end()) mp[s2] = v = k++;
			else v = mp[s2];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		N = k;
		solve(tc);
		mp.clear();
		adj.clear();
	}
	return 0;
}