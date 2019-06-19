#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(prev_permutation(all(a)))
    {
        for(int i = 0; i < n; i++)
        {
            if(i>0)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    next_permutation(all(a));
    for(int i = 0; i < n; i++)
    {
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    if(next_permutation(all(a)))
    {
        for(int i = 0; i < n; i++)
        {
            if(i>0)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    
    return 0;
}