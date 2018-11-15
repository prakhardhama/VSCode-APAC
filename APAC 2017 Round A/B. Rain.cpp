#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int T, R, C, mt[55][55];

bool sea;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool valid(int x, int y) {
	return x >= 0 && x < R && y < C && y >= 0;
}

int val, minA;
vii vis;

bool trav[55][55];
void rec(int x, int y) {
	vis.push_back(ii(x, y));
	trav[x][y] = true;
	//printf("vis %d %d\n", x, y);
	rep(i, 0, 4) {
		if (sea) return;
		int p, q;
		p = x + dr[i], q = y + dc[i];
		if (!valid(p, q)) { sea = true; return; }
		//printf("valid pq %d %d\n", p, q);
		if (mt[p][q] > val) minA = min(minA, mt[p][q]);
		else if(!trav[p][q]) rec(p, q);
		//printf("greater pq %d\n", mt[p][q]);
	}
}

void process(int x, int y) {
	sea = false;
	vis.clear(); minA = 1001; val = mt[x][y];
	memset(trav, false, sizeof(trav));
	//printf("val: %d\n", val);
	rec(x, y);
	if (sea) return;
	//printf("val: %d\n", val);
	//printf("x,y %d:%d minA: %d\n", x, y, minA);
	//rep(i, 0, (int)vis.size()) printf("%d:%d ", vis[i].first, vis[i].second); printf("vis\n");
	rep(i, 0, (int)vis.size()) {
		ii t = vis[i];
		int p = t.first, q = t.second;
		mt[p][q] = minA;
	}
}

void solve(int tc) {
	//printf("R: %d C: %d\n", R, C);
	/*puts("before");
	rep(i, 0, R) {
		rep(j, 0, C) printf("%d ", mt[i][j]); puts("");
	}*/
	
	int IP, OP;
	IP = OP = 0;
	rep(i, 0, R)
	rep(j, 0, C) IP += mt[i][j];

	rep(i, 0, R)
	rep(j, 0, C)
		process(i, j);
	
	/*puts("after");
	rep(i, 0, R) {
		rep(j, 0, C) printf("%d ", mt[i][j]); puts("");
	}*/

	rep(i, 0, R)
	rep(j, 0, C) OP += mt[i][j];
	printf("Case #%d: %d\n", tc, OP - IP);
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d", &R, &C);
		rep(j, 0, R)
		rep(k, 0, C)
			scanf("%d", &mt[j][k]);
		solve(i + 1);
	}
	return 0;
}