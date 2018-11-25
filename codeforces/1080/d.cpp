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
    int t;
    cin>>t;
    vector<ll> n2,mi,ma;
    n2.push_back(1);
    mi.push_back(0);
    ma.push_back(0);
    
    for(ll i = 0; i < (ll)(1e9)+10; i++)
    {
        n2.push_back(n2[i]*2);
        
    }
    
    
    for(int tt = 0; tt < t; tt++)
    {
        ll n,k;
        cin>>n>>k;

    }

    return 0;
}