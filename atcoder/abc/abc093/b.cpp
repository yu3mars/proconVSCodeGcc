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
    int a,b,k;
    cin>>a>>b>>k;
    if(b-a+1 < 2*k)
    {
        
        for(int i = a; i <= b; i++)
        {
            cout << i<<endl;
        }
        
    }
    else
    {
        
        for(int i = 0; i < k; i++)
        {
            cout << a+i << endl;
        }
        
        for(int i = k - 1; i >= 0; i--)
        {
            cout << b-i << endl;
        }
        
        
    }
    return 0;
}