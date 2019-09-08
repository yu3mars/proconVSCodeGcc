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
    string s,t;
    cin>>s>>t;
    ll n = s.size();
    ll m = t.size();
    vector<ll> v[26];
    for (ll i = 0; i < n; i++)
    {
        v[s[i]-'a'].push_back(i);
    }
    for (ll i = 0; i < m; i++)
    {
        if(v[t[i]-'a'].size()==0) 
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    
    ll syukai = 0;
    ll pnt = 0;
    for (ll i = 0; i < m; i++)
    {
        ll nowc = t[i]-'a';
        auto it = lower_bound(all(v[nowc]), pnt);
        if(it==v[nowc].end())
        {
            syukai++;
            it = lower_bound(all(v[nowc]), 0);
        }
        pnt = *it;
        pnt++;
        if(pnt>=n)
        {
            syukai++;
            pnt%=n;
        }
        //cout<<i<<":\t"<<pnt<<endl;
    }
    

    cout<<syukai*n+pnt<<endl;

    return 0;
}
