#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)

int T, N;
string seg[101];

string led[] = { "1111110", "0110000", "1101101", "1111001", "0110011",
				 "1011011", "1011111", "1110000", "1111111", "1111011" };

void solve(int tc) {
	int ans = -1, cnt = 0, cur;
	string temp, broken, b, fconf;
	bool f, fO;
	
	rep(k, 0, 10) {
		b = "0000000"; f = true; temp = seg[0];
		rep(l, 0, 7)
			if (temp[l] == '1' && (b[l] == '1' || led[k][l] == '0')) { f = false; break; }
			else if (temp[l] == '0' && led[k][l] == '1' && b[l] == '2') { f = false; break; }
		if (!f) continue;
		rep(l, 0, 7)
			if (temp[l] == '0' && led[k][l] == '1') b[l] = '1';
			else if (temp[l] == '1') b[l] = '2';
		//printf("\nfirst match %d temp %s ledk %s b %s\n", k, temp.c_str(), led[k].c_str(), b.c_str());

		cur = (k - 1 + 10) % 10;
		fO = true;
		rep(i, 1, N) {
			temp = seg[i];
			f = true;
			rep(l, 0, 7)
				if (temp[l] == '1' && (b[l] == '1' || led[cur][l] == '0')) { f = false; break; }
				else if (temp[l] == '0' && led[cur][l] == '1' && b[l] == '2') { f = false; break; }
			if (!f) { fO = false; break; }
			//printf("match %d temp %s ledk %s\n", cur, temp.c_str(), led[cur].c_str());

			rep(l, 0, 7)
				if (temp[l] == '0' && led[cur][l] == '1') b[l] = '1';
				else if (temp[l] == '1') b[l] = '2';
			cur = (cur - 1 + 10) % 10;
		}
		if (!fO) continue;
		//printf("found match! broken %s\n", b.c_str());

		ans = cur; broken = b;
		temp = led[ans];
		rep(l, 0, 7)
			if (broken[l] == '0' && led[ans][l] == '1') { cnt = '2'; break; }
			else if (broken[l] == '1') temp[l] = '0';
		if (!cnt) fconf = temp, ++cnt;
		else if (fconf != temp) { cnt = 2; break; }
	}
	//printf("cnt %d ans %d broken %s\n", cnt, ans, broken.c_str());
	printf("Case #%d: ", tc);
	if (cnt > 1) puts("ERROR!"); 
	else printf("%s\n", fconf.c_str());
}

int main() {
	freopen("../APAC 2015 Round A/A-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round A/A-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d", &N);
		rep(i, 0, N) cin >> seg[i];
		solve(tc);
	}
	return 0;
}