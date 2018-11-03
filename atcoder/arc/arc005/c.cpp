#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int h,w;

bool inside(int y, int x)
{
    return (0<=y && y<h && 0<=x && x<w);
}

int main()
{
    cin >> h>>w;
    vector<string> c(h);
    bool checked[500][500];
    m0(checked);

    for(int i = 0; i < h; i++)
    {
        cin >> c.at(i);
    }
    int gx, gy;
    queue<pii> q[4];    

    for(int y = 0; y < h; y++)
    {        
        for(int x = 0; x < w; x++)
        {
            if(c.at(y).at(x) == 's')
            {
                q[0].push(pii(x,y));
                checked[y][x] = true;
            }
            else if(c.at(y).at(x) == 'g')
            {
                gx=x;
                gy=y;
            }
        }        
    }
    
    
    for(int qi = 0; qi < 3; qi++)
    {        
        while(q[qi].size()>0){
            pii now = q[qi].front();
            q[qi].pop();
                    
            for(int i = 0; i < 4; i++)
            {
                int nextx = now.first + dx[i];
                int nexty = now.second + dy[i];
                if(inside(nexty, nextx) 
                    && checked[nexty][nextx] == false)
                {
                    if(c[nexty][nextx]!='#') //not kabe
                    {
                        q[qi].push(pii(nextx,nexty));
                        checked[nexty][nextx] = true;
                    }
                    else if(qi < 2)
                    {
                        q[qi+1].push(pii(nextx,nexty));
                        checked[nexty][nextx] = true;
                    }                    
                }
            }
        }        
    }
    
    if(checked[gy][gx])
    {
        cout << "YES"<<endl;
    }
    
    else
    {
        cout <<"NO"<<endl;
    }
    
 
    return 0;
}