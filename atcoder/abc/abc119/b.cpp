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
    int n;
    cin>>n;
    double rate = 380000,ans=0;
    for(int i = 0; i < n; i++)
    {
        double x;
        string u;
        cin>>x>>u;
        if(u=="JPY")
        {
            ans+=x;
        }
        else
        {
            ans+=x*rate;
        }
        
    }
    
    
    cout<<ans<<endl;
    return 0;
}