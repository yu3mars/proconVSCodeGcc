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
    cin>>n;
    vector<string> s(n);
    unordered_map<string, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
        sort(all(s[i]));
        mp[s[i]]++;
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ll val = i->second;
        ans+=val*(val-1)/2;
    }
    cout<<ans<<endl;

    return 0;
}