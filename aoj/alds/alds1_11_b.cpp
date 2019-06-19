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
int color[110],detect[110],finish[110];
int tim;
int n;

void dfs(int u)
{
    color[u]=1;
    detect[u]=tim;
    tim++;
    for(int v = 0; v < n; v++)
    {
        if(ls[u][v]==1 && color[v]==0)
        {
            dfs(v);
        }
    }
    color[u]=2;
    finish[u]=tim;
    tim++;
}

int main(){
    m0(ls);
    m0(color);
    m0(detect);
    m0(finish);
    tim=1;

    cin>>n;

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
    for(int i = 0; i < n; i++)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout<<i+1<<" "<<detect[i]<<" "<<finish[i]<<endl;
    }
    
    return 0;
}