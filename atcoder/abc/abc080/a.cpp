#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    
    cout << min(a * n, b) << endl;

    return 0;
}