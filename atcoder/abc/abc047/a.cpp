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
    vector<int> n(3);
    bool ok = false;
    for(int i = 0; i < 3; i++)
    {
        cin>>n[i];
    }
    
    for(int i = 0; i < 3; i++)
    {
        if(n[i%3] == n[(i+1)%3] + n[(i+2)%3])
        {
            ok = true;
        }
    }
    
    if(ok) cout << "Yes"<<endl;
    else cout <<"No" <<endl; 
 
    return 0;
}