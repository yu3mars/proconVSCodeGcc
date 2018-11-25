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
    int n,ans=0;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    
    for(int d = 0; d < n; d++)
    {
        int tmp=0;
        for(int i = 0; i < n; i++)
        {
            if(i<=d) tmp+=a[i];
            if(d<=i) tmp+=b[i];
        }
        ans=max(ans,tmp);
    }
    

    cout<<ans<<endl;

    return 0;
}