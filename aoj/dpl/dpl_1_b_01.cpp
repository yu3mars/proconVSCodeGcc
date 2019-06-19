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

int dp[1010][10010];//item, weight

int main(){
    m0(dp);
    int n,wmax;
    cin>>n>>wmax;
    vector<int> v(n),w(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i]>>w[i];
    }

    int ans=0;
    for(int i = 0; i < n; i++)
    {
        for(int ww = 0; ww <= wmax; ww++)
        {
            if(ww<w[i])
            {
                dp[i+1][ww]=max(dp[i+1][ww],dp[i][ww]);
            }
            else
            {
                dp[i+1][ww]=max(max(dp[i+1][ww],dp[i][ww]), dp[i][ww-w[i]]+v[i]);
            }
            ans=max(ans,dp[i+1][ww]);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}