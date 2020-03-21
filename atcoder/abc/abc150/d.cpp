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


int main()
{
    int n,k;
    int r,s,p;
    string t;
    cin>>n>>k;
    cin>>r>>s>>p;
    cin>>t;
    vector<bool> v(n);
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        if(i<k || t[i]!=t[i-k] || v[i-k]==false)
        {
            char c=t[i];
            if(c=='r')
            {
                ans+=p;
            }
            else if(c=='s')
            {
                ans+=r;
            }
            else if(c=='p')
            {
                ans+=s;
            }
            v[i]=true;
        }
    }
    cout<<ans<<endl;

    return 0;
}