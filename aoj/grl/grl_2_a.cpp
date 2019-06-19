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

const int MAX = 100010;
const ll INF = __INT_MAX__/3;


class DisjointSet
{
    public:
        vector<int> rank,p;

    DisjointSet(){};
    DisjointSet(int size)
    {
        rank.resize(size,0);
        p.resize(size,0);
        for(int i = 0; i < size; i++)
        {
            makeSet(i);
        }
    }
    void makeSet(int x)
    {
        p[x]=x;
        rank[x]=0;
    }

    bool same(int x, int y)
    {
        return findSet(x)==findSet(y);
    }

    void unite(int x,int y)
    {
        link(findSet(x),findSet(y));
    }

    void link(int x, int y)
    {
        if(rank[x] > rank[y])
        {
            p[y]=x;
        }
        else
        {
            p[x]=y;
            if(rank[x]==rank[y])
            {
                rank[y]++;
            }
        }
        
    }

    int findSet(int x)
    {
        if(p[x]!=x)
        {
            p[x]=findSet(p[x]);
        }
        return p[x];
    }
};


class Edge{
    public:
        int source, target, cost;
        Edge(){}
        Edge(int source, int target, int cost):
        source(source),target(target),cost(cost){}
        bool operator < (const Edge &e) const {
            return cost < e.cost;
        }
};

int kruscal(int n, vector<Edge> edges)
{
    sort(all(edges));
    int totalCost=0;
    DisjointSet dset = DisjointSet(n);
    for(int i = 0; i < n; i++)
    {
        dset.makeSet(i);
    }
    for(int i = 0; i < edges.size(); i++)
    {
        Edge e = edges[i];
        if(!dset.same(e.source, e.target))
        {
            totalCost+=e.cost;
            dset.unite(e.source,e.target);
        }
    }
    
    return totalCost;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++)
    {
        int source, target, cost;
        cin>>source>>target>>cost;
        edges.push_back(Edge(source,target,cost));
    }
    cout<<kruscal(n,edges)<<endl;

    return 0;
}