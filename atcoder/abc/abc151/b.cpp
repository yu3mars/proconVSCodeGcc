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
    ll n,k,m,asum=0;
    cin>>n>>k>>m;
    vector<ll> a(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin>>a[i];
        asum+=a[i];
    }
    
    ll need = n*m-asum;
    if(need<=0)
    {
        cout<<0<<endl;
    }
    else if(need>k)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<need<<endl;
    }
    
    
    return 0;
}