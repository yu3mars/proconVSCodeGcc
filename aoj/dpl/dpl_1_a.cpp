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



int main(){
    int n,m;
    cin>>n>>m;
    vector<int> c(m);
    for(int i = 0; i < m; i++)
    {
        cin>>c[i];
    }

    int dp[100000];
    for(int i = 0; i <= n; i++)
    {
        dp[i]=__INT_MAX__/3;
    }
    dp[0]=0;
    for(int i = 0; i < m; i++)
    {
        for(int j = c[i]; j <= n; j++)
        {
            dp[j]= min(dp[j],dp[j-c[i]]+1);
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}