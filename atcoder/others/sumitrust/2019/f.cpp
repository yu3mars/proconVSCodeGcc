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
    ll t[2],a[2],b[2];
    cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];
    for (int i = 0; i < 2; i++)
    {
        a[i]-=b[i];
        b[i]=0;
    }
    if(a[0]<0) //a[0]>0
    {
        for (int i = 0; i < 2; i++)
        {
            a[i]*=-1;
        }        
    }
    for (int i = 0; i < 2; i++)
    {
        a[i]*=t[i];
    }

    ll diff = a[0]+a[1];
    //cout<<a[0]<<"\t"<<a[1]<<"\t"<<diff<<endl;//
    
    if(a[0]+a[1]==0)
    {
        cout<<"infinity"<<endl;
    }
    else if(a[1]>=0) //sa ga hiraku ippou
    {
        cout<<0<<endl;
        //cout<<"a"<<endl;
    }
    //a[0]>0,a[1]<0
    else if(a[0]+a[1]>0)
    {
        cout<<0<<endl;
        //cout<<"b"<<endl;
    }
    else
    {
        ll ans=(a[0]/(-diff))*2;
        if(a[0]%(-diff)!=0) ans++;
        cout<<ans<<endl;
    }
    
    return 0;
}