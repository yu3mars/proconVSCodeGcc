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
    vector<ll> l(n);
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
    }
    sort(all(l));
    //a<=b kakutei
    //b-a<c
    //c<a+b
    for (ll bi = 0; bi < n; bi++)
    {
        for (ll ai = 0; ai < bi; ai++)
        {
            ll a=l[ai];
            ll b=l[bi];
            auto cimax = lower_bound(all(l),a+b);
            //cout<<a<<"\t"<<b<<"\t"<<cimax-(l.begin())<<endl;
            //cout<<cimax-(l.begin())-bi-1<<endl;;
            //cout<<a<<"\t"<<b<<"\t"<<chmax<<"\t"<<chmin<<endl;
            ans+=cimax-(l.begin())-bi-1;            
        }
        
    }
    
    cout<<ans<<endl;
    return 0;
}