#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int n,ma,mb;
    cin>>n>>ma>>mb;
    static int dp[45][420][420];
    int inf = 1e9;
    
    for(int i = 0; i < 45; i++)
    {
        
        for(int j = 0; j < 420; j++)
        {
            
            for(int k = 0; k < 420; k++)
            {
                dp[i][j][k]=inf;
            }
            
        }
        
    }
    dp[0][0][0]=0;
    
    
    for(int drug = 0; drug < n; drug++)
    {
        int a,b,c;
        cin >>a>>b>>c;
        
        for(int ia = 0; ia < 402; ia++)
        {
            
            for(int ib = 0; ib < 402; ib++)
            {
                dp[drug+1][ia][ib]=min(dp[drug+1][ia][ib], dp[drug][ia][ib]);
                dp[drug+1][ia+a][ib+b]=min(dp[drug+1][ia+a][ib+b], dp[drug][ia][ib] +c);
            }            
        }
    }
    int ans = inf;
    
    for(int i = 1; ; i++)
    {
        if(ma*i >400 || mb*i>400) break;
        ans=min(ans,dp[n][ma*i][mb*i]);
    }
    if(ans==inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    
    return 0;
}