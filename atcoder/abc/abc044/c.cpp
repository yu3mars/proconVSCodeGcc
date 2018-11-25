#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    int n,a;
    cin>>n>>a;
    vector<int> x(n);
    ll ans=0;
    
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    ll dp[55][55][2560];//mita(m) eranda(e) wa(w)
    m0(dp);
    dp[0][0][0]=1;
    
    for(int m = 0; m < n; m++)
    {
        
        for(int e = 0; e < n; e++)
        {
            for(int w = 0; w <= 2500; w++)
            {
                dp[m+1][e][w]+=dp[m][e][w];
                dp[m+1][e+1][w+x[m]]+=dp[m][e][w];
            }
        }
    }
    
    for(int e = 1; e <= n; e++)
    {
        ans+=dp[n][e][e*a];
    }
    

    cout<<ans<<endl;
    return 0;
}