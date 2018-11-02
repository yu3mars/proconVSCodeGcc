#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

int main()
{
    int n;
    bool ok = true;
    cin >> n;
    vector<int> t(n+1),x(n+1),y(n+1);
    t.at(0)=0;
    x.at(0)=0;
    y.at(0)=0;
    for(int i = 1; i <= n; i++)
    {
        cin >> t.at(i) >> x.at(i)>>y.at(i);
    }

    
    for(int i = 0; i < n; i++)
    {
        int d = dist(x.at(i),y.at(i),x.at(i+1),y.at(i+1));
        int tdiff = t.at(i+1)-t.at(i);
        if(tdiff >= d && (tdiff - d)%2==0)
        {
            continue;
        }
        else
        {
            ok = false;
            break;
        }
    }
    

    if(ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}