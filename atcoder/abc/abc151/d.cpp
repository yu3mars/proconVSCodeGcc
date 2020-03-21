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

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
void warshall_floyd(Matrix< T > &g, T INF) {
  for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
      for(int j = 0; j < g.size(); j++) {
        if(g[i][k] == INF || g[k][j] == INF) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
};

int h,w;

bool inside(int y,int x)
{
    return 0<=y && y<h && 0<=x && x<w;
}

int calcV(int y,int x)
{
    return y*w+x;
}

int main()
{
    int doty,dotx;
    cin>>h>>w;
    int V=h*w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin>>s[i];
    }
    Matrix< int > mat(h*w, vector< int >(h*w, INT_MAX));
    for(int i = 0; i < h*w; i++) mat[i][i] = 0;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if(s[y][x]=='#') continue;
            for (int i = 0; i < 4; i++)
            {
                int nexty= y+dy4[i];
                int nextx= x+dx4[i];
                if(inside(nexty,nextx)==true && s[nexty][nextx]=='.')
                {
                    mat[calcV(y,x)][calcV(nexty,nextx)]=1;
                }
            }
            doty=y;
            dotx=x;
        }
    }

    warshall_floyd(mat, INT_MAX);

    int ans=0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(mat[i][j]!=INT_MAX)
            {
                ans=max(ans,mat[i][j]);
            }
        }
    }
    cout<<ans<<endl;
    

    /*
    int v1=calcV(doty,dotx);
    int v2=calcV(doty,dotx);
    int dmax=0;
    for (int i = 0; i < h*w; i++)
    {
        if(mat[calcV(doty,dotx)][i]==INT_MAX) continue;
        if(mat[calcV(doty,dotx)][i]>dmax)
        {
            v1=i;
            dmax=mat[calcV(doty,dotx)][i];
        }
    }
    for (int i = 0; i < h*w; i++)
    {
        if(mat[v1][i]==INT_MAX) continue;
        if(mat[v1][i]>dmax)
        {
            v2=i;
            dmax=mat[v1][i];
        }
    }
    cout<<dmax<<endl;


    for(int i = 0; i < h*w; i++) {
        for(int j = 0; j < h*w; j++) {
            if(j > 0) putchar('\t');
            if(mat[i][j] == INT_MAX) printf("INF");
            else printf("%d", mat[i][j]);
        }
        putchar('\n');
    }
    cout<<endl;
    cout<<v1<<"\t"<<v2<<endl;
    */

    return 0;
}