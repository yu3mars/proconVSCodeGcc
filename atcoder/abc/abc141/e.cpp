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
    ll n,ans=0;
    string s;
    cin>>n>>s;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i+ans+1; j < n; j++)
        {
            ll tmp =0;
            ll len =0;
            while (s[j+len]==s[i+len] && i+len<j)
            {
                tmp++;
                len++;
                ans=max(ans,tmp);
            }
        }
        
    }
    

    cout<<ans<<endl;
    return 0;
}