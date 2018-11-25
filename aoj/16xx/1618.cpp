#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int Cnt(int e[10][10], int yu,int yd,int xl,int xr)
{
    int sotomin=10;
    int nakamax=0;
    
    for(int y = yu; y <= yd; y++)
    {
        for(int x = xl; x <= xr; x++)
        {
            if(y==yu||y==yd||x==xl||x==xr)
            {
                sotomin = min(sotomin,e[y][x]);
            }            
            else
            {
                nakamax=max(nakamax,e[y][x]);
            }            
        }        
    }
    if(sotomin<=nakamax) return 0;
    int ans =0;
    for(int y = yu+1; y < yd; y++)
    {
        for(int x = xl+1; x < xr; x++)
        {
            ans+=sotomin-e[y][x];          
        }        
    }

    return ans;
}

int main()
{
    for(;;)
    {
        int d,w,ans =0;;
        cin >>d>>w;
        if(d==0) break;
        int e[10][10];
        m0(e);
        
        for(int dd = 0; dd < d; dd++)
        {
            for(int ww = 0; ww < w; ww++)
            {
                cin>>e[dd][ww];
            }
        }
        
        for(int yu = 0; yu < d-2; yu++)
        {
            
            for(int yd = yu+2; yd < d; yd++)
            {
                
                for(int xl = 0; xl < w-2; xl++)
                {
                    
                    for(int xr = xl+2; xr < w; xr++)
                    {
                        ans=max(ans,Cnt(e,yu,yd,xl,xr));
                    }
                }
            }
        }
        cout << ans<<endl;
    }
    return 0;
}