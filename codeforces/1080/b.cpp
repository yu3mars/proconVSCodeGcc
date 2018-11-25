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
    int q;
    cin>>q;
    
    for(int qq = 0; qq < q; qq++)
    {
        ll l,r,ans=0;
        cin>>l>>r;
        ans=-(l+r)*(r-l+1)/2;
        if(l%2==1)l++;
        if(r%2==1)r--;
        if(l<=r)
        {
            ans+=(r+l)*(r-l+2)/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}