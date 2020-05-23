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
    ll n,ans=0;
    cin>>n;
    priority_queue<pll> a;
    for (ll i = 0; i < n; i++)
    {
        ll aa;
        cin>>aa;
        auto pp=make_pair(aa,i);
        a.push(pp);
    }
    ll l=0,r=n-1;
    while (a.size()>0)
    {
        auto t=a.top();
        a.pop();
        if(abs(t.second-l)>=abs(t.second-r))
        {
            ans+=t.first*abs(t.second-l);
            l++;
        }
        else
        {
            ans+=t.first*abs(t.second-r);
            r--;
        }
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}