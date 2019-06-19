#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int,int,int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int h,w;//y,x
int d[1000][1000];

bool inside(int y,int x)
{
    return (0<=y && y<h && 0<=x && x<w);
}

int main(){
    int ans=0;
    cin>>h>>w;
    vector<string> a(h);
    for (int i = 0; i < h; i++)
    {
        cin>>a[i];
    }
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if(a[y][x]=='.') d[y][x]=1e9+7;
            else
            {
                d[y][x]=0;
            }
        }
    }
    queue<tiii> q;//y,x,d
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if(a[y][x]=='#')
            {
                for (int i = 0; i < 4; i++)
                {
                    int nexty=y+dy4[i];
                    int nextx=x+dx4[i];
                    if(inside(nexty,nextx)==true && d[nexty][nextx]==1e9+7)
                    {
                        q.push(make_tuple(nexty,nextx,1));
                        d[nexty][nextx]=1;
                    }
                }   
            }
        }
    }
    while(q.size()>0)
    {
        tiii nowt = q.front();
        q.pop();
        int y = get<0>(nowt);
        int x = get<1>(nowt);
        int dd = get<2>(nowt);
        ans=max(ans,dd);
        for (int i = 0; i < 4; i++)
        {
            int nexty=y+dy4[i];
            int nextx=x+dx4[i];
            if(inside(nexty,nextx)==true && d[nexty][nextx]>dd+1)
            {
                q.push(make_tuple(nexty,nextx,dd+1));
                d[nexty][nextx]=dd+1;
            }
        }
    }


    cout<<ans<<endl;

    return 0;
}