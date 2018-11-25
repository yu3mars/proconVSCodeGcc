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
    vector<int> x(n),y(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
        y[i]=x[i];
    }
    sort(all(y));
    int mid = y[n/2-1];
    
    for(int i = 0; i < n; i++)
    {
        if(x[i]<=mid) cout<<y[n/2]<<endl;
        else cout<<mid<<endl;
    }

    return 0;
}