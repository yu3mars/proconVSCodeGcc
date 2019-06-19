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

int ls[110][110];
int color[110];
int d[110],p[110];
int n;

int prim()
{
    for(int i = 0; i < n; i++)
    {
        color[i]=WHITE;
        p[i]=-1;
        d[i]=INF;
    }
    d[0]=0;
    while(true){
        int mincost=INF;
        int u=-1;
        for(int i = 0; i < n; i++)
        {
            if(color[i]!=BLACK && d[i]<mincost)
            {
                mincost=d[i];
                u=i;
            }
        }

        if(mincost==INF)
        {
            break;
        }
        color[u]=BLACK;
        for(int v = 0; v < n; v++)
        {
            if(color[v]!=BLACK && ls[u][v]!=INF)
            {
                if(ls[u][v]<d[v])
                {
                    d[v]=ls[u][v];
                    p[v]=u;
                    color[v]=GRAY;
                }
            }
        }
    }
    int ret=0;
    for(int i = 0; i < n; i++)
    {
        if(p[i]!=-1)
        {
            ret+=ls[i][p[i]];
        }
    }
    return ret;
}

int main(){
    m0(ls);
    m0(color);
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int aa;
            cin>>aa;
            if(aa==-1) aa=INF;
            ls[i][j]=aa;
        }
    }
    
    cout<<prim()<<endl;
    
    return 0;
}