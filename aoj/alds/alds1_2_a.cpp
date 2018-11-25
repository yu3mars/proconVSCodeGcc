#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int bubbleSort(vector<int> a,int n)
{
    int change = 0;
    bool flag = true;
    while(flag)
    {
        flag = false;
        
        for(int j = n-1; j > 0; j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                flag = true;
                change++;
            }
        }
        
    }

    
    for(int i = 0; i < n; i++)
    {
        cout << a.at(i);
        if(i==n-1) cout << endl;
        else cout << " ";
    }
    cout << change << endl;
    return change;
}

int main()
{
	int n;
	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }
    bubbleSort(v,n);
    return 0;
}