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
        int n;
        cin>>n;
        vector<string> vs(n);
        string ans;
        vector<bool> win(n);
        int wincnt=0;
        for(int i = 0; i < n; i++)
        {
            cin>>vs[i];
            win[i]=false;
        }
        while(wincnt<n && ans.size()<500)
        {
            int j = ans.size();
            bool r=false,p=false,s=false;
            for(int i = 0; i < n; i++)
            {
                if(win[i]) continue;
                if(vs[i][j%vs[i].size()]=='R') r=true;
                else if(vs[i][j%vs[i].size()]=='P') p=true;
                else if(vs[i][j%vs[i].size()]=='S') s=true;
            }
            if(r&&p&&s)
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
            if(r&&!p&&!s)//r
            {
                ans+='P';
                cout<<ans<<endl;
                return;
            }
            if(!r&&p&&!s)//p
            {
                ans+='S';
                cout<<ans<<endl;
                return;
            }
            if(!r&&!p&&s)//s
            {
                ans+='R';
                cout<<ans<<endl;
                return;
            }
            if(r&&!p&&s)//rs
            {
                for(int i = 0; i < n; i++)
                {
                    if(win[i]) continue;
                    if(vs[i][j]=='R') continue;
                    if(vs[i][j]=='S') 
                    {
                        win[i]=true;
                        wincnt++;
                    }
                }
                ans+='R';
            }
            if(r&&p&&!s)//rp
            {
                for(int i = 0; i < n; i++)
                {
                    if(win[i]) continue;
                    if(vs[i][j]=='P') continue;
                    if(vs[i][j]=='R') 
                    {
                        win[i]=true;
                        wincnt++;
                    }
                }
                ans+='P';
            }
            if(!r&&p&&s)//ps
            {
                for(int i = 0; i < n; i++)
                {
                    if(win[i]) continue;
                    if(vs[i][j]=='S') continue;
                    if(vs[i][j]=='P') 
                    {
                        win[i]=true;
                        wincnt++;
                    }
                }
                ans+='S';
            }
        }
        cout<<"IMPOSSIBLE"<<endl;
        return;
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