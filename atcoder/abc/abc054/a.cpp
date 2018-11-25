#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int a,b;
    cin>>a>>b;
    if(a==1)a=14;
    if(b==1)b=14;
    if(a>b) cout << "Alice" <<endl;
    else if(a<b) cout << "Bob"<<endl;
    else cout << "Draw"<<endl;

    return 0;
}