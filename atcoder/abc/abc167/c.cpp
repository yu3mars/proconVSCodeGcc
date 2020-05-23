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
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> c(n);
    vector<vector<int>> a(n);
    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
        a[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    for (int bit = 0; bit < (1<<n); bit++)
    {
        vector<int> know(m);
        int cost=0;
        for (int book = 0; book < n; book++)
        {
            if((bit&(1<<book))!=0)//use c[book]
            {
                cost+=c[book];
                for (int i = 0; i < m; i++)
                {
                    know[i]+=a[book][i];
                }
            }
        }
        bool ok=true;
        for (int i = 0; i < m; i++)
        {
            if(know[i]<x)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            ans=min(ans,cost);
        }
    }
    if(ans==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    
    
    return 0;
}