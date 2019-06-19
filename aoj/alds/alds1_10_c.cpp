#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int dp[1010][1010];

int main(){
    int q;
    cin>>q;
    for(int qq = 0; qq < q; qq++)
    {
        m0(dp);
        string x,y;
        cin>>x>>y;
        for(int i = 0; i < x.size(); i++)
        {
            for(int j = 0; j < y.size(); j++)
            {
                if(x[i]==y[j])
                {
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
                }
                else
                {
                    dp[i+1][j+1]=max(dp[i+1][j+1],
                        max(dp[i+1][j],dp[i][j+1]));
                }
            }
            
        }
        cout<<dp[x.size()][y.size()]<<endl;
        
    }
    
    
    return 0;
}