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
    int n;
    cin>>n;
    int dp[100100];
    
    for(int i = 0; i <= n; i++)
    {
        dp[i]=i;
    }
    
    
    for(int mul = 6; mul <= n; mul*=6)
    {
        for(int i = 0; i+mul <= n; i++)
        {
            dp[i+mul]=min(dp[i+mul], dp[i]+1);
        }    
    }
        
    for(int mul = 9; mul <= n; mul*=9)
    {
        for(int i = 0; i+mul <= n; i++)
        {
            dp[i+mul]=min(dp[i+mul], dp[i]+1);
        }    
    }

    cout<<dp[n]<<endl;

    return 0;
}