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
    ll n,m,waans=0,acans=0;
    cin>>n>>m;
    vector<int> wa(n+1);
    vector<bool> ac(n+1);
    for (int i = 0; i < m; i++)
    {
        int p;
        string s;
        cin>>p>>s;
        if(s=="WA")
        {
            wa[p]++;
        }
        else
        {
            if(ac[p]==false)
            {
                ac[p]=true;
                waans+=wa[p];
                acans++;
            }
        }
    }
    cout<<acans<<" "<<waans<<endl;
    
    return 0;
}