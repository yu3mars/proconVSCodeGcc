#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n, y;
    cin >> n >> y;
    int a=-1,b=-1,c=-1;

    
    for(int i = 0; i <= n; i++)
    {
        
        for(int j = 0; j <= n - i; j++)
        {
            int k = n-i-j;
            if(i*10000+j*5000+k*1000 == y)
            {
                a=i;
                b=j;
                c=k;
                break;
            }
        }
        if(a>=0)
        {
            break;
        }
    }
    cout << a << " " << b << " " << c << endl;

    return 0;
}