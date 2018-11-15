#include <stdio.h>

long long cat;
long long par[201][201];

void add(long long &a, long long b)
{
	a += b;
	if (a >= 2000000000000000000ll)
		a = 2000000000000000000ll;
}

int main()
{
	freopen ("D-large-practice.in","r",stdin);
	freopen ("D-large-practice.out","w",stdout);

	par[1][1] = 1;
	for (int i=2;i<=200;i++){
		for (int j=0;j<i;j++){
			add(par[i][j+1],par[i-1][j]);
			if (j) add(par[i][j-1],par[i-1][j]);
		}
	}

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		int n; long long k;
		scanf ("%d %lld",&n,&k); n *= 2;

		if (par[n][0] < k){
			puts("Doesn't Exist!");
			continue;
		}

		k--;
		int u = 0;
		for (int i=0;i<n;i++){
			if (k < par[n-i-1][u+1]){
				printf ("("); u++;
			}
			else{
				printf (")");
				k -= par[n-i-1][u+1], u--;
			}
		}
		puts("");
	}

	return 0;
}
