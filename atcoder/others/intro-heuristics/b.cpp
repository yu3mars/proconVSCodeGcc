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

ll d;
vector<ll> c;
vector<vector<ll>> s;
vector<ll> t;

int main()
{
    cin>>d;
    c.resize(d);
    for (int i = 0; i < d; i++)
    {
        cin>>c[i];
    }
    s.resize(d, vector<ll>(26));
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cin>>s[i][j];
        }
    }
    t.resize(d);
    for (int i = 0; i < d; i++)
    {
        cin>>t[i];
    }
    
    
    return 0;
}