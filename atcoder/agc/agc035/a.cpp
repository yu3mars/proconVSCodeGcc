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
    bool ans = false;
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    if(a[0]==0&&a[n-1]==0)
    {
        ans=true;
    }
    else if(n%3==0)
    {
        ll nn = n/3;
        if(a[0]==a[nn-1] && a[nn]==a[nn*2-1] && a[nn*2]==a[nn*3-1])
        {
            if(a[0]==0 && a[nn]==a[nn*2])
            {
                ans=true;
            }
            else if ((a[0]^a[nn])==a[nn*2])
            {
                ans=true;
            }
        }
    }
    if(ans==true)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    return 0;
}