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
    int h,w,k;
    cin>>h>>w>>k;
    vector<string> c(h);
    for (int i = 0; i < h; i++)
    {
        cin>>c[i];
    }
    int ans=0;
    for (int hbit = 0; hbit < (1<<h); hbit++)
    {
        for (int wbit = 0; wbit < (1<<w); wbit++)
        {
            int cnt=0;
            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    if(((hbit & (1<<y))!=0) && ((wbit & (1<<x))!=0) && c[y][x]=='#')
                    {
                        cnt++;
                    }
                }
                
            }
            
            if(cnt==k) ans++;
            //cout<<hbit<<" "<<wbit<<" "<<cnt<<endl;
        }
        
    }
    
    
    cout<<ans<<endl;
    return 0;
}