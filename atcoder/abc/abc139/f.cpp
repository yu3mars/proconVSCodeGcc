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

ll d(pll p)
{
    return p.first*p.first + p.second*p.second;
}

//  3
// 4|2
//5-0-1
// 6|8
//  7
int getSyogen(pll p)
{
    ll x=p.first,y=p.second;
    if(x==0&&y==0) return 0;
    else if(x>0 && y==0) return 1;
    else if(x>0 && y>0) return 2;
    else if(x==0 && y>0) return 3;
    else if(x<0 && y>0) return 4;
    else if(x<0 && y==0) return 5;
    else if(x<0 && y<0) return 6;
    else if(x==0 && y<0) return 7;
    else if(x>0 && y<<0) return 8;
}

int main()
{
    ll n;
    cin>>n;
    vector<pll> xy;
    for (int i = 0; i < n; i++)
    {
        ll xx,yy;
        cin>>xx>>yy;
        xy[i]=make_pair(xx,yy);
    }
    pll dp[110][9];
    for (int i = 0; i < 110; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            dp[i][j]=make_pair(0,0);
        }
        
    }
    
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 9; j++)
        {
            dp[i+1][j] = dp[i][j];
        }
        
        pll engine = xy[i];
        for (ll nowSyogen = 0; nowSyogen < 9; nowSyogen++)
        {
            pll nowPos = dp[i][nowSyogen];
            pll tempPos = nowPos;
            tempPos.first+=engine.first;
            tempPos.second+=engine.second;
            int movedSyogen = getSyogen(tempPos);
            pll nextPos = dp[i+1][movedSyogen];
            if(d(nextPos)<d(tempPos))
            {
                dp[i+1][movedSyogen] = tempPos;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < 9; i++)
    {
        if(ans<d(dp[n][i]))
        {
            ans=d(dp[n][i]);
        }
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(12);
    cout<<sqrt(ans)<<endl;

    return 0;
}