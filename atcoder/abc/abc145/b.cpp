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
    int n;
    string s;
    cin>>n>>s;
    bool ok=true;
    if(n%2!=0) ok=false;
    if(ok)
    {
        for (int i = 0; i < n/2; i++)
        {
            if(s[i]!=s[i+n/2])
            {
                ok=false;
                break;
            }
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}