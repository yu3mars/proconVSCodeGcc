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
    vector<int> a(n),b(n),ans(n);
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
        a[i]=b[i];
    }
    bool ok = true;
    for(int teban = n - 1; teban >= 0; teban--)
    {
        bool deleted = false;
        for(int pos = teban; pos >= 0; pos--)
        {
            if(a[pos]==pos+1)
            {
                //cout<<teban<<"\t"<<pos<<endl;
                ans[teban]=pos+1;
                a.erase(a.begin() + pos);
                deleted=true;
                break;
            }
        }
        if(deleted == false)
        {
            ok = false;
            break;
        }
    }
    
    
    
    if(ok)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    else
    {
        cout<<-1<<endl;
    }
    
    return 0;
}