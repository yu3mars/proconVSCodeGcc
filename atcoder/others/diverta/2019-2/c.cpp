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
    ll ans=0;
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll minus=0,plus=0,zero=0;
    ll abssum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        abssum+=abs(a[i]);
        if(a[i]<0) minus++;
        else if(a[i]>0) plus++;
        else zero++;
    }
    sort(all(a));
    if(plus==0) plus+=zero;
    else minus+=zero;
    if(n==2)
    {
        cout<<a[1]-a[0]<<endl;
        cout<<a[1]<<" "<<a[0]<<endl;

    }
    else if(plus == n) // hitotsu dake minus
    {
        cout<<abssum-a[0]*2<<endl;
        ll tmp = a[0];
        for (int i = 1; i < n-1; i++)
        {
            cout<<tmp<<" "<<a[i]<<endl;
            tmp=tmp-a[i];
        }
        cout<<a[n-1]<<" "<<tmp<<endl;
    }
    else if(minus == n) // hitotsu dake sonomama
    {
        cout<<abssum+a[n-1]*2<<endl;
        ll tmp = a[n-1];
        for (int i = 0; i < n-1; i++)
        {
            cout<<tmp<<" "<<a[i]<<endl;
            tmp=tmp-a[i];
        }        
    }
    else // zenbu abs
    {
        cout<<abssum<<endl;
        ll tmp = a[0];
        for (int i = minus; i < n-1; i++)
        {
            cout<<tmp<<" "<<a[i]<<endl;
            tmp=tmp-a[i];
        }
        cout<<a[n-1]<<" "<<tmp<<endl;
        tmp=a[n-1]-tmp;
        for (int i = 1; i < minus; i++)
        {
            cout<<tmp<<" "<<a[i]<<endl;
            tmp=tmp-a[i];
        }
                
    }
    

    return 0;
}