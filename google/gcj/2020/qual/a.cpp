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
        vector<int> m[n];
        int k=0,r=0,c=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int mm;
                cin>>mm;
                m[i].push_back(mm);
            }
        }
        
        // taikaku
        for (int i = 0; i < n; i++)
        {
            k+=m[i][i];
        }
        // gyou
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> se;
            bool repeated=false;
            for (int j = 0; j < n; j++)
            {
                int now = m[i][j];
                if(se.find(now)==se.end())
                {
                    se.insert(now);
                }
                else
                {
                    repeated=true;
                    break;
                }                
            }
            if(repeated==true) r++;
        }
        // retsu
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> se;
            bool repeated=false;
            for (int j = 0; j < n; j++)
            {
                int now = m[j][i];
                if(se.find(now)==se.end())
                {
                    se.insert(now);
                }
                else
                {
                    repeated=true;
                    break;
                }                
            }
            if(repeated==true) c++;
        }
        cout<<k<<" "<<r<<" "<<c<<endl;
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