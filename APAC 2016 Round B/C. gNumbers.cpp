#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define MXP 40000000
typedef long long ll;
typedef vector<int> vi;

int T; ll N;
int gNumb[MXP];
int laurence[MXP];

bitset<MXP> sv;
vector<int> prime;
void init() {
	sv.set(); 
	for (ll i = 2; i < MXP; ++i)
		if (sv[i]) {
			prime.push_back((int)i);
			for (ll j = i*i; j < MXP; j += i) sv[j] = 0;
		}
	//printf("prime %d\n", prime.size());
	memset(gNumb, -1, sizeof(gNumb));
	memset(laurence, -1, sizeof(laurence));
	gNumb[1] = 1; laurence[1] = 0;
}

bool isGNumber(ll num) {
	if (num < MXP && gNumb[num] != -1) return gNumb[num] == 1;
	int s = 0; ll temp = num;
	while (temp) s += temp % 10, temp /= 10;
	bool pr = true;
	for (int i = 2; i*i <= s; ++i)
		if (s%i == 0) { pr = false; break; }
	if (num < MXP) gNumb[num] = pr ? 1 : 0;
	return pr;
}

int rec(ll num) {
	//printf("rec N: %lld\n", num);
	bool flag = isGNumber(num);
	if (flag) {
		if (num < MXP) laurence[num] = 0;
		//puts("N is gNumb!");
		return 0;
	}
	int idx = 0; ll pf = prime[0], temp = num;
	vector<ll> fact;
	while (pf*pf <= temp) {
		if (temp%pf == 0) fact.push_back(pf);
		while (temp%pf == 0) temp /= pf;
		pf = prime[++idx];
	}
	if (temp != 1) fact.push_back(temp);
	//printf("N %lld: ", num);
	//rep(i, 0, fact.size()) printf("%lld ", fact[i]); puts("fact");
	vector<ll> reduced;
	rep(i, 0, fact.size()) {
		temp = num;
		while (temp%fact[i] == 0) temp /= fact[i];
		reduced.push_back(temp);
	}
	flag = false;
	//printf("N %lld: ", num);
	//rep(i, 0, reduced.size()) printf("%lld ", reduced[i]); puts("reduced");
	rep(i, 0, reduced.size()) {
		temp = reduced[i];
		if (temp < MXP && laurence[temp] != -1) {
			if (!laurence[temp]) { flag = true; break; }
		}
		else if(!rec(temp)) { flag = true; break; }
	}
	if (num < MXP) laurence[num] = flag ? 1 : 0;
	//printf("laurence %lld: %d\n", N, flag ? 1 : 0);
	return flag ? 1 : 0;
}

void solve(int tc) {
	printf("Case #%d: ", tc);
	if (N < MXP && laurence[N] != -1) {
		if (laurence[N]) puts("Laurence");
		else puts("Seymour");
		return;
	}
	int ans = rec(N);
	if (ans) puts("Laurence");
	else puts("Seymour");
}

int main() {
	freopen("../APAC 2016 Round B/C-large-practice.in", "r", stdin);
	freopen("../APAC 2016 Round B/C-large-practice.out", "w", stdout);
	init();
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%lld", &N);
		fprintf(stderr, "solve %d\n", tc);
		solve(tc);
	}
}