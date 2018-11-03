#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int n;
    cin >> n;
    vector<int> ls;
    
    for(int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        bool done = false;
        for(int j = 0; j < ls.size(); j++)
        {
            if(w <= ls.at(j))
            {
                ls.at(j) = w;
                done = true;
                break;
            }
        }
        if(done == false)
        {
            ls.push_back(w);
        }
    }
    
    cout << ls.size() << endl;

    return 0;
}