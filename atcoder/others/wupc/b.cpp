#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int calcSub(int mx)
{
    int ans;
    if(mx<=5) ans=0;
    else if(mx==6||mx==7) ans=1;
    else if(mx==8) ans=2;
    else if(mx==9) ans=3;
    return ans;
}

int main()
{
    int h,w,mx=0,ans=0;
    int a[100][100];
    cin>>h>>w;
    bool exist5 = false;
    bool all0=true;
    for(int yy = 0; yy < h; yy++)
    {
        for(int xx = 0; xx < w; xx++)
        {
            cin>>a[yy][xx];
            if(a[yy][xx]==5)
            {
                exist5=true;
            }
            if(a[yy][xx]!=0)
            {
                all0=false;
            }
            mx=max(mx,a[yy][xx]);
        }
    }
    if(all0) cout<<"Yes 0"<< endl;
    else if(exist5==false) cout<<"No"<<endl;
    else
    {
        if(mx==5) ans=1;
        else if(h>1||w>1)
        {
            ans=calcSub(mx)+1;
        }
        else 
        {
            int b[100];
            int n= max(h,w);
            if(h==1)
            {
                for(int i = 0; i < w; i++)
                {
                    b[i]=a[0][i];
                }
            }
            else
            {
                for(int i = 0; i < h; i++)
                {
                    b[i]=a[h][0];
                }
            }
            for(int mid = 0; mid < n; mid++)
            {
                if(b[mid]!=5) continue;
                int lmax=0,rmax=0;
                for(int i = 0; i < mid; i++)
                {
                    lmax=max(lmax,b[i]);
                }
                for(int i = mid+1; i < n; i++)
                {
                    rmax=max(lmax,b[i]);
                }
                ans=min(ans,calcSub(lmax)+calcSub(rmax)+1);
            }
            
        }

        cout<<"Yes "<<ans<<endl;
    }
 
    return 0;
}