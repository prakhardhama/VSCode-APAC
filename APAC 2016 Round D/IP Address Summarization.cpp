#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef pair<int, int> ii;
typedef pair<ii, ii> i4;
typedef pair<i4, int> i5;

int T, N;
int a, b, c, d, p;

set<i5> subs;

void norm() {
	int r = p, s[4], o, m;
	//printf("%d.%d.%d.%d/%d\n", a, b, c, d, p);
	rep(i, 0, 4) {
		int o = (i==0)? a : ((i==1)? b : ((i==2)? c : d));
		if (r >= 8) s[i] = o, r -= 8;
		else if (r == 0) s[i] = 0;
		else {
			m = (1<<8) - 1;
			m <<= (8-r);
			s[i] = m&o;
			bitset<8> bs(m); 
			//printf("mask r:%d m:%d %s\n o:%d s[%d]:%d\n", r, m, bs.to_string().c_str(), o, i, s[i]);
			r = 0;
		}
	}
	printf("- %d.%d.%d.%d/%d\n\n", s[0], s[1], s[2], s[3], p);
}

void solve(int tc) {
	string str;
	printf("Case #%d:\n", tc);
	rep(i, 0, N) {
		scanf("%d.%d.%d.%d/%d", &a, &b, &c, &d, &p);
		norm();
	}
	subs.clear();
}

int main() {
	freopen("../APAC 2016 Round D/IP Address Summarization.in", "r", stdin);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d\n", &N);
		solve(tc);
	}
	return 0;
}