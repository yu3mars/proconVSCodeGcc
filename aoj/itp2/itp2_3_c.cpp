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
    int q;
    cin>>q;
    for(int qq = 0; qq < q; qq++)
    {
        int b,e,k;
        cin>>b>>e>>k;
        int cnt=0;
        for(int i = b; i < e; i++)
        {
            if(a[i]==k) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}