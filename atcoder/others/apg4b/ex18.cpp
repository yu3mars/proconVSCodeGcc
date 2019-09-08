#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a.at(i) >> b.at(i);
        a[i]--;
        b[i]--;
    }

    // ここにプログラムを追記
    // (ここで"試合結果の表"の2次元配列を宣言)
    vector<vector<char>> ans(n, vector<char>(n, '-'));
    for (int i = 0; i < m; i++)
    {
        ans[a[i]][b[i]]='o';
        ans[b[i]][a[i]]='x';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j];
            if(j==n-1) cout<<endl;
            else cout<<" ";
        }
    }
    
    return 0;
}
