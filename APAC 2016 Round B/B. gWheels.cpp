#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pll;

int T, Np, Ne, Nt;
vi p, e, t;

ll gcd(ll a, ll b) {
	return (b == 0) ? a : gcd(b, a%b);
}

void solve(int tc) {
	int M;
	multimap<pll, int> mp;
	rep(i, 0, Np)
	rep(j, 0, Ne) {
		ll u = p[i], v = e[j];
		ll g = gcd(u, v);
		u /= g, v /= g;
		mp.insert(pair<pll, int>(pll(u, v), j));
	}
	
	scanf("%d", &M);
	printf("Case #%d:\n", tc);
	rep(i, 0, M) {
		ll p, q;
		scanf("%lld %lld", &p, &q);
		ll g = gcd(p, q);
		p /= g, q /= g;
		bool flag = false;
		rep(j, 0, Ne)
		if(!flag)
		rep(k, 0, Nt) {
			ll u=t[k], v=e[j];
			u *= p, v *= q;
			ll g = gcd(u, v);
			u /= g, v /= g;
			auto itse = mp.equal_range(pll(u, v));
			for (auto it = itse.first; it != itse.second; ++it)
				if (it->second != j) { flag = true; break; }
			if (flag) break;
		}
		flag ? printf("Yes\n") : printf("No\n");
	}
}

int main() {
	freopen("../APAC 2016 Round B/B-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round B/B-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d %d %d", &Np, &Ne, &Nt);
		p.resize(Np); e.resize(Ne); t.resize(Nt);
		rep(j, 0, Np) scanf("%d", &p[j]);
		rep(j, 0, Ne) scanf("%d", &e[j]);
		rep(j, 0, Nt) scanf("%d", &t[j]);
		solve(i + 1);
	}
	return 0;
}
