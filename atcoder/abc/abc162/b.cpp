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
    ans=(n+1)*n/2;
    ll m3=n-(n%3);
    ll m5=n-(n%5);
    ll m15=n-(n%15);
    
    ll kou3=(m3-0)/3;
    ll sum3=kou3*(3+m3)/2;

    ll kou5=(m5-0)/5;
    ll sum5=kou5*(5+m5)/2;

    ll kou15=(m15-0)/15;
    ll sum15=kou15*(15+m15)/2;

    ans=ans-sum3-sum5+sum15;

    //cout<<ans<<" "<<sum3<<" "<<sum5<<" "<<sum15<<endl;
    cout<<ans<<endl;
    
    return 0;
}