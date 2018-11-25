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
    cin>>n;
    vector<ll> a(n),b(n);
    ll suma=0,sumb=0,adda=0,addb=0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        suma+=a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
        sumb+=b[i];
    }
    ll diff=sumb-suma;
    for(int i = 0; i < n; i++)
    {
        if(a[i]<b[i])
        {
            adda+=(b[i]-a[i])/2;
            if((b[i]-a[i])%2>0)
            {
                adda++;
                addb++;
            }
        }
        else if(a[i]>b[i])
        {
            addb+=(a[i]-b[i]);
        }
    }
    
    if(adda<=diff &&addb<=diff)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}