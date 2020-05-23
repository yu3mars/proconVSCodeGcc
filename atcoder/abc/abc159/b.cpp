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
    string s;
    cin>>s;
    int n=s.length();
    bool ok=true;
    for (int i = 0; i < n/2; i++)
    {
        if(s[i]!=s[n-1-i]) 
        {
            ok=false;
            break;
        }
    }
    for (int i = 0; i < (n-1)/2; i++)
    {
        if(s[i]!=s[(n-1)/2-1-i])
        {
            ok=false;
            break;
        }
    }
    for (int i = (n+3)/2; i < n; i++)
    {
        if(s[i]!=s[n-1-i])
        {
            ok=false;
            break;
        }
    }
    if(ok)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    
    return 0;
}