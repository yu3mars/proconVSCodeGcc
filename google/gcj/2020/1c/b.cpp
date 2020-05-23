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
        int u;
        cin >> u;
        vector<string> q(10000);
        vector<string> r(10000);
        for (int i = 0; i < 10000; i++)
        {
            cin >> q[i] >> r[i];
        }
        unordered_map<char, ll> mp;
        unordered_set<char> szero, snonzero;
        for (int qi = 0; qi < 10000; qi++)
        {
            char c = r[qi][0];
            if (mp.find(c) == mp.end())
            {
                mp.emplace(c, 1);
                szero.insert(c);
            }
            else
            {
                mp[c]++;
            }

            for (int ri = 0; ri < r[qi].size(); ri++)
            {
                char cc = r[qi][ri];
                if (snonzero.find(cc) == snonzero.end())
                {
                    snonzero.insert(cc);
                }
            }
        }
        vector<pair<ll, char>> v;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            v.push_back(make_pair(it->second, it->first));
        }
        sort(all(v));
        reverse(all(v));

        for (int i = 0; i < v.size(); i++)
        {
            //cout << v[i].first << " " << v[i].second << endl; //
        }

        string ans;
        for (auto it = snonzero.begin(); it != snonzero.end(); it++)
        {
            char c=*it;
            if(szero.find(c)==szero.end())
            {
                ans+=c;
            }
            //cout<<c<<endl;//
        }
        

        for (int i = 0; i < v.size(); i++)
        {
            ans += v[i].second;
        }

        cout << ans << endl;
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