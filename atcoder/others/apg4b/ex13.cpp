#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum =0;

    for(int i = 0; i < n; i++)
    {
        cin >> v.at(i);
        sum += v.at(i);
    }
    int ave = sum/n;
    for(int i = 0; i < n; i++)
    {
        cout << abs(v.at(i) - ave) << endl;
    }
    

}
