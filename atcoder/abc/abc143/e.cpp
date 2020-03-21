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

const int MAX = 305;
const ll INF = __LONG_LONG_MAX__/3;

ll dist[MAX][MAX];
ll fuel[MAX][MAX];

int main(){
    ll n,m,l;
    cin>>n>>m>>l;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
                fuel[i][j]=0;
            }
            else
            {
                dist[i][j]=INF;
                fuel[i][j]=INF;
            }
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        dist[a][b]=c;
        dist[b][a]=c;
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(dist[i][k]==INF) continue;
            for(int j = 0; j < n; j++)
            {
                if(dist[k][j]==INF) continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j]<=l)
            {
                fuel[i][j]=1;
            }
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(fuel[i][k]==INF) continue;
            for(int j = 0; j < n; j++)
            {
                if(fuel[k][j]==INF) continue;
                fuel[i][j]=min(fuel[i][j],fuel[i][k]+fuel[k][j]);
            }
        }
    }

    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int s,t;
        cin>>s>>t;
        s--;t--;
        if(fuel[s][t]==INF) cout<<-1<<endl;
        else cout<<fuel[s][t]-1<<endl;;
    }
    
    return 0;
}