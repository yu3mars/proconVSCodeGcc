#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

static const ll NIL=-1;
static const ll INF=__LONG_LONG_MAX__/3;
static const ll WHITE=0;
static const ll GRAY=1;
static const ll BLACK=2;

vector<pll> ls[100010];
ll color[100010];
ll d[100010],p[100010];
ll n;

void dijkstra(ll s)
{
    for(ll i = 0; i < n; i++)
    {
        color[i]=WHITE;
        p[i]=-1;
        d[i]=INF;
    }
    d[s]=0;
    priority_queue<pii,vector<pll>,greater<pll>> pq; //cost, to
    pq.push(make_pair(0,0));

    while(pq.empty()==false){
        pii f = pq.top();
        pq.pop();
        ll u = f.second;
        color[u]=BLACK;
        if(d[u]<f.first) continue;

        for(ll j = 0; j < ls[u].size(); j++)
        {
            ll v = ls[u][j].second;
            ll c = ls[u][j].first;
            if(color[v]!=BLACK && d[u]+c<d[v])
            {
                d[v]=d[u]+c;
                color[v]=GRAY;
                pq.push(make_pair(d[v],v));
            }
        }
        
    }
}

int main(){
    m0(ls);
    m0(color);
    cin>>n;

    for (ll i = 0; i < n-1; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        ls[u].push_back(make_pair(w,v));
        ls[v].push_back(make_pair(w,u));
    }
    
    dijkstra(0);

    for (ll i = 0; i < n; i++)
    {
        cout<<d[i]%2<<endl;
    }
    
    
    return 0;
}