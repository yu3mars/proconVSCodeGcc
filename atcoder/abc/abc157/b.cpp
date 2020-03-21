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
    int aa,bb,m;
    cin>>aa>>bb>>m;
    vector<int> a(aa),b(bb);
    for (int i = 0; i < aa; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < bb; i++)
    {
        cin>>b[i];
    }

    int amin=a[0],bmin=b[0];
    for (int i = 0; i < aa; i++)
    {
        amin=min(amin,a[i]);
    }
    for (int i = 0; i < bb; i++)
    {
        bmin=min(bmin,b[i]);
    }
    
    int ans=amin+bmin;
    for (int i = 0; i < m; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        x--;
        y--;
        ans=min(ans,a[x]+b[y]-c);
    }
    cout<<ans<<endl;
    
    return 0;
}