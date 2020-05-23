#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    string s;
    string a ="AKIHABARA";
    cin>>s;
    int n=s.size();
    bool ok=true;
    if(n>9)
    {
        ok=false;
    }
    else
    {
        int ap=0;
        int sp=0;
        while (sp<n && ap<9)
        {
            if(s[sp]==a[ap])
            {
                ap++;
                sp++;
            }
            else if(a[ap]=='A')
            {
                ap++;
            }
            else
            {
                ok=false;
                break;
            }            
        }
        if(sp<n) ok=false;
        if(ap<8) ok=false;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}