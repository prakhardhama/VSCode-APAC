#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)
#define per($, b, a) for(int $=(b); $>=(a); --$)
typedef long long ll;
double EPS = 1e-11;

int T, M;
int arr[105];

long double func(long double x) {
	double s = 0.0, r = 1.0 + x, k = 1.0;
	per(i, M - 1, 0) {
		if (!i) s -= arr[i] * k;
		else s += arr[i] * k;
		k *= r;
	}
	return s;
}

double bisection() {
	double low = -1.0, high = 1.0;
	int iter = 0;
	while (iter++<50) {
		double mid = (low + high) / 2.0;
		double fl, fm;
		fl = func(low); fm = func(mid);
		if (signbit(fl) == signbit(fm)) low = mid;
		else high = mid;
	}
	return (low + high) / 2.0;
}

void solve(int tc) {
	//printf("M: %d\n", M);
	//rep(i, 0, M) printf("%lld ", arr[i]); puts("");
	double ans = bisection();
	//if (fabs(1 - ans) < EPS) ans = 1.0 - EPS;
	//else if (fabs(ans + 1) < EPS) ans = -1.0 + EPS;
	printf("Case #%d: %.12Lf\n", tc, ans);
}

int main() {
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(i, 0, T) {
		scanf("%d", &M); ++M;
		rep(j, 0, M) scanf("%d", &arr[j]);
		solve(i + 1);
	}
	return 0;
}