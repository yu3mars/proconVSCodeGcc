#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll mod = 1e9+7;
ll dp[100010][13];

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    dp[0][0]=1;
    for (int i = 0; i < n; i++)
    {
        int c;
        if(s[i]=='?') c=-1;
        else c=s[i]-'0';
        for (int k = 0; k < 10; k++)
        {
            if(c!=-1 && c!=k) continue;
            for (int l = 0; l < 13; l++)
            {
                dp[i+1][(l*10+k)%13] += dp[i][l];
                dp[i+1][(l*10+k)%13]%=mod;
            }
        }
    }
    cout<<dp[n][5]<<endl;

    return 0;
}