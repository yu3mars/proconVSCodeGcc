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
    int n,ans=0;
    string a,b,c;
    cin>>n>>a>>b>>c;
    
    for(int i = 0; i < n; i++)
    {
        if(a[i]==b[i] && b[i]==c[i])
        {

        }
        else if(a[i]==b[i] || b[i]==c[i]||c[i]==a[i])
        {
            ans++;
        }
        else 
        {
            ans+=2;
        }
    }
    

    cout<<ans<<endl;
    return 0;
}