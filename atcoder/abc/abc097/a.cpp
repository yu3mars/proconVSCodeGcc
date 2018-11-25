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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(abs(a-c)<=d || (abs(a-b)<=d && abs(b-c)<=d))
    {
        cout << "Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}