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

int main(){
    string s;
    cin>>s;
    ll n = s.size();
    ll k,ans=0;
    cin>>k;
    ll cnt=0, cnt2=0;
    bool flag = false;// 2kaime sentou wo kaeru
    bool flag2 = false;
    bool n1flag=false, n1flag2=false;

    for (int i = 1; i < n; i++)
    {
        if(s[i]==s[i-1])
        {
            cnt++;
            
            if(i==n-1)
            {
                n1flag = true;
            }
            i++;
        }
    }
    if(n1flag==false && s[0]==s[n-1])
    {
        flag = true;
    }
    for (int i = 0; i < n; i++)
    {
        if(i==0 || s[i]==s[i-1])
        {
            cnt2++;
            if(i==n-1)
            {
                n1flag2 = true;
            }
            i++;
        }
    }
    if(n1flag2==false && s[0]==s[n-1])
    {
        flag2 = true;
    }

    if(flag == false)
    {
        ans=cnt*k;
    }
    else
    {
        if(flag2==false)
        {
            ans = cnt*(k-k/2)+cnt2*(k/2);
        }
        else
        {
            ans = cnt+cnt2*(k-1);
        }
        
    }
    
    
    cout<<ans<<endl;
    return 0;
}