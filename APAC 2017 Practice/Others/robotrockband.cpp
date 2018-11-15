#include<stdio.h>
#include<map>
using namespace std;
int a[1005],b[1005],c[1005],d[1005];
map<int,long long int> m;

int main()
{
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	int t,T,n,i,j,k,l,x;
	long long int ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		m.clear();
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=0;i<n;i++)
			scanf("%d",&c[i]);
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				m[c[i]^d[j]]++;
		
		ans=0;	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				x=a[i]^b[j]^k;
					if(m.find(x)!=m.end())
						ans+=m[x];
			}
		}
		printf("Case #%d: %lld\n",t,ans);
	}
	
	return 0;
}
