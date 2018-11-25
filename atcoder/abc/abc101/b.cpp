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
    int n,s =0;
    cin >>n;
    int temp =n;
    
    while(temp>0)
    {
        s+=temp%10;
        temp/=10;    
    }
    if(n%s==0)
    {
        cout << "Yes"<<endl;
    }
    else
    {
        cout << "No"<<endl;
    }

    return 0;
}