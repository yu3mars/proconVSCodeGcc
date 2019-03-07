#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int n,a,b,c,ans;
vector<int> l;
int dfs(int cnt, int x, int y, int z)
{
    if(cnt==n)
    {
        if(x==0||y==0||z==0) return 1e9+7;
        else
        {
            int ret = abs(a-x)+abs(b-y)+abs(c-z);
            return ret;
        }        
    }
    else
    {
        int ret0 = dfs(cnt+1,x,y,z);
        int ret1 = dfs(cnt+1,x+l[cnt],y,z)+10;
        int ret2 = dfs(cnt+1,x,y+l[cnt],z)+10;
        int ret3 = dfs(cnt+1,x,y,z+l[cnt])+10;
        int ret = min(min(ret0,ret1),min(ret2,ret3));
        return ret;
    }
    
}

int main(){
    ans=1e9+7;
    cin>>n>>a>>b>>c;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        l.push_back(tmp);
    }
    ans = dfs(0,0,0,0);
    
    cout<<ans-30<<endl;
    return 0;
}