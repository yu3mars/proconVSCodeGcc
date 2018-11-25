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
    int t;
    cin>>t;
    
    for(int tt = 0; tt < t; tt++)
    {
        ll xx,yy,x[4],y[4];
        cin>>yy>>xx;
        ll b=yy*xx/2;
        ll w=yy*xx-b;
        
        for(int i = 0; i < 4; i++)
        {
            cin>>x[i]>>y[i];
        }

        //white penki
        ll f = (x[1]-x[0]+1)*(y[1]-y[0]+1);
        if(f%2==0||(x[0]+y[0])%2==0)
        {
            b-=f/2;
            w+=f/2;
        }
        else
        {
            b-=f/2+1;
            w+=f/2+1;
        }

        //both penki moto ni modosu
        ll mx[2],my[2];
        mx[0]=max(x[0],x[2]);
        my[0]=max(y[0],y[2]);
        mx[1]=min(x[1],x[3]);
        my[1]=min(y[1],y[3]);
        if(mx[0]<=mx[1]&&my[0]<=my[1])
        {
            f=(mx[1]-mx[0]+1)*(my[1]-my[0]+1);
            if(f%2==0||(mx[0]+my[0])%2==0)
            {
                b+=f/2;
                w-=f/2;
            }
            else
            {
                b+=f/2+1;
                w-=f/2+1;
            }
        }

        //black penki
        f = (x[3]-x[2]+1)*(y[3]-y[2]+1);
        if(f%2==0||(x[2]+y[2])%2==1)
        {
            b+=f/2;
            w-=f/2;
        }
        else
        {
            b+=f/2+1;
            w-=f/2+1;
        }

        cout<<w<<" "<<b<<endl;
    }

    return 0;
}