#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int partition(int a[],int p,int r)
{
    int x = a[r];
    int i=p-1;
    for(int j = p; j < r; j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

int main(){
    int n;
    cin>>n;
    int a[100010];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int p = partition(a,0,n-1);
    for(int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        if(i==p)
        {
            cout<<"["<<a[i]<<"]";
        }
        else cout<<a[i];
    }
    cout<<endl;
    
    return 0;
}