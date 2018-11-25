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
    int n;
    ll ans=1e18;
    cin>>n;
    vector<ll> a(n),imos(n+1),left(n+1),right(n+1);
    imos[0]=0;
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        imos[i+1]=imos[i]+a[i];
    }
    
    for(int i = 0; i < n+1; i++)
    {
        left[i]=1e18;
        right[i]=1e18;
    }
    
    int l=0;
    for(int mid = 2; mid < n-1; mid++)
    {
        left[mid]=l;
        while(l-1<mid)
        {
            if(abs(imos[mid]-imos[l]*2) > abs(imos[mid]-imos[l+1]*2))
            {
                l++;
                left[mid]=l;
            }
            else break;
        }
    }
    
    int r=n;
    for(int mid = n - 2; mid >= 2; mid--)
    {
        right[mid]=r;
        while(r-1>mid)
        {
            //([n]-[r])-([r]-[mid])=[n]+[mid]-2*[r]
            if(abs(imos[n]+imos[mid]-imos[r]*2) > abs(imos[n]+imos[mid]-imos[r-1]*2))
            {
                r--;
                right[mid]=r;
            }
            else break;
        }
    }
    
    for(int mid = 2; mid < n-1; mid++)
    {
        ll w=imos[left[mid]];
        ll x=imos[mid] - imos[left[mid]];
        ll y=imos[right[mid]] - imos[mid];
        ll z=imos[n] - imos[right[mid]];
        ll mi = min(min(w,x),min(y,z));
        ll ma = max(max(w,x),max(y,z));
        ll tmp = ma-mi;
        ans=min(ans,tmp);
    }
    
    cout<<ans<<endl;

    return 0;
}