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
    std::cout << std::setprecision(10);
    ll n;
    cin>>n;
    vector<ll> x(n),y(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];
    }
    double ans=0;
    double cnt=n*(n-1)/2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ans+=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
        }
    }
    ans=ans/cnt*(n-1);
    cout<<ans<<endl;
    
    return 0;
}