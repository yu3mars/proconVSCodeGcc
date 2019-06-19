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

int main(){
    int n,q;
    cin>>n>>q;
    DisjointSet ds = DisjointSet(n);
    for(int qq = 0; qq < q; qq++)
    {
        int com,x,y;
        cin>>com>>x>>y;
        if(com==0)
        {
            ds.unite(x,y);
        }
        else
        {
            if(ds.same(x,y))
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
            
        }
        
    }
    
    return 0;
}