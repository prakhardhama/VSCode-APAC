#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <deque>
#include <thread>

using namespace std;

long long gcd(long long a, long long b){
	while(b){
		auto t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int isprime[200];

int main()
{
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	
	for (int i = 1; i < 200 ;i++) isprime[i] = 1;
	for (int i = 2; i < 200; i++) {
		if (isprime[i] == 0) continue;
		for (int j = i * 2; j < 200; j+=i) isprime[j] = 0;
	}
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		fprintf(stderr, "Case #%d processing\n", testcase);
		printf("Case #%d: ",testcase);
		long long n, backup;
		scanf("%lld",&n);
		backup = n;
		vector<long long> factors;
		for (long long i = 2; i <= n/i; i++) {
			if (n%i) continue;
			long long cur = 1;
			while(n % i == 0) {
				n /= i;
				cur *= i;
			}
			factors.push_back(cur);
		}
		if (n > 1) {
			factors.push_back(n);
			n = 1;
		}
		vector<int> dp(1<<factors.size());
		for (int i = 0; i < (1<<factors.size()); i++) {
			long long curnum = 1;
			for (int j = 0; j < factors.size(); j++) {
				if (i & (1<<j)) {
					curnum *= factors[j];
				}
			}
			int digitsum = 0;
			while(curnum) {
				digitsum += curnum % 10;
				curnum /= 10;
			}
			if (isprime[digitsum]) {
				dp[i] = 0; // lose position
			} else {
				dp[i] = 0;
				for (int j = 0; j < factors.size(); j++) {
					if (i & (1<<j)) {
						if (dp[i^(1<<j)] == 0) {
							dp[i] = 1;
							break;
						}
					}
				}
			}
		}
		puts(!dp.back() ? "Seymour" : "Laurence");
	}
	return 0;
}
