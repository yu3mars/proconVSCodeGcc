#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

void SelectionSort(int a[],int n)
{
    int swpcnt=0;
    for(int i = 0; i < n; i++)
    {
        int minj=i;
        
        for(int j = i; j < n; j++)
        {
            if(a[j]<a[minj])
            {
                minj=j;
            }
        }
        if(i!=minj)
        {
            swap(a[i],a[minj]);
            swpcnt++;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout<<a[i];
        if(i < n-1) cout<<" ";
        else cout<<endl;
    }
    cout<<swpcnt<<endl;
    
}

int main()
{
    int n,a[110];
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    SelectionSort(a,n);

    return 0;
}