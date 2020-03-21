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
    string s;
    cin>>n>>m>>s;
    vector<int> ans;
    int now=n;
    while (now>0)
    {
        bool ok=false;
        for (int deme = min(now,m); deme > 0; deme--)
        {
            if(s[now-deme]=='0')
            {
                now-=deme;
                ans.push_back(deme);
                ok=true;
                break;
            }
        }
        if(ok==false)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout<<ans[i];
        if(i==0) cout<<endl;
        else cout<<" ";
    }
    
    
    return 0;
}