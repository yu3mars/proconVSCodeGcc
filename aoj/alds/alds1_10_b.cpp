#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int dp[110][110];
int p[110];
int INF=INT_MAX/3;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>p[i]>>p[i+1];
    }
    for(int i = 0; i < 105; i++)
    {
        for(int j = 0; j < 105; j++)
        {
            if(i==j) dp[i][j]==0;
            else dp[i][j]=INF;
        }
    }
    for(int l = 2; l <= n; l++)
    {
        for(int i = 0; i+l <= n+1; i++)
        {
            int j = i+l-1;
            for(int k = i; k < j; k++)
            {
                dp[i][j]=min(dp[i][j],
                    dp[i][k]+dp[k+1][j]+p[k+1]*p[i]*p[j+1]);
            }
            
        }
    }
    
    cout<<dp[0][n-1]<<endl;
    
    return 0;
}