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

int n,m;
vector<int> edge[610];
double dp[610];
const double INF=1e9;
double ans=INF;
void init()
{
    for (int i = 0; i < 610; i++)
    {
        dp[i]=INF;
    }
    dp[n]=0;
}

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    cin>>n>>m;
    init();
    for (int i = 0; i < m; i++)
    {
        int s,t;
        cin>>s>>t;
        edge[s].push_back(t);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        int cnt=edge[i].size();
        double tmp=0;
        for (int j = 0; j < cnt; j++)
        {
            tmp+=dp[edge[i][j]]+1;
        }
        tmp/=cnt;
        dp[i]=tmp;
    }
    ans=min(ans,dp[1]);
    for (int del = n - 1; del >= 1; del--)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            if(i!=del || edge[i].size()==1)
            {
                int cnt=edge[i].size();
                double tmp=0;
                for (int j = 0; j < cnt; j++)
                {
                    tmp+=dp[edge[i][j]]+1;
                }
                tmp/=cnt;
                dp[i]=tmp;
            }
            else
            {
                int cnt=edge[i].size();
                double tmp=0,mx=0;
                for (int j = 0; j < cnt; j++)
                {
                    tmp+=dp[edge[i][j]]+1;
                    mx=max(mx,dp[edge[i][j]]+1);
                }
                tmp-=mx;
                tmp/=(cnt-1);
                dp[i]=tmp;
            }
            
        }
        ans=min(ans,dp[1]);
    }
    
    
    
    
    cout<<ans<<endl;
    return 0;
}