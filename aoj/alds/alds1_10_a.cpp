#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};



int main(){
    int n;
    cin>>n;

    ll dp[50];
    dp[0]=1;
    dp[1]=1;
    for(int i = 2; i < 50; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;    
    
    return 0;
}