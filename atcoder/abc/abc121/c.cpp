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
    ll n,m,ans=0;
    cin>>n>>m;
    vector<pll> v(n);
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        v[i]=make_pair(a,b);
    }
    sort(all(v));
    int bought=0;
    for(int i = 0; i < n; i++)
    {
        if(bought>=m) break;
        if(v[i].second>=(m-bought))   // koko de kaiowaru
        {
            ans+=v[i].first*(m-bought);
            break;
        }
        else
        {
            bought+=v[i].second;
            ans+=v[i].first*v[i].second;
        }
        
    }
    
    
    cout<<ans<<endl;
    return 0;
}