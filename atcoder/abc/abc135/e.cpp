#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    ll k,x,y;
    cin>>k>>x>>y;
    if(k%2==0 &&(abs(x)+abs(y))%2==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        ll fugoux=1,fugouy=1;
        bool swapflag = false;
        if(x<0)
        {
            fugoux=-1;
            x=-x;
        }
        if(y<0)
        {
            fugouy=-1;
            y=-y;
        }
        if(x<y)
        {
            swapflag=true;
            swap(x,y);
        }
        ll c = (k-(x+y)%k)%k;
        vector<pll> v;
        if(x+y<k && (x+y) % 2 ==1)
        {
            v.push_back(make_pair(x, -k+x));
            v.push_back(make_pair(x+(k+x-y)/2, (-k+x+y)/2));
            v.push_back(make_pair(x,y));
        }
        else
        {
            ll n;
            if(x+y<k && (x+y)%2==0)
            {
                n=2;
            }
            else
            {
                n = (x+y+k-1)/k;
                if(c%2==1) n++;                
            }
            
            ll p1 = -(n*k-x-y)/2;
            ll stage = 0;
            ll nowx=0, nowy=0;
            for (int i = 0; i < n; i++)
            {
                ll nextx=nowx, nexty=nowy;
                if(stage==0)
                {
                    if(x+y==k)
                    {
                        nextx=x;
                        nexty=y;
                    }
                    else if(nowy-k > p1)
                    {
                        nexty-=k;
                    }
                    else
                    {
                        nextx+=k-(nowy-p1);
                        nexty=p1;
                        stage++;
                    }
                }
                else if (stage==1)
                {
                    if(nowx+k<x)
                    {
                        nextx+=k;
                    }
                    else
                    {
                        nexty+=k-(x-nowx);
                        nextx=x;
                        stage++;
                    }
                    
                }
                else
                {
                    nexty+=k;
                }
                v.push_back(make_pair(nextx, nexty));
                nowx=nextx;
                nowy=nexty;
            }
            
        }

        cout<<v.size()<<endl;
        for (int i = 0; i < v.size(); i++)
        {
            ll xx = v[i].first;
            ll yy = v[i].second;
            if(swapflag) swap(xx,yy);
            xx*=fugoux;
            yy*=fugouy;
            cout<<xx<<" "<<yy<<endl;
        }
        
    }
    
    return 0;
}