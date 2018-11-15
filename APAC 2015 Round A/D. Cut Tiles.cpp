#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)
typedef pair<int, int> ii;

int T, N, M;
int inp[505];
multiset<ii> tiles;

void adjust(ii &tl) {
	if (tl.first > tl.second) swap(tl.first, tl.second);
}

int main() {
	freopen("../APAC 2015 Round A/D-large-practice.in", "r", stdin);
	freopen("../APAC 2015 Round A/D-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d", &N, &M);
		rep(i, 0, N) scanf("%d", &inp[i]);
		sort(inp, inp + N, greater<int>());
		int ans = 0;
		rep(i, 0, N) {
			int s = 1 << inp[i];
			auto ptr = lower_bound(tiles.begin(), tiles.end(), ii(s, s));
			ii box, box1, box2;
			if (ptr == tiles.end()) box = ii(M, M), ++ans;
			else box = *ptr, tiles.erase(ptr);
			box1.first = box.first - s; box1.second = box.second;
			box2.first = s; box2.second = box.second - s;
			adjust(box1); adjust(box2);
			if(box1.first) tiles.insert(box1); 
			if(box2.first) tiles.insert(box2);
		}
		tiles.clear();
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}