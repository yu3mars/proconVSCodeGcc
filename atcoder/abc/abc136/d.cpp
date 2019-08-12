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
    ll n = s.size();
    vector<ll> ans(n);
    ll odd=0, even=0;
    ll lastr = 0;
    for (ll i = 0; i < n; i++)
    {
        swap(odd,even);
        even++;
        if(s[i]=='R')
        {
            lastr=i;
        }
        else //L
        {
            if((i-lastr)%2==1)
            {
                ans[lastr]+=odd;
                ans[lastr+1]+=even;

            }
            else
            {
                ans[lastr]+=even;
                ans[lastr+1]+=odd;
            }
            odd=0;
            even=0;
        }
    }
    


    for (int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}