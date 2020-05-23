#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

class GoogleCodeJam
{
public:
    string case_prefix;
    void exec()
    {
        int x,y;
        string s;
        cin>>x>>y>>s;
        int ans=-1;
        if(x==0&&y==0)
        {
            ans=0;
        }
        else
        {
            for (int time = 0; time < s.size(); time++)
            {
                char c=s[time];
                if(c=='S') y--;
                if(c=='N') y++;
                if(c=='E') x++;
                if(c=='W') x--;
                if(abs(x)+abs(y) <= time+1) 
                {
                    ans=time+1;
                    break;
                }
            }   
        }        
        if(ans==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else 
        {
            cout<<ans<<endl;
        }
    }
    GoogleCodeJam()
    {
        int T;
        std::cin >> T;
        for (int i = 1; i <= T; i++)
        {
            case_prefix = "Case #" + std::to_string(i) + ": ";
            cout << case_prefix;
            exec();
        }
    }
};

int main()
{
    GoogleCodeJam();

    return 0;
}