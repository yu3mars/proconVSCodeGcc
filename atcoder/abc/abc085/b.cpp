#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    
    
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        s.emplace(d);
    }
    
    cout << s.size() << endl;
    
    return 0;
}