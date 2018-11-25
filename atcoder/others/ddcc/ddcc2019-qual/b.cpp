#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {0,0,1,1}, dy4[4] = {0,1,0,1};

double mid;
double dist(int y,int x)
{
    return abs(mid-y)+abs(mid-x);
}

int main()
{
    int n, ans=0;
    cin>>n;
    mid=n/2.0;
    
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            bool ok = true;
            
            for(int i = 0; i < 4; i++)
            {
                int nowy = y+dy4[i];
                int nowx = x+dx4[i];
                if(mid - dist(nowy,nowx)< -1e-6)
                {
                    ok=false;
                    break;
                }
            }
            if(ok) ans++;
        }    
    }
    


    cout<<ans<<endl;
    return 0;
}