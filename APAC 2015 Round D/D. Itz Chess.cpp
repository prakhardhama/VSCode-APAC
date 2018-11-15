#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

int T, N;
char chess[8][8];

int kill[8][8];
bool valid(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int X, Y, ans;
int dr[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dc[] = { 0, 0, -1, 1, 1, 1, -1, -1 };

void king() {
	int p, q;
	rep(i, 0, 8) {
		p = X + dr[i], q = Y + dc[i];
		if (!valid(p, q)) continue;
		if (chess[p][q] != '-') ++ans;
	}
}

void queen() {
	int p, q, k;
	rep(i, 0, 8) {
		k = 1;
		while (true) {
			p = X + k*dr[i], q = Y + k*dc[i];
			if (!valid(p, q)) break;
			if (chess[p][q] != '-') { ++ans; break; }
			k++;
		}
	}
}

void rook() {
	int p, q, k;
	rep(i, 0, 4) {
		k = 1;
		while (true) {
			p = X + k*dr[i], q = Y + k*dc[i];
			if (!valid(p, q)) break;
			if (chess[p][q] != '-') { ++ans; break; }
			k++;
		}
	}
}

void bishop() {
	int p, q, k;
	rep(i, 4, 8) {
		k = 1;
		while (true) {
			p = X + k*dr[i], q = Y + k*dc[i];
			if (!valid(p, q)) break;
			if (chess[p][q] != '-') { ++ans; break; }
			k++;
		}
	}
}

void knight() {
	int p, q;
	int kr[] = {-1, 1, -1, 1, -2, -2, 2, 2};
	int kc[] = {-2, -2, 2, 2, -1, 1, -1, 1};
	rep(i, 0, 8) {
		p = X + kr[i], q = Y + kc[i];
		if (!valid(p, q)) continue;
		if (chess[p][q] != '-') ++ans;
	}
}

void pawn() {
	int p, q;
	int pr[] = { 1, 1 };
	int pc[] = { -1, 1 };
	rep(i, 0, 2) {
		p = X + pr[i], q = Y + pc[i];
		if (!valid(p, q)) continue;
		if (chess[p][q] != '-') ++ans;
	}
}

void solve(int tc) {
	/*puts("chess");
	rep(i, 0, 8) {
		rep(j, 0, 8) printf("%c ", chess[i][j]);
		puts("");
	}*/
	ans = 0;
	rep(i, 0, 8)
	rep(j, 0, 8) {
		X = i, Y = j;
		switch (chess[i][j]) {
		case '-': break;
		case 'K': king(); break;
		case 'Q': queen(); break;
		case 'R': rook(); break;
		case 'B': bishop(); break;
		case 'N': knight(); break;
		case 'P': pawn(); break;
		}
	}
	printf("Case #%d: %d\n", tc, ans);
}

int main() {
	freopen("../APAC 2015 Round D/D-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round D/D-large-practice.out", "w", stdout);
	int x, y;
	string str;
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d", &N);
		fill(&chess[0][0], &chess[7][7] + 1, '-');
		rep(i, 0, N) {
			cin >> str;
			x = str[0] - 'A';
			y = str[1] - '1';
			chess[x][y] = str[3];
		}
		solve(tc);
	}
	return 0;
}