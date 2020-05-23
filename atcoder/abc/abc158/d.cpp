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
    string s,mae,ato;
    int q;
    cin>>s>>q;
    bool normal=true;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            normal=!normal;
        }
        else
        {
            int f;
            char c;
            cin>>f>>c;
            if((normal && f==1) || (!normal && f==2))
            {
                mae+=c;
            }
            else
            {
                ato+=c;
            }
        }
    }
    string ans;
    reverse(all(mae));
    ans=mae+s+ato;

    if(!normal)
    {
        reverse(all(ans));
    }
    
    
    cout<<ans<<endl;
    
    return 0;
}