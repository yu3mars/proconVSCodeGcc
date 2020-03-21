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

unordered_set<ll> usedColor[100010];
vector<ll> edge[100010];


int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n-1),b(n-1),color(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
        edge[a[i]].push_back(i);
        edge[b[i]].push_back(i);
    }
    for (int i = 0; i < n-1; i++)
    {
        color[i]=-1;
    }
    queue<ll> q;
    q.emplace(0);
    while (q.size()>0)
    {
        ll now =q.front();
        q.pop();
        
        //set children color
        ll nuruColor=0;
        for (int i = 0; i < edge[now].size(); i++)
        {
            ll nowEdge=edge[now][i];
            if(color[nowEdge]==-1)
            {
                ll next;
                if(b[nowEdge]==now) next=a[nowEdge];
                else next=b[nowEdge];
                while (usedColor[now].find(nuruColor)!=usedColor[now].end())
                {
                    nuruColor++;
                }
                
                color[nowEdge]=nuruColor;
                usedColor[now].insert(nuruColor);
                usedColor[next].insert(nuruColor);
                nuruColor++;
                q.emplace(next);
            }
        }
    }
    ll colorVari=1;
    for (int i = 0; i < n-1; i++)
    {
        color[i]++;
        colorVari=max(colorVari,color[i]);
    }
    cout<<colorVari<<endl;
    for (int i = 0; i < n-1; i++)
    {
        cout<<color[i]<<endl;
    }
        
    return 0;
}