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
    int n,maxa=0,mina=0;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        
        if(a[i]>a[maxa]) maxa=i;
        if(a[i]<a[mina]) mina=i;
    }
    
    cout<<2*n-1<<endl;
    if(abs(a[maxa])>=abs(a[mina]))
    {
        for(int i = 0; i < n; i++)
        {
            cout<<maxa+1<<" "<<i+1<<endl;
        }
        
        for(int i = 0; i < n-1; i++)
        {
            cout<<i+1<<" "<<i+2<<endl;
        }
        cout<<endl;        
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout<<mina+1<<" "<<i+1<<endl;
        }
        
        for(int i = n-1; i > 0; i--)
        {
            cout<<i+1<<" "<<i<<endl;
        }
        cout<<endl;  
    }

    return 0;
}