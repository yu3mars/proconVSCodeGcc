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
    string s,t;
    cin>>t;
    int n=t.size();
    for (int i = 0; i < n; i++)
    {
        if(t[i]=='?')
        {
            s+='D';
        }
        else
        {
            s+=t[i];
        }
    }
    cout<<s<<endl;
    /*
    int ans=0;
    int tmp=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='D')
        {
            tmp++;
        }
        else    //s[i]=='P'
        {
            if(i<n-1 && s[i+1]=='D')
            {
                tmp++;
            }
            else
            {
                ans=max(ans,tmp);
                tmp=0;
            }
        }
    }
    ans=max(ans,tmp);
    
    cout<<ans<<endl;
    */
    return 0;
}