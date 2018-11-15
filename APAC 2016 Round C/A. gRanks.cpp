#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef vector<int> vi;
typedef pair<string, int> si;

int T, P, N, M;
int score[101];

map<string, vi> mp;
vector<si> stand;

bool stand_cmp(si a, si b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

void solve(int tc) {
	for (auto it : mp) {
		//cout << it.first << ": ";
		//for (auto s : it.second) printf("%d ", s); printf("\n");
		string name = it.first;
		vi arr = it.second;
		sort(arr.begin(), arr.end(), greater<int>());
		int s = 0;
		for (int j = 0; j < M && j < arr.size(); ++j) s += arr[j];
		stand.push_back(si(name, s));
	}
	sort(stand.begin(), stand.end(), stand_cmp);
	printf("Case #%d:\n", tc);
	int k = 1;
	rep(i, 0, stand.size()) {
		if (!i || stand[i].second < stand[i - 1].second) k = i + 1;
		printf("%d: ", k);
		cout << stand[i].first << endl;
	}
}

int main() {
	freopen("../APAC 2016 Round C/A-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round C/A-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		mp.clear(); stand.clear();
		scanf("%d", &P);
		rep(j, 0, P) scanf("%d", &score[j]);
		scanf("%d", &N);
		rep(j, 0, N) {
			int weight;
			scanf("%d", &weight);
			string name;
			rep(k, 0, P) {
				cin >> name;
				mp[name].push_back(weight*score[k]);
			}
		}
		scanf("%d", &M);
		solve(i + 1);
	}
	return 0;
}