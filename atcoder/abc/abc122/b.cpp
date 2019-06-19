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
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int bg = 0; bg < n; bg++)
    {
        for(int en = bg; en < n; en++)
        {
            bool ok=true;
            for(int i = bg; i <= en; i++)
            {
                if(s[i]!='A' && s[i]!='T' && s[i]!='G' && s[i]!='C')
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                ans=max(ans,(en-bg+1));
            }
        }
        
    }
    cout<<ans<<endl;
    return 0;
}