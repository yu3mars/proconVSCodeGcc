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
        ll ew, ns;
        cin >> ew >> ns;
        if (ew % 2 == ns % 2)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        bool ewIsPlus, nsIsPlus;

        if (ew >= 0)
            ewIsPlus = true;
        else
        {
            ewIsPlus = false;
            ew = -ew;
        }

        if (ns >= 0)
            nsIsPlus = true;
        else
        {
            nsIsPlus = false;
            ns = -ns;
        }

        ll sm = ew + ns;
        ll keta = 0;
        ll tmp = sm;
        while (tmp > 0)
        {
            keta++;
            tmp = (tmp >> 1);
        }

        bool nIsOdd = (ns % 2 == 1);
        ll llodd, lleven;
        if (nIsOdd)
        {
            llodd = ns;
            lleven = ew;
        }
        else
        {
            llodd = ew;
            lleven = ns;
        }

        vector<vector<ll>> vodd(2), veven(2);
        bool normal = true;

        for (ll i = 0; i < keta; i++)
        {
            ll flgeven = (lleven >> i) & 1;
            ll flgodd = (llodd >> i) & 1;
            ll thisNum = (i);
            if (normal)
            {
                if (flgeven == 0 && flgodd == 0)
                {
                    vodd[1].push_back(thisNum);
                }
                else if (flgeven == 0 && flgodd == 1)
                {
                    vodd[0].push_back(thisNum);
                }
                else if (flgeven == 1 && flgodd == 0)
                {
                    veven[0].push_back(thisNum);
                }
                else if (flgeven == 1 && flgodd == 1)
                {
                    veven[0].push_back(thisNum);
                    normal = false;
                }
            }
            else
            {
                if (flgeven == 0 && flgodd == 0)
                {
                    veven[1].push_back(thisNum);
                }
                else if (flgeven == 0 && flgodd == 1)
                {
                    veven[0].push_back(thisNum);
                }
                else if (flgeven == 1 && flgodd == 0)
                {
                    vodd[0].push_back(thisNum);
                }
                else if (flgeven == 1 && flgodd == 1)
                {
                    vodd[0].push_back(thisNum);
                    normal = false;
                }
            }
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