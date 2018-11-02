#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,a,b, ans=0;
    cin >> n>>a>>b;
    
    for(int i = 1; i <= n; i++)
    {
        int now = i;
        int cnt = 0;
        while(now>0){
            cnt += now%10;
            now/=10;
        }
        if(a<=cnt && cnt <=b) 
        {
            ans +=i;
        }
        
    }
    

    cout << ans << endl;
    
    return 0;
}