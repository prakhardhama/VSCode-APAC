#include<bits/stdc++.h>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

double PI = acos(-1);
double G = 9.8;

int T, V, D;

void solve(int tc) {
	double val = double(D*G) / (V*V), theta;
	printf("Case #%d: ", tc);
	if (val > 1.0 || val < 0.0) puts("nan");
	else theta = 0.5*asin(val)*180/PI, printf("%.7lf\n", theta);
}

int main() {
	freopen("../APAC 2016 Practice/B-small-practice.in", "r", stdin);
	freopen("../APAC 2016 Practice/B-small-practice.out", "w", stdout);
	scanf("%d", &T);
	rep(tc, 1, T + 1) {
		scanf("%d %d\n", &V, &D);
		solve(tc);
	}
	return 0;
}