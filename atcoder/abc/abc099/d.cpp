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
    int n,col,ans=1e9;
    cin>>n>>col;
    int d[30][30], c[500][500];
    int ls[3][30];// n%3, col
    
    for(int y = 0; y < col; y++)
    {
        for(int x = 0; x < col; x++)
        {
            cin >> d[y][x];
        }    
    }
    
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            cin >> c[y][x];
            c[y][x]--;
            ls[(y+x)%3][c[y][x]]++;
        }        
    }
    
    for(int i = 0; i < col; i++)
    {
        
        for(int j = 0; j < col; j++)
        {
            
            for(int k = 0; k < col; k++)
            {
                if(i==j||j==k||k==i) continue;

                int tmp=0;
                
                for(int ci = 0; ci < col; ci++)
                {
                    tmp+=ls[0][ci] * d[ci][i];
                    tmp+=ls[1][ci] * d[ci][j];
                    tmp+=ls[2][ci] * d[ci][k];
                }
                
                ans=min(ans,tmp);
            }
            
        }
        
    }
    
    cout<<ans<<endl;

    return 0;
}