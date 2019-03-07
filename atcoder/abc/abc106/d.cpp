#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int x[510][510], imos[510][510]; //l nomi ruiseki wa
int main()
{
    m0(x);
    m0(imos);
    int n,m,qqq;
    cin>>n>>m>>qqq;
    vector<int> l(m),r(m);

    for(int i = 0; i < m; i++)
    {
        cin>>l[i]>>r[i];
        x[l[i]][r[i]]++;
    }
    for(int li = 0; li < 505; li++)
    {
        for(int ri = 1; ri < 505; ri++)
        {
            imos[li][ri]=imos[li][ri-1]+x[li][ri];
        }
    }
    
    for(int qq = 0; qq < qqq; qq++)
    {
        int p,q;
        cin>>p>>q;
        int ans=0;
        for(int ll = p; ll <= q; ll++)
        {
            ans+=imos[ll][q]-imos[ll][p-1];
        }
        cout<<ans<<endl;
    }
    

    return 0;
}