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
        string s;
        cin>>s;
        int n=s.size();
        int depth=0;
        for (int i = 0; i < n; i++)
        {
            int num=s[i]-'0';
            if(depth<num)
            {
                for (int i = 0; i < num-depth; i++)
                {
                    cout<<"(";
                }                
            }
            else if(depth>num)
            {
                for (int i = 0; i < depth-num; i++)
                {
                    cout<<")";
                }                
            }
            cout<<num;
            depth=num;
        }
        if(depth>0)
        {
            for (int i = 0; i < depth; i++)
            {
                cout<<")";
            }                
        }
        cout<<endl;

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