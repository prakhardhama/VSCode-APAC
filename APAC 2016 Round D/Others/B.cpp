#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>
 
#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>
 
#define MAX 100005
#define AMAX 1500
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int t,n,m,q;
LL v[1005],p[1005],h[1005],lo,hi,mi,ta,tb,tc;

bool go(LL a){
	ta=q;
	F1(b,0,n){
		if(p[b]==0)continue;
		tc=-1;
		F1(c,0,m){
			if(v[c]==0)continue;
			if((p[b]>0)^(v[c]>0)){
				tb=(abs(p[b])+abs(v[c])-1)/abs(v[c]);
				if(tb>a)continue;
				tb=abs(c-h[b]);
				if(tc==-1)tc=tb;
				else tc=min(tc,tb);
			}
		}
		//if(a==2)printf("! %d %lld %lld\n",b,tc,ta);
		if(tc==-1)return 0;
		//if(a==2)printf("! %d %lld %lld\n",b,tc,ta);
		if(tc>ta)return 0;
		//if(a==2)printf("! %d %lld %lld\n",b,tc,ta);
		ta-=tc;
	}
	return 1;
}

int main(){
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);
	scanf("%d",&t);
	F2(a,1,t){
		scanf("%d%d%d",&n,&m,&q);
		F1(b,0,m)scanf("%lld",&v[b]);
		F1(b,0,n)scanf("%lld%lld",&p[b],&h[b]);
		lo=0;
		hi=LLONG_MAX/2;
		while(lo<hi){
			mi=(lo+hi)/2;
			//printf("%lld %lld %lld\n",lo,hi,mi);
			if(!go(mi))lo=mi+1;
			else hi=mi;
			//printf("%lld %lld %lld\n",lo,hi,mi);
		}
		if(lo==LLONG_MAX/2)printf("Case #%d: IMPOSSIBLE\n",a);
		else printf("Case #%d: %lld\n",a,lo);
	}
	//system("pause");
    return 0;
}
