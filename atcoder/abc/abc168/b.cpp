#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int k;
    string s;
    cin>>k>>s;
    int sn=s.size();
    if(k>=sn)
    {
        cout<<s<<endl;
    }
    else
    {
        for(int i=0;i<k;i++)
        {
            cout<<s[i];
        }
        cout<<"..."<<endl;
    }
    
    
    return 0;
}