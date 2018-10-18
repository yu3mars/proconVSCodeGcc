#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // ここにプログラムを追記
    int ans = 1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s.at(i)=='+') ans++;
        if(s.at(i)=='-') ans--;
    }
    cout << ans << endl;

}
