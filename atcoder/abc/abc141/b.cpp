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
    cin>>s;
    bool ok = true;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if(i%2==0) //RUD
        {
            if(s[i]=='L') ok=false;
        }
        else    //LUD
        {
            if(s[i]=='R') ok=false;            
        }
    }
    
    if(ok)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    
    return 0;
}