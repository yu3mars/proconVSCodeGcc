#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()

int main()
{
    string s;
    cin >> s;
    string ls[] = {"dream", "dreamer", "erase", "eraser"};
    bool ok = true;
    
    reverse(all(s));
    for(int i = 0; i < 4; i++)
    {
        reverse(all(ls[i]));
    }
        
    int cnt = 0;
    
    while(cnt < s.length())
    {        
        bool ok2 = false;
        for(int i = 0; i < 4; i++)
        {
            string d = ls[i];
            if(s.substr(cnt, d.length()) == d)
            {
                cnt += d.length();
                ok2=true;
                break;

            }
        }
        if(!ok2)
        {
            ok=false;
            break;
        }
    }
    

    if(ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}