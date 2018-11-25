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
    int n,sum=0;
    cin>>n;
    vector<int> a(n+2);
    a[0]=0;
    a[n+1]=0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    
    for(int i = 0; i <= n; i++)
    {
        sum+=abs(a[i]-a[i+1]);
    }
    
    for(int i = 1; i <= n; i++)
    {
        int tmp = sum -abs(a[i-1]-a[i])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]);
        cout<<tmp<<endl;
    }
    

    return 0;
}