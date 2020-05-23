#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main() {
    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i) {
        int lo, hi;
        std::cin >> lo >> hi;
        int num_tries;
        std::cin >> num_tries;
        int head = lo + 1, tail = hi;
        while (true) {
        int m = (head + tail) / 2;
        std::cout << m << std::endl;
        std::string s;
        std::cin >> s;
        if (s == "CORRECT") break;
        if (s == "TOO_SMALL")
            head = m + 1;
        else
            tail = m - 1;
        }
    }
    return 0;
}