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

int a[2000010],b[2000010],c[10010];

int main(){
    int n;
    cin>>n;
    m0(a);
    m0(b);
    m0(c);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for(int i = 0; i < 10005; i++)
    {
        c[i+1]=c[i]+c[i+1];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        c[a[i]]--;
        b[c[a[i]]]=a[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        cout<<b[i];
    }
    cout<<endl;
    
    
    return 0;
}