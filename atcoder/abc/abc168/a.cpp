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
    int n;
    cin>>n;
    n%=10;
    string s="hon";
    if(n==3)
    {
        s="bon";
    }
    else if(n==0||n==1||n==6||n==8)
    {
        s="pon";
    }
    cout<<s<<endl;
    
    return 0;
}