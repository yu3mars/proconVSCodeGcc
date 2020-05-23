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
    ll k,n;
    cin>>k>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll mi=k+a[0]-a[n-1];
    for (int i = 0; i < n-1; i++)
    {
        mi=max(mi, a[i+1]-a[i]);
    }
    cout<<k-mi<<endl;
    
    return 0;
}