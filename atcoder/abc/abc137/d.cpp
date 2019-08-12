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

vector<ll> v[100010];
priority_queue<ll> pq;

int main()
{
    ll n,m,ans=0;
    cin>>n>>m;

    for (ll i = 0; i < n; i++)
    {
        ll aa,bb;
        cin>>aa>>bb;
        aa--;
        v[aa].push_back(bb);
    }
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < v[i].size(); j++)
        {
            pq.push(v[i][j]);
        }
        if(pq.size()>0)
        {
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<endl;

    return 0;
}