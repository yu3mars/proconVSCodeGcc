#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int a,b,ans=0;
    cin >> a >> b;
    
    
    for(int i = a; i <= b; i++)
    {
        if(i%10 == i/10000 % 10 && 
            i/10%10 == i/1000%10)
            {
                ans++;
            }
    }
    

    cout << ans << endl;

    return 0;
}