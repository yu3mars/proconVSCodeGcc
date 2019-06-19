#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};
ll mod=1e9+7;

int main()
{
    int n;
    cin>>n;
    ll dp[110][4][4][4];//A0 C1 G2 T3
    m0(dp);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if((i==0&&j==2&&k==1)
                    ||(i==0&&j==1&&k==2)
                    ||(i==2&&j==0&&k==1))
                {
                    continue;
                }
                else
                {
                    dp[3][i][j][k]=1;
                }
            }
        }
    }
    for(int now = 4; now <= n; now++)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    for(int l = 0; l < 4; l++)
                    {
                        if((j==0&&k==2&&l==1)
                            ||(j==0&&k==1&&l==2)
                            ||(j==2&&k==0&&l==1))
                        {
                            continue;
                        }
                        else if((i==0&&j==2&&l==1)
                            ||(i==0&&k==2&&l==1))
                        {
                            continue;
                        }
                        else
                        {
                            dp[now][j][k][l]+=dp[now-1][i][j][k];
                            dp[now][j][k][l]%=mod;
                        }
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                ans+=dp[n][i][j][k];
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}