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
    ll n,sum=0;
    cin>>n;
    vector<ll> a(n);
    unordered_map<ll,ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        sum+=a[i];
    }
    ll q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        ll b,c;
        cin>>b>>c;

        int cnt=mp[b];
        mp[c]+=cnt;
        mp.erase(b);
        sum+=(c-b)*cnt;
        cout<<sum<<endl;
    }
    
    
    return 0;
}