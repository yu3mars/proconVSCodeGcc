#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,tmp, fx=0;
    cin >> n;
    tmp=n;
    while(tmp>0)
    {
        fx+=tmp%10;
        tmp/=10;
    }

    if(n % fx == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}