#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,k,now=1;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        if(now > k)
        {
            now+=k;
        }        
        else
        {
            now*=2;
        }        
    }
    cout << now << endl;
 
    return 0;
}