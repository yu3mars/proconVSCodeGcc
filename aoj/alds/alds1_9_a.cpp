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

int a[260];

int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return i*2;
}
int right(int i)
{
    return i*2+1;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i+1];
    }
    for(int i = 1; i <= n; i++)
    {
        cout<<"node "<<i<<": key = "<<a[i]<<", ";
        if(parent(i)>0) cout<<"parent key = "<<a[parent(i)]<<", ";
        if(left(i)<=n) cout<<"left key = "<<a[left(i)]<<", ";
        if(right(i)<=n) cout<<"right key = "<<a[right(i)]<<", ";
        cout<<endl;
    }
    
    
    return 0;
}