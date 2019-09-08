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

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> dp(n+10);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(i==0)
        {
            dp[0]=1;
        }
        else
        {
            if(s[i]!=s[i-1] || cnt>0)
            {
                dp[i]=dp[i-1]+1;
                if(cnt>0) cnt--;
            }
            else
            {
                dp[i]=dp[i-1];
                cnt=2;
            }
        }
    }
    cout<<dp[n-1]<<endl;
    
    return 0;
}