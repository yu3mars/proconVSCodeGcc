#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int a,b;
    cin >> a >> b;
    
    
    if (a*b%2==1) {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    
    return 0;
}