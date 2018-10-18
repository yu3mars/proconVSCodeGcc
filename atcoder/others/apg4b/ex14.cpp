#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int ma = max(A,max(B,C));
    int mi = min(A,min(B,C));
    cout << ma-mi << endl;
}
