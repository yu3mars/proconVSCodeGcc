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
    int n,ansx,ansy,ansh=-1;
    cin>>n;
    vector<int> x(n),y(n),h(n);
    int xx,yy,hh;
    
    for(int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i]>>h[i];
        if(h[i]>0)
        {
            xx=x[i];
            yy=y[i];
            hh=h[i];
        }
    }
    
    
    for(int tmpx = 0; tmpx < 101; tmpx++)
    {
        for(int tmpy = 0; tmpy < 101; tmpy++)
        {
            bool ok=true;
            bool kakutei =false;
            int tmph = hh + abs(tmpx-xx)+abs(tmpy-yy);
            
            for(int info = 0; info < n; info++)
            {
                int diff= abs(tmpx-x[info])+abs(tmpy-y[info]);
                if(tmph!=diff+h[info])
                {
                    if(h[info]==0 && diff>tmph)
                    {
                        continue;
                    }
                    else
                    {
                        ok=false;
                        break;
                    }
                }
            }
            if(ok)
            {
                ansx=tmpx;
                ansy=tmpy;
                ansh=tmph;
                break;
            }
        }
        if(ansh>0)break;
    }

    cout<<ansx<<" "<<ansy<<" "<<ansh<<endl;
    return 0;
}