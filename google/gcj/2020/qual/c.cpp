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
        vector<tuple<int,int,int>> p(n);
        for (int i = 0; i < n; i++)
        {
            int si,ei;
            cin>>si>>ei;
            p[i]=make_tuple(si,ei,i);
        }
        sort(all(p));
        int time[2] = {0,0};
        char ans[n];
        bool ok=true;
        for (int i = 0; i < n; i++)
        {
            int bg = get<0>(p[i]);
            int en = get<1>(p[i]);
            int id = get<2>(p[i]);
            if (time[0]<=bg)
            {
                ans[id]='C';
                time[0]=en;
            }
            else if(time[1]<=bg)
            {
                ans[id]='J';
                time[1]=en;
            }
            else
            {
                ok=false;
                break;
            }
            
        }
        if(ok)
        {
            for (int i = 0; i < n; i++)
            {
                cout<<ans[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
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