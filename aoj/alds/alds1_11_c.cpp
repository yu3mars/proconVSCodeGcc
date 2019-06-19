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

int ls[110][110];
int color[110],dest[110];
int n;

void bfs(int s)
{
    color[s]=1;
    dest[s]=0;
    queue<int> q;
    q.push(s);
    while(q.empty()==false){
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++)
        {
            if(ls[u][v]==1 && color[v]==0)
            {
                color[v]=1;
                dest[v]=dest[u]+1;
                q.push(v);
            }
        }
        color[u]=2;
    }
    
}

int main(){
    m0(ls);
    m0(color);
    m0(dest);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        dest[i]=-1;
    }
    

    for(int i = 0; i < n; i++)
    {
        int from,cnt;
        cin>>from>>cnt;
        from--;
        for(int j = 0; j < cnt; j++)
        {
            int to;
            cin>>to;
            to--;
            ls[from][to]=1;
        }
    }
    bfs(0);

    for(int i = 0; i < n; i++)
    {
        cout<<i+1<<" "<<dest[i]<<endl;
    }
    
    
    return 0;
}