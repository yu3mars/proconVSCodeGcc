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
ll dp[710][710];

// Combination Table 
ll C[10010][10010]; // C[n][k] -> nCk 

void comb_table (int N)
{ 
    for (int i = 0 ;i <= N; i++)
    { 
        for (int j = 0 ;j <= i; j++)
        { 
            if (j == 0 or j == i)
            {
                C[i][j] = 1LL; 
            }
            else
            { 
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%mod; 
            } 
        } 
    } 
}


int main()
{
    int t;
    ll ans=0;
    cin>>t;
    ll x[500];
    m0(x);
    
    for(int i = 0; i < t; i++)
    {
        cin>>x[i];
    }
    comb_table(10000);

    m0(dp);
    
    for(int now = 1; now < 400; now++)
    {
        for(int befcnt = 0; befcnt < 400; befcnt++)
        {
            for(int nowcnt = 0; nowcnt < x[now-1]; nowcnt++)
            {
                dp[now][befcnt+nowcnt]=
                (C[dp[now-1][befcnt]][befcnt]
                +C[x[now-1]][nowcnt]);
                dp[now][befcnt+nowcnt]%=mod;
            }            
        }      
    }
    
    
    for(int i = 0; i < 400; i++)
    {
        ans+=dp[i][1];
        ans%=mod;
    }
    
    
    cout<<ans<<endl;

    return 0;
}