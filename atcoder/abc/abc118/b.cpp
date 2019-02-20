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
    int n,m,ans=0;
    cin>>n>>m;
    bool ls[30][30];
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            ls[i][j]=false;
        }
        
    }
    
    for(int person = 0; person < n; person++)
    {
        int k;
        cin>>k;
        for(int i = 0; i < k; i++)
        {
            int a;
            cin>>a;
            a--;
            ls[person][a]=true;
        }        
    }
    
    for(int food = 0; food < m; food++)
    {
        bool ok = true;
        for(int person = 0; person < n; person++)
        {
            if(ls[person][food]==false)
            {
                ok=false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;

    return 0;
}