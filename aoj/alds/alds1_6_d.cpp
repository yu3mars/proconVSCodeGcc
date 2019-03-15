#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int n,a[1010],s;
int b[1010],t[10010];
bool v[1010];

int solve(){
    int ans=0;
    for(int i = 0; i < n; i++)
    {
        b[i]=a[i];
        v[i]=false;
    }
    sort(b,b+n);
    for(int i = 0; i < n; i++)
    {
        t[b[i]]=i;
    }
    for(int i = 0; i < n; i++)
    {
        if(v[i]) continue;
        int cur = i;
        int sm = 0;
        int mi=INT_MAX;
        int an=0;
        while(true){
            v[cur]=true;
            an++;
            int val = a[cur];
            mi=min(mi,val);
            sm+=val;
            cur=t[val];
            if(v[cur]) break;
        }

        ans+=min(sm+(an-2)*mi,sm+mi+(an+1)*s);
    }
    

    return ans;
}

int main(){
    cin>>n;
    s=INT_MAX;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        s=min(s,a[i]);
    }
    int ans= solve();
    cout<<ans<<endl;

    return 0;
}