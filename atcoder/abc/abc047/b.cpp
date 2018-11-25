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
    int w,h,n;
    cin >>w>>h>>n;
    int xl = 0, xr = w, yu = h, yd=0;
    
    for(int i = 0; i < n; i++)
    {
        int x,y,a;
        cin >> x>>y>>a;
        if(a==1)
        {
            xl =max(xl,x);
        }
        if(a==2)
        {
            xr=min(xr,x);
        }
        if(a==3)
        {
            yd=max(yd,y);
        }
        if(a==4)
        {
            yu=min(yu,y);
        }
    }
    
    cout<<(max(0,xr-xl) * max(0,yu-yd))<<endl;
 
    return 0;
}