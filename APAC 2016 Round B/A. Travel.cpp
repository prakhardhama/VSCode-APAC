#include<bits/stdc++.h>
using namespace std;

#define MXV 501
#define MXE 2001
#define INF 1000000000
#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, vi> piv;

int T, N, M, K, D, S;
vector<piv> adj[MXV];

vi dist[MXV];
int ans;
void dijkstra() {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 0));
	dist[0].assign(24, 0);
	while (!pq.empty()) {
		ii t = pq.top(); pq.pop();
		int d = t.first, u = t.second;
		if (u == D) break;
		int ts = (S + d) % 24;
		if (dist[u][ts] < d) continue;
		//printf("u: %d d: %d ts: %d\n", u + 1, d, ts);
		rep(i, 0, (int)adj[u].size()) {
			int v; vi cst;
			v = adj[u][i].first; cst = adj[u][i].second;
			int te = (S + d + cst[ts]) % 24;
			if (d + cst[ts] < dist[v][te]) {
				//printf("pushing old: %d new: %d v: %d te: %d\n", dist[v][te], d + cst[ts], v, te);
				dist[v][te] = d + cst[ts];
				pq.push(ii(dist[v][te], v));
			}
		}
	}
	//rep(k, 0, 24) printf("%d ", dist[D][k]); printf(": dist at dest\n");
	ans = INF;
	rep(k, 0, 24) ans = min(ans, dist[D][k]);
}

void solve(int tc) {
	/*printf("adj:\n");
	rep(i, 0, N) {
		printf("u %d\n", i + 1);
		rep(j, 0, (int)adj[i].size()) {
			int v; vi cst;
			v = adj[i][j].first; cst = adj[i][j].second;
			printf("%d: ", v + 1);
			rep(k, 0, 24) printf("%d ", cst[k]); printf("\n");
		}
	}*/
	printf("Case #%d: ", tc);
	rep(i, 0, K) {
		scanf("%d %d", &D, &S); --D;
		rep(j, 0, MXV) dist[j].assign(24, INF);
		dijkstra();
		if(i<K-1) (ans != INF) ? printf("%d ", ans) : printf("-1 ");
		else (ans != INF) ? printf("%d", ans) : printf("-1");
	}
	printf("\n");
}

int main() {
	freopen("../APAC 2016 Round B/A-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round B/A-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d %d", &N, &M, &K);
		rep(j, 0, MXV) adj[j].clear();
		rep(j, 0, M) {
			int u, v; vi cst(24);
			scanf("%d %d", &u, &v); --u; --v;
			rep(k, 0, 24) scanf("%d", &cst[k]);
			adj[u].push_back(piv(v, cst));
			adj[v].push_back(piv(u, cst));
		}
		solve(i + 1);
	}
	return 0;
}