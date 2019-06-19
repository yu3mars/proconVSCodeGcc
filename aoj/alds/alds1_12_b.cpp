#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

static const int NIL=-1;
static const int INF=INT_MAX/3;
static const int WHITE=0;
static const int GRAY=1;
static const int BLACK=2;

vector<pii> ls[10010];
int color[10010];
int d[10010],p[10010];
int n;

void dijkstra(int s)
{
    for(int i = 0; i < n; i++)
    {
        color[i]=WHITE;
        p[i]=-1;
        d[i]=INF;
    }
    d[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq; //cost, to
    pq.push(make_pair(0,0));

    while(pq.empty()==false){
        pii f = pq.top();
        pq.pop();
        int u = f.second;
        color[u]=BLACK;
        if(d[u]<f.first) continue;

        for(int j = 0; j < ls[u].size(); j++)
        {
            int v = ls[u][j].second;
            int c = ls[u][j].first;
            if(color[v]!=BLACK && d[u]+c<d[v])
            {
                d[v]=d[u]+c;
                color[v]=GRAY;
                pq.push(make_pair(d[v],v));
            }
        }
        
    }
    for(int i = 0; i < n; i++)
    {
        cout<<i<<" "<<d[i]<<endl;
    }
}

int main(){
    m0(ls);
    m0(color);
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        int id, k;
        cin>>id>>k;
        for(int j = 0; j < k; j++)
        {
            int v,c;
            cin>>v>>c;
            ls[id].push_back(make_pair(c,v));
        }
        
    }
    
    dijkstra(0);
    
    return 0;
}