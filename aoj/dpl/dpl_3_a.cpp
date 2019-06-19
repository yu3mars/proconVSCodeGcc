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

int mp[1410][1410];
int ans[1410][1410];

int main(){
    int h,w;
    cin>>h>>w;
    m0(mp);
    m0(ans);
    for(int hh = 0; hh < h; hh++)
    {
        for(int ww = 0; ww < w; ww++)
        {
            cin>>mp[hh][ww];
        }
    }
    for(int hh = 0; hh < h; hh++)
    {
        if(mp[hh][0]==0) ans[hh][0]=1;
    }
    for(int ww = 0; ww < w; ww++)
    {
        if(mp[0][ww]==0) ans[0][ww]=1;
    }

    for(int hh = 1; hh < h; hh++)
    {
        for(int ww = 1; ww < w; ww++)
        {
            if(mp[hh][ww]==0)
            {
                ans[hh][ww]=min(min(ans[hh-1][ww],ans[hh-1][ww-1]),ans[hh][ww-1])+1;
            }
        }
    }
    int mx=0;
    for(int hh = 0; hh < h; hh++)
    {
        for(int ww = 0; ww < w; ww++)
        {
            mx=max(mx,ans[hh][ww]);
        }
    }
    cout<<mx*mx<<endl;
    return 0;
}