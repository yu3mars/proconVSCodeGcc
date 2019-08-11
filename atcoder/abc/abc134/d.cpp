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
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<bool> b(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        b[i]=false;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int num=i+1;
        bool upper = false;
        for (int j = i+num; j < n; j+=num)
        {
            if(b[j]==true)
            {
                upper=!upper;
            }
        }
        bool isone = (a[i]==1);
        if(isone != upper)
        {
            b[i]=true;
        }
    }
    
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        if(b[i]==true)
        {
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if(i!=0)cout<<" ";
        cout<<ans[i];
    }
    if(ans.size()>0) cout<<endl;

    return 0;
}