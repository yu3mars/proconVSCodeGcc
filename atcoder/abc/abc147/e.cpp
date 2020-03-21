#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int dx2[2] = {1,0}, dy2[4] = {0,1};
int h,w;
bool dp[85][85][12890];

bool inside(int y,int x)
{
    return 0<=y && y<h && 0<=x && x<w;
}


int main()
{

    cin>>h>>w;
    vector<vector<int>> a(h);
    for (int hh = 0; hh < h; hh++)
    {
        for (int ww = 0; ww < w; ww++)
        {
            int aa;
            cin>>aa;
            a[hh].push_back(aa);
        }
    }
    for (int hh = 0; hh < h; hh++)
    {
        for (int ww = 0; ww < w; ww++)
        {
            int bb;
            cin>>bb;
            a[hh][ww]=abs(a[hh][ww]-bb);
        }
    }
    m0(dp);
    dp[0][0][a[0][0]]=true;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            for (int v = 0; v < 12805; v++)
            {
                if(dp[y][x][v]==true)
                {
                    for(int i=0;i<2;i++)
                    {
                        int nexty=y+dy2[i];
                        int nextx=x+dx2[i];
                        if(inside(nexty,nextx)==true)
                        {
                            dp[nexty][nextx][abs(v+a[nexty][nextx])]=true;
                            dp[nexty][nextx][abs(v-a[nexty][nextx])]=true;
                        }

                    }
                }
            }
        }
    }
    ll ans=-1;
    for (ll i = 0; i < 12850; i++)
    {
        if(dp[h-1][w-1][i]==true)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}