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
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for(int i = n - 1; i >= 0; i-=2)
    {
        if(i!=n-1) cout<<" ";
        cout<<a[i];
    }
    
    if(n%2==0)
    {
        for(int i = 0; i < n; i+=2)
        {
            cout<<" "<<a[i];
        }    
    }
    else
    {
        
        for(int i = 1; i < n; i+=2)
        {
            cout<<" "<<a[i];
        }
        
    }

    return 0;
}