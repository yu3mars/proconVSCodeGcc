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

vector<ll> div(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i*i <= n; i++)
    {
        if(n%i==0)
        {
            ret.push_back(i);
            if(i*i!=n)
			{
				ret.push_back(n/i);
			}
        }
    }
    return ret;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll sum=0;
    ll ans=1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(all(a));
    if(k>=(sum-a[n-1]))
    {
        //ans=sum;
    }
    auto yakusuu = div(sum);
    sort(all(yakusuu));
    reverse(all(yakusuu));
    
    for (int ii = 0; ii < yakusuu.size(); ii++)
    {
        ll d = yakusuu[ii];
        //cout<<d<<endl;//

        vector<pll> v(n);
        for (int i = 0; i < n; i++)
        {
            ll mod = a[i]%d;
            v[i]=make_pair((d-mod)%d, mod);
        }
        sort(all(v));
        ll mae=0, usiro=n-1;
        ll plus=0, minus=0;
        while (mae<=usiro)
        {
            if(plus<=minus)
            {
                plus+=v[mae].first;
                mae++;
            }
            else
            {
                minus+=v[usiro].second;
                usiro--;
            }
        }
        if(plus==minus && plus<=k)
        {
            ans=d;
            break;
        }
        
    }
    
    
    cout<<ans<<endl;
    return 0;
}