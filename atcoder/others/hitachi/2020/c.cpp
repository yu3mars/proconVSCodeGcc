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
    int n,m;
    cin>>n>>m;
    vector<int> s(m),c(m),ans(n);
    bool ok=true;
    for (int i = 0; i < n; i++)
    {
        ans[i]=-1;
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>s[i]>>c[i];
        s[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        if(ans[s[i]]==-1 || ans[s[i]]==c[i])
        {
            ans[s[i]]=c[i];
        }
        else
        {
            ok=false;
            break;
        }
    }
    if(ans[0]==0 && n>1) ok=false;
    if(ok)
    {
        if(n==1) cout<<max(0,ans[0])<<endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if(ans[i]==-1)
                {
                    if(i==0) cout<<1;
                    else cout<<0;
                }
                else
                {
                    cout<<ans[i];
                }
                
            }
            cout<<endl;
        }
        
    }
    else
    {
        cout<<-1<<endl;
    }
    
    
    return 0;
}