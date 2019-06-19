#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    ll n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d>>s;
    a--;
    b--;
    c--;
    d--;
    bool ok=true;
    for (ll i = a; i < c; i++)
    {
        if(s[i]=='#' && s[i+1]=='#')
        {
            ok=false;
            break;
        }
    }
    for (ll i = b; i < d; i++)
    {
        if(s[i]=='#' && s[i+1]=='#')
        {
            ok=false;
            break;
        }
    }
    if(ok && d<c)
    {
        bool nukaseru = false;
        for (int i = b; i <= d; i++)
        {
            if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.')
            {
                nukaseru = true;
                break;
            }
        }
        if(nukaseru==false)
        {
            ok=false;
        }
    }

    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}