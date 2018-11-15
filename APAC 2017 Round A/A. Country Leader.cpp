#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)
typedef pair<int, string> pis;
typedef vector<pis> vpis;

int T, N;
string name[105];

vpis mp;
bool mp_cmp(pis a, pis b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

void solve(int tc) {
	//printf("N: %d\n", N);
	//rep(i, 0, N) cout << name[i] << endl;
	mp.clear();
	rep(i, 0, N) {
		set<char> ele;
		rep(j, 0, (int)name[i].size())
			if (name[i][j] != ' ') ele.insert(name[i][j]);
		mp.push_back(pis((int)ele.size(), name[i]));
	}
	sort(mp.begin(), mp.end(), mp_cmp);
	//rep(i, 0, N) cout << mp[i].first << " " << mp[i].second << endl;
	printf("Case #%d: ", tc);
	cout << mp[0].second << endl;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d\n", &N);
		rep(j, 0, N) {
			string str;
			getline(cin, str);
			name[j] = str;
		}
		solve(i + 1);
	}
	return 0;
}