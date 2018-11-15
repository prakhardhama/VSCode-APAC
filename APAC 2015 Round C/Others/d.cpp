// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define IOS ios_base::sync_with_stdio(false)

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front


// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;
#endif

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 105

bool mp[MAX][MAX];
bool tmp[MAX][MAX];
int w, h;
bool gameover;

vector<PII> Ts[7] =
{
    { // 1
        {0, 0},
        {1, 0},
        {1, 1},
        {2, 1},
    },
    { // 2
        {0, 1},
        {1, 0},
        {1, 1},
        {2, 0},
    },
    { // 3
        {0, 0},
        {1, 0},
        {2, 0},
        {2, 1},
    },
    { // 4
        {0, 1},
        {1, 1},
        {2, 0},
        {2, 1},
    },
    { // 5
        {0, 0},
        {1, 1},
        {0, 1},
        {1, 0},
    },
    { // 6
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
    },
    { // 7
        {0, 1},
        {1, 0},
        {1, 1},
        {1, 2},
    }
};

vector<PII> rotation(vector<PII> vec)
{
    int n = 0, m = 0;
    for (const auto& p : vec)
    {
        n = max(p.first, n);
        m = max(p.second, m);
    }
    for (auto& p : vec)
    {
        int x = p.first, y = p.second;

        p = MP(m - y, x);
    }
    return vec;
}

void print(int sh)
{
    for (int i = sh; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
            printf("%c", mp[i][j] ? 'x' : '.');
        printf("\n");
    }
}

bool touch(const vector<PII> &tet, int x, int y)
{
    for (const auto& p : tet)
    {
        if (p.first + y >= h) return true;
        if (mp[p.first + y][p.second + x]) return true;
    }
    return false;
}

void clear()
{
    int newh = h - 1;
    for (int i = h - 1; i >= 0; --i)
    {
        bool check = true;
        for (int j = 0; j < w; ++j)
            check &= mp[i][j];

        if (not check)
            memcpy(tmp[newh--], mp[i], MAX);
    }
    for (int i = 0; i <= newh; ++i)
        memset(tmp[i], 0, MAX);
    memcpy(mp, tmp, sizeof(tmp));
}

void appgameover(int t, int r, int x)
{
    vector<PII> tetro = Ts[t];
    for (int i = 0; i < r; ++i)
        tetro = rotation(tetro);

    int y = 0;
    for (y = 0; not touch(tetro, x, y); ++y);
    --y;

    for (const auto& p : tetro)
    {
        mp[p.first + y][p.second + x] = true;
        assert(p.first + y < h);
        assert(p.second + x < w);
    }

    //print(0);
    //printf("\n");

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < w; ++j)
            if (mp[i][j])
                gameover = true;

    clear();

}


int main()
{
    freopen ("D-small-practice.in","r",stdin);
	freopen ("D-small-practice.out","w",stdout);
    int z;
    scanf("%d", &z);
    for (int zi = 1; zi <= z; ++zi)
    {
        int n;
        scanf("%d %d %d", &w, &h, &n);

        h += 4;

        memset(mp, 0, sizeof(mp));
        gameover = false;
        while (n--)
        {
            int t, r, x;
            scanf("%d %d %d", &t, &r, &x);

            if (not gameover)
                appgameover(t - 1, r, x);
        }

        printf("Case #%d:\n", zi);
        if (not gameover)
            print(4);
        else
            printf("Game Over!\n");
    }
}

