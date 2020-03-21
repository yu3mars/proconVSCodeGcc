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
    std::cout << std::fixed;
    std::cout << std::setprecision(8);

    ll n,k;
    ll mx=0,tmp=0;
    cin>>n>>k;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
        p[i]++;
    }

    for (int i = 0; i < k; i++)
    {
        tmp+=p[i];
    }
    mx=tmp;
    
    for (int i = k; i < n; i++)
    {
        tmp=tmp+p[i]-p[i-k];
        mx=max(mx,tmp);
    }
    
    cout<<(double)mx/2.0<<endl;
    
    return 0;
}