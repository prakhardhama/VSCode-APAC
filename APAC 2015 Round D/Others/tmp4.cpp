#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
#define KING 0
#define QUEEN 1
#define ROOK 2
#define BISHOP 3
#define KNIGHT 4
#define PAWN 5
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
int bdx[8]={2,2,1,1,-1,-1,-2,-2};
int bdy[8]={1,-1,2,-2,2,-2,1,-1};
int pdx[2]={1,1};
int pdy[2]={1,-1};
int d[22][22];
int an;
bool Out(int x,int y){
    return x<=0||y<=0||x>8||y>8;
}
void KK(int x,int y){
    REP(i,8){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(d[nx][ny]>=0)an++;
    }
}
void QQ(int x,int y){
    REP(i,8){
        int nx=x+dx[i];
        int ny=y+dy[i];
        while(!Out(nx,ny)){
            if(d[nx][ny]>=0){
                an++;
                break;
            }
            nx+=dx[i];
            ny+=dy[i];
        }
    }
}
void RR(int x,int y){
    REP(i,4){
        int nx=x+dx[i];
        int ny=y+dy[i];
        while(!Out(nx,ny)){
            if(d[nx][ny]>=0){
                an++;
                break;
            }
            nx+=dx[i];
            ny+=dy[i];
        }
    }
}
void BB(int x,int y){
    REPP(i,4,8){
        int nx=x+dx[i];
        int ny=y+dy[i];
        while(!Out(nx,ny)){
            if(d[nx][ny]>=0){
                an++;
                break;
            }
            nx+=dx[i];
            ny+=dy[i];
        }
    }
}
void NN(int x,int y){
    REP(i,8){
        int nx=x+bdx[i];
        int ny=y+bdy[i];
        if(Out(nx,ny))continue;
        if(d[nx][ny]>=0)an++;
    }
}
void PP(int x,int y){
    REP(i,2){
        int nx=x+pdx[i];
        int ny=y+pdy[i];
        if(Out(nx,ny))continue;
        if(d[nx][ny]>=0)an++;
    }
}
int main(){
    freopen ("D-lareg-practice.in","r",stdin);
	freopen ("D-large-practice.out","w",stdout);
    map<char,int>to;
    to['K']=KING;
    to['Q']=QUEEN;
    to['R']=ROOK;
    to['B']=BISHOP;
    to['N']=KNIGHT;
    to['P']=PAWN;
    CASET{
        an=0;
        DRI(n);
        MS1(d);
        char s[111];
        REP(i,n){
            RS(s);
            d[s[0]-'A'+1][s[1]-'0']=to[s[3]];
        }
        REPP(x,1,9)REPP(y,1,9){
            if(d[x][y]==KING)KK(x,y);
            if(d[x][y]==QUEEN)QQ(x,y);
            if(d[x][y]==ROOK)RR(x,y);
            if(d[x][y]==BISHOP)BB(x,y);
            if(d[x][y]==KNIGHT)NN(x,y);
            if(d[x][y]==PAWN)PP(x,y);
        }
        printf("Case #%d: %d\n",case_n++,an);
    }
    return 0;
}
