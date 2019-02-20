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
    vector<int> v(6);
    int cnt[4];
    for(int i = 0; i < 4; i++)
    {
        cnt[i]=0;
    }
    
    for(int i = 0; i < 6; i++)
    {
        cin>>v[i];
        cnt[v[i]-1]++;
    }
    bool ok = true;
    for(int i = 0; i < 4; i++)
    {
        if(cnt[i]>2)
        {
            ok = false;
        }
    }
    
    if(ok)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}