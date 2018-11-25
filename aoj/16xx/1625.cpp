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
    for(;;)
    {
        int n,m,t,p;
        cin>>n>>m>>t>>p;
        if(n==0) break;
        int cnt[70][70];
        m0(cnt);
        
        for(int y = 0; y < m; y++)
        {
            for(int x = 0; x < n; x++)
            {
                cnt[y][x]=1;
            }
        }
        
        for(int iii = 0; iii < t; iii++)
        {
            int d,c;
            cin>>d>>c;
            if(d==1)//yoko ori
            {
                for(int x = c - 1; x >= 0; x--)
                {
                    for(int y = 0; y < m; y++)
                    {
                        cnt[y][c+(c-1-x)]+=cnt[y][x];
                        cnt[y][x]=0;
                    }
                }
                
                for(int y = 0; y < m; y++)
                {
                    for(int x = 0; x < max(n-c+2,c*2); x++)
                    {
                        cnt[y][x]=cnt[y][x+c];
                        cnt[y][x+c]=0;
                    }                    
                }
                n=max(n-c,c);
            }
            else//tate ori
            {
                if(m-c<c)
                {
                    
                    for(int x = 0; x < n; x++)
                    {
                        for(int y = m - 1; y >= 0; y--)
                        {
                            cnt[y+(c*2-m)][x]=cnt[y][x];
                            cnt[y][x]=0;
                        }
                    }
                    m=c*2;
                }
                for(int y = c - 1; y >= 0; y--)
                {
                    for(int x = 0; x < n; x++)
                    {
                        cnt[(m-c)-(c-y)][x]+=cnt[m-1-y][x];
                        cnt[m-1-y][x]=0;
                    }
                }
                m=max(m-c,c);
            }
            /*
            cout<<endl;
            for(int y = 0; y < 10; y++)
            {
                
                for(int x = 0; x < 10; x++)
                {
                    cout<<cnt[y][x]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            */
        }
        
        for(int iii = 0; iii < p; iii++)
        {
            int xx,yy;
            cin>>xx>>yy;
            cout<<cnt[m-1-yy][xx]<<endl;
        }

    }
    return 0;
}