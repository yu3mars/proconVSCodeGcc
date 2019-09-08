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

vector<ll> gTmp[200010], g[200010];
ll ans[200010], pls[200010];


int main()
{
    m0(ans);
    ll n,q;
    cin>>n>>q;    

    for (int i = 0; i < n-1; i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        gTmp[a].push_back(b);
        gTmp[b].push_back(a);
    }
    unordered_set<ll> se;
    se.insert(0);
    queue<ll> qGraph;
    qGraph.push(0);
    while (qGraph.size()>0)
    {
        ll now = qGraph.front();
        qGraph.pop();
        for (int i = 0; i < gTmp[now].size(); i++)
        {
            ll next = gTmp[now][i];
            if(se.find(next)==se.end()) //mada yattenai
            {
                se.insert(next);
                qGraph.push(next);
                g[now].push_back(next);
            }
        }
    }
    
    for (int i = 0; i < q; i++)
    {
        ll p,x;
        cin>>p>>x;
        p--;
        pls[p]+=x;
    }

    queue<ll> qCalc;
    qCalc.push(0);
    while (qCalc.size()>0)
    {
        ll now = qCalc.front();
        qCalc.pop();
        ans[now]=pls[now];
        for (int i = 0; i < g[now].size(); i++)
        {
            ll next = g[now][i];
            qCalc.push(next);
            pls[next]+=pls[now];
        }

    }
    
    for (int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
    
    return 0;
}