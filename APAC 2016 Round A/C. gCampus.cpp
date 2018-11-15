#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define INF 1000000000
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;

int T, N, M;
vvii adj;
viii edge;

vi dist;
bool ineff(iii e) {
	int S = e.second.first, D = e.second.second, W = e.first;
	dist.assign(N, INF);
	dist[S] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(ii(0, S));
	while (!pq.empty()) {
		ii t = pq.top(); pq.pop();
		int d = t.first, u = t.second;
		if (d > dist[u]) continue;
		if (u == D) break;
		rep(i, 0, adj[u].size()) {
			ii vp = adj[u][i];
			int v = vp.first, dv = d + vp.second;
			if (dv < dist[v]) dist[v] = dv, pq.push(ii(dv, v));
		}
	}
	return dist[D] < W;
}

void solve(int tc) {
	printf("Case #%d:\n", tc);
	rep(i, 0, M) {
		if (ineff(edge[i])) printf("%d\n", i);
	}
}

int main() {
	freopen("../APAC 2016 Round A/C-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round A/C-large-practice.out", "w", stdout);
	int u, v, w;
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d", &N, &M);
		adj.resize(N);
		edge.resize(M);
		rep(i, 0, M) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(ii(v, w));
			adj[v].push_back(ii(u, w));
			edge[i] = iii(w, ii(u, v));
		}
		solve(tc);
		adj.clear(); edge.clear();
	}
	return 0;
}