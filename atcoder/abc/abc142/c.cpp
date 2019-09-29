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
    ll n;
    cin>>n;
    vector<pll> p(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        p[i]=make_pair(a,i+1);
    }
    sort(all(p));
    for (int i = 0; i < n; i++)
    {
        if(i>0)cout<<" ";
        cout<<p[i].second;
    }
    cout<<endl;

    return 0;
}