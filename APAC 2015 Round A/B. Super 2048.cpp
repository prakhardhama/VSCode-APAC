#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)

int T, N, mt[25][25];
string dir;

void rotR() {
	int br[25][25];
	rep(i, 0, N)
	rep(j, 0, N)
		br[i][j] = mt[N - j - 1][i];
	memcpy(mt, br, sizeof(br));
}

void solve(int tc) {
	/*printf("N: %d dir: ", N); cout << dir << endl;
	rep(i, 0, N) {
		rep(j, 0, N) printf("%d ", mt[i][j]);
		puts("");
	}
	printf("rotated\n");*/
	if (dir == "up") rotR();
	else if (dir == "down") rotR(), rotR(), rotR();
	else if (dir == "left") rotR(), rotR();
	/*rep(i, 0, N) {
		rep(j, 0, N) printf("%d ", mt[i][j]);
		puts("");
	}*/
	vector<int> row, nxt;
	rep(i, 0, N) {
		row.clear();
		nxt.clear();
		per(j, N - 1, 0) 
			if (mt[i][j]) row.push_back(mt[i][j]);
		//rep(j, 0, (int)row.size()) printf("%d ", row[j]); puts("row");

		rep(j, 0, (int)row.size()) {
			if (j < (int)row.size() - 1 && row[j] == row[j + 1]) nxt.push_back(row[j] << 1), ++j;
			else nxt.push_back(row[j]);
		}
		int k = N - 1;
		memset(mt[i], 0, sizeof(mt[i]));

		//rep(j, 0, N) printf("%d ", mt[i][j]); puts("original row");
		//rep(j, 0, (int)nxt.size()) printf("%d ", nxt[j]); puts("nxt");
		
		rep(j, 0, (int)nxt.size())
			mt[i][k--] = nxt[j];
	}
	if (dir == "up") rotR(), rotR(), rotR();
	else if (dir == "down") rotR();
	else if (dir == "left") rotR(), rotR();
	printf("Case #%d:\n", tc);
	rep(i, 0, N) {
		rep(j, 0, N) printf("%d ", mt[i][j]);
		puts("");
	}
}

int main() {
	freopen("../APAC 2015 Round A/B-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round A/B-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d", &N);
		cin >> dir;
		rep(i, 0, N)
		rep(j, 0, N)
			scanf("%d", &mt[i][j]);
		solve(i + 1);
	}
	return 0;
}