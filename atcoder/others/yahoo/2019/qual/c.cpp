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
    ll k,a,b,ans=1;
    cin>>k>>a>>b;
    if(b-a<2 || k<=a)    //kankin shinai
    {
        ans = k+1;
    }
    else
    {
        ans=a;
        k=k-a+1;
        if(k%2==1)
        {
            ans++;
            k--;
        }
        k/=2;
        ll plus = b-a;
        ans+=plus*k;
    }

    cout<<ans<<endl;
    return 0;
}