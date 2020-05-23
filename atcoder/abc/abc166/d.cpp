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
    ll x;
    cin>>x;

    for (ll l = 0; l < 1000; l++)
    {
        for (ll r = -1000; r < l; r++)
        {
            ll calc = pow(l,5)-pow(r,5);
            if(calc==x)
            {
                cout<<l<<" "<<r<<endl;
                return 0;
            }
        }
        
    }
    
    return 0;
}