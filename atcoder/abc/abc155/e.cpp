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
    ll ans=0;
    string s;
    cin>>s;
    int inc=0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        int n=s[i]-'0';
        int n10;
        n+=inc;
        inc=n/10;
        n=n%10;
        int inc2=inc;
        if(i>0) inc2+=s[i-1]-'0';
        if(n<5 || (n==5 && inc2<5))
        {
            ans+=n;
        }
        else
        {
            ans+=max(0,10-n);
            inc+=1;
        }
        
    }
    cout<<ans+inc<<endl;
    

    return 0;
}