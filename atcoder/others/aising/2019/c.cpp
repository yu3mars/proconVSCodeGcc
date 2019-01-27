#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int h,w;
ll cnt[161000][2];

bool inside(int y, int x)
{
    return (0<=y && y<h && 0<=x && x<w);
}

int category(char c)
{
    if(c=='#') return 0;
    else return 1;
}

int main(){
    cin>>h>>w;
    ll ans =0;
    vector<string> stage(h);
    int groups[410][410];
    ll cnt[161000][2];
    int nowgroup = 0;
    
    for(int i = 0; i < 161000; i++)
    {
        
        for(int j = 0; j < 2; j++)
        {
            cnt[i][j]=0;
        }
        
    }
    
    
    for(int i = 0; i < h; i++)
    {
        cin>>stage[i];
    }
    
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(groups[y][x]!=0) continue;
            nowgroup++;
            groups[y][x]=nowgroup;
            cnt[nowgroup][category(stage[y][x])]++;
            queue<int> qy,qx;
            qy.push(y);
            qx.push(x);
            while(qy.size()>0)
            {
                int nowy=qy.front();
                int nowx=qx.front();
                qy.pop();
                qx.pop();
                
                for(int i = 0; i < 4; i++)
                {
                    int nexty=nowy+dy4[i];
                    int nextx=nowx+dx4[i];
                    if(inside(nexty,nextx) && groups[nexty][nextx]==0
                        && stage[nowy][nowx]!=stage[nexty][nextx])
                    {
                        groups[nexty][nextx]=nowgroup;
                        cnt[nowgroup][category(stage[nexty][nextx])]++;
                        qy.push(nexty);
                        qx.push(nextx);
                    }
                }
                
            }
        }
    }
    
    
    for(int i = 1; i <= nowgroup; i++)
    {
        ans += cnt[i][0]*cnt[i][1];
    }
    

    cout<<ans<<endl;
    return 0;
}