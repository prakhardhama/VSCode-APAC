#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)
#define INF 1000000
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int T, N, Q, K;
int add[10010][10010], sub[10010][10010];

iii inp[5005];
map<string, int> mp;
map<int, string> pm;

void solve(int tc) {
	int u, v, z;
	bool flag = true;
	while (flag) {
		flag = false;
		rep(i, 0, N) {
			z = inp[i].first, u = inp[i].second.first, v = inp[i].second.second;
			if (add[u][u] != INF && add[v][v] == INF) add[v][v] = (z - (add[u][u]/2))*2, flag = true;
			else if (add[u][u] == INF && add[v][v] != INF) add[u][u] = (z - (add[v][v]/2))*2, flag = true;
		}
	}
	int u1, v1, z1;
	rep(i, 0, N) {
		z = inp[i].first, u = inp[i].second.first, v = inp[i].second.second;
		if (u == v) continue;
		rep(j, i + 1, N) {
			z1 = inp[j].first, u1 = inp[j].second.first, v1 = inp[j].second.second;
			if (u1 == v1) continue;
			if ((u == u1 && v == v1) || (u == v1 && v == u1)) continue;
			if (u == u1) sub[v][v1] = z - z1, sub[v1][v] = z1 - z;
			else if (u == v1) sub[v][u1] = z - z1, sub[u1][v] = z1 - z;
			else if (v == u1) sub[u][v1] = z - z1, sub[v1][u] = z1 - z;
			else if (v == v1) sub[u][u1] = z - z1, sub[u1][u] = z1 - z;
		}
	}
	string buf1, buf2;
	scanf("%d\n", &Q);
	printf("Case #%d:\n", tc);
	rep(i, 0, Q) {
		getline(cin, buf1, '+');
		getline(cin, buf2);
		if (mp.find(buf1) == mp.end()) continue;
		else u = mp[buf1];
		if (mp.find(buf2) == mp.end()) continue;
		else v = mp[buf2];
		if (add[u][v] != INF) printf("%s+%s=%d\n", pm[u].c_str(), pm[v].c_str(), add[u][v]);
		else if (add[u][u] != INF && add[v][v] != INF) printf("%s+%s=%d\n", pm[u].c_str(), pm[v].c_str(), (add[u][u] + add[v][v])/2);
		else {
			if (u == v) continue;
			rep(k, 0, K) {
				if (k == u || k == v) continue;
				if (sub[u][k] != INF && add[k][v] != INF) {
					printf("%s+%s=%d\n", pm[u].c_str(), pm[v].c_str(), sub[u][k] + add[k][v]);
					break;
				}
				else if (sub[v][k] != INF && add[k][u] != INF) {
					printf("%s+%s=%d\n", pm[u].c_str(), pm[v].c_str(), sub[v][k] + add[k][u]);
					break;
				}
			}
		}
	}
}

int main() {
	freopen("../APAC 2015 Round A/C-small-practice.in", "r", stdin);
	freopen("../APAC 2015 Round A/C-small-practice.out", "w", stdout);
	string buf1, buf2;
	int z, k, u, v;
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		rep(i, 0, 10010)
		rep(j, 0, 10010) 
			add[i][j] = sub[i][j] = INF;
		rep(i, 0, 10010)
			sub[i][i] = 0;
		scanf("%d\n", &N);
		k = 0;
		rep(i, 0, N) {
			getline(cin, buf1, '+');
			getline(cin, buf2, '=');
			scanf("%d\n", &z);
			//printf("%s + %s = %d\n", buf1.c_str(), buf2.c_str(), z);
			if (mp.find(buf1) == mp.end()) mp[buf1] = u = k, pm[k++] = buf1;
			else u = mp[buf1];
			if (mp.find(buf2) == mp.end()) mp[buf2] = v = k, pm[k++] = buf2;
			else v = mp[buf2];
			add[u][v] = add[v][u] = z;
			inp[i] = iii(z, ii(u, v));
		}
		K = k;
		solve(tc);
		mp.clear(); pm.clear();
	}
	return 0;
}