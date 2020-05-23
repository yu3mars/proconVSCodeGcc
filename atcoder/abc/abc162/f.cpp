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
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(n%2==0)
    {
        ll odd=0,even=0;
        for (int i = 0; i < n; i+=2)
        {
            even+=a[i];
        }
        for (int i = 1; i < n; i+=2)
        {
            odd+=a[i];
        }
        cout<<max(odd,even)<<endl;
        
    }
    else
    {
        vector<ll> odd,even;
        ll oddMin=1e10,evenMin=1e10;
        for (int i = 1; i < n; i+=2)
        {
            if(i==1)
            {
                odd.push_back(a[i]);
            }
            else
            {
                odd.push_back(odd[odd.size()-1]+a[i]);
            }
            oddMin=min(oddMin,a[i]);
        }
        for (int i = 0; i < n; i+=2)
        {
            if(i==0)
            {
                even.push_back(a[i]);
            }
            else
            {
                even.push_back(even[even.size()-1]+a[i]);
            }
            evenMin=min(evenMin,a[i]);
        }
        ll oddans= odd[odd.size()-1];
        ll evenans =  even[even.size()-1]-evenMin;
        ll ans = max(oddans,evenans);
        cout<<oddans<<"\t"<<evenans<<endl;//
        for (int i = 0; i < n/2 ; i++)
        {
            ll tmp = even[i]+odd[odd.size()-1]-odd[i];
            ans=max(ans,tmp);
            cout<<i+odd.size()-1-i<<"\t"<<i<<"\t"<<tmp<<endl;//
        }
        for (int i = 0; i < n/2 ; i++)
        {
            ll tmp = even[even.size()-1]- even[i+1]+odd[i];
            ans=max(ans,tmp);
            cout<<i+even.size()-1-(i+1)<<"\t"<<i<<"\t"<<tmp<<endl;//
        }
        for (int i = 0; i < n/2 ; i++)
        {
            ll tmp = even[even.size()-1]- a[i*2] - a[i*2+2] +a[i*2+1];
            ans=max(ans,tmp);
            cout<<i+even.size()-1-(i+1)<<"\t"<<i<<"\t"<<tmp<<endl;//
        }
        


        cout<<ans<<endl;
    }
    
    
    return 0;
}