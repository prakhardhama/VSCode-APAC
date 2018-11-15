#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define INF 1000000000
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int T, N, M, WT[105], ST[105], MET[1005];
vvii adj;

int path[1005];
vi dist;
void print_path(int v) {
	if (path[v] != -1) print_path(path[v]);
	int mt, sn;
	mt = MET[v];
	sn = v - ST[mt];
	printf("%d,%d (%d) -> ", mt + 1, sn + 1, dist[v]);
}

int dijkstra(int x1, int y1, int x2, int y2) {
	int SRC, DST;
	priority_queue<ii, vector<iii>, greater<iii>> pq;
	SRC = ST[x1] + y1, DST = ST[x2] + y2;
	pq.push(iii(0, ii(SRC, 1)));
	dist.assign(1005, INF);
	vector<bool> tunnel_arrive(1005, false);
	vector<bool> station_arrive(1005, false);
	dist[SRC] = 0;
	path[SRC] = -1;
	while (!pq.empty()) {
		iii t = pq.top(); pq.pop();
		int d = t.first, u = t.second.first, tun1=t.second.second;
		if (u == DST) break;
		//if (d > dist[u]) continue; IMP HERE!!!
		rep(i, 0, adj[u].size()) {
			ii vp = adj[u][i];
			int v = vp.first, tun2, d2;
			tun2 = (MET[u] == MET[v]) ? 0 : 1;
			if (tun1 && !tun2) d2 = d + WT[MET[v]] + vp.second;
			else d2 = d + vp.second;
			if (d2 < dist[v])
				dist[v] = d2, pq.push(iii(dist[v], ii(v, tun2))), path[v] = u;
			else if (!tunnel_arrive[v] && tun2)
				pq.push(iii(d2, ii(v, tun2))), tunnel_arrive[v] = true;
			else if (!station_arrive[v] && !tun2)
				pq.push(iii(d2, ii(v, tun2))), station_arrive[v] = true;
		}
	}
	//print_path(DST); puts("!");
	return dist[DST];
}

void solve(int tc) {
	/*puts("adj:");
	rep(i, 0, 1005) {
		if (adj[i].empty()) break;
		printf("%d: ", i);
		rep(j, 0, adj[i].size()) printf("%d(%d) ", adj[i][j].first, adj[i][j].second);
		puts("");
	}*/
	int Q, x1, y1, x2, y2, ans;
	scanf("%d", &Q);
	printf("Case #%d:\n", tc);
	rep(i, 0, Q) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		--x1, --y1, --x2, --y2;
		ans = dijkstra(x1, y1, x2, y2);
		printf("%d\n", ans == INF ? -1 : ans);
	}
}

int main() {
	freopen("../APAC 2015 Round C/B-small-practice.in", "r", stdin);
	freopen("../APAC 2015 Round C/B-small-practice.out", "w", stdout);
	int k, SN, TM[105], m1, m2, s1, s2, t, u, v;
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d", &N);
		adj.resize(1005);
		k = 0;
		rep(i, 0, N) {
			scanf("%d %d", &SN, &WT[i]);
			rep(j, 0, SN - 1)
				scanf("%d", &TM[j]);
			rep(j, 0, SN - 1)
				MET[k + j] = i,
				adj[k + j].push_back(ii(k + j + 1, TM[j])),
				adj[k + j + 1].push_back(ii(k + j, TM[j]));
			MET[k + SN - 1] = i;
			ST[i] = k;
			k += SN;
		}
		scanf("%d", &M);
		rep(i, 0, M) {
			scanf("%d %d %d %d %d", &m1, &s1, &m2, &s2, &t);
			--m1, --m2, --s1, --s2;
			u = ST[m1] + s1, v = ST[m2] + s2;
			adj[u].push_back(ii(v, t));
			adj[v].push_back(ii(u, t));
		}
		solve(tc);
		adj.clear();
	}
	return 0;
}