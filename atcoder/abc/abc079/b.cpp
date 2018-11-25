#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n;
    cin >>n;
    vector<ll> v;
    v.push_back(2);
    v.push_back(1);
    
    for(int i = 2; i <= n; i++)
    {
        v.push_back(v[i-1]+v[i-2]);
    }
    cout << v[n]<<endl;

    return 0;
}