#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    int n,ans=0;
    cin>>n;
    vector<tuple<int,int,int>> red(n),blue(n);
    
    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        red[i]=make_tuple(x,y,-1);
    }
    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        blue[i]=make_tuple(x,y,-1);
    }
    sort(all(red));
    sort(all(blue));
    
    for(int bcnt = 0; bcnt < n; bcnt++)
    {
        int p =-1;
        for(int rcnt = 0; rcnt < n; rcnt++)
        {
            if(get<2>(red[rcnt])!=-1) continue;
            if(get<0>(red[rcnt]) < get<0>(blue[bcnt]))
            {
                if(get<1>(red[rcnt]) < get<1>(blue[bcnt]))
                {
                    if(p==-1)
                    {
                        p=rcnt;
                    }
                    else if(get<1>(red[p]) < get<1>(red[rcnt]))
                    {
                        p=rcnt;
                    }
                }    
            }
            else break;
        }
        if(p!=-1)
        {
            ans++;
            get<2>(red[p])=p;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}