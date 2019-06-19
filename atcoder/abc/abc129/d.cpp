#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int h,w;//y,x
bool inside(int y, int x)
{
    return (0<=y && y<h && 0<=x && x<w);
}
int cx[2010][2010];
int cy[2010][2010];

int main(){
    ll ans=0;
    cin>>h>>w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin>>s[i];
    }
    m0(cx);
    m0(cy);
    //x houkou
    for (int y = 0; y < h; y++)
    {
        int cnt=0,bgn=0;
        for (int x = 0; x < w; x++)
        {
            if(s[y][x]=='.')
            {
                cnt++;
                if(x==w-1)
                {
                    for (int xi = bgn; xi <= x; xi++)
                    {
                        cx[y][xi]=cnt;
                    }
                }
            }
            else //#
            {
                for (int xi = bgn; xi < x; xi++)
                {
                    cx[y][xi]=cnt;
                }
                cnt=0;
                bgn=x+1;
            }
        }
    }

    //y houkou
    for (int x = 0; x < w; x++)
    {
        int cnt=0,bgn=0;
        for (int y = 0; y < h; y++)
        {
            if(s[y][x]=='.')
            {
                cnt++;
                if(y==h-1)
                {
                    for (int yi = bgn; yi <= y; yi++)
                    {
                        cy[yi][x]=cnt;
                    }
                }
            }
            else //#
            {
                for (int yi = bgn; yi <= y; yi++)
                {
                    cy[yi][x]=cnt;
                }
                cnt=0;
                bgn=y+1;
            }
        }
    }
    
    //calc ans
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            ll tmp = cx[y][x]+cy[y][x]-1;
            ans=max(ans,tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
}