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
    int ans=0;
    int n;
    cin>>n;
    vector<string> s(n);
    vector<bool> bgnb(n),enda(n);
    int acnt=0,bcnt=0;
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
        if(s[i][0]=='B'){ 
            bgnb[i]=true;
            bcnt++;
        }
        if(s[i][s[i].size()-1]=='A'){
            enda[i]=true;
            acnt++;
        }
        for(int j = 0; j < s[i].size()-1; j++)
        {
            if(s[i][j]=='A' &&s[i][j+1]=='B') ans++;
        }
    }
    if(acnt==bcnt && acnt>0)
    {
        bool ok=false;
        for(int i = 0; i < n; i++)
        {
            if(bgnb[i]!=enda[i]) 
            {
                ok=true;
                break;
            }
        }
        ans+=min(acnt,bcnt);
        if(ok==false)
        {
            ans--;
        }
        
    }
    else
    {
        ans+=min(acnt,bcnt);
    }
    

    cout<<ans<<endl;
    return 0;
}