#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


struct card
{
    char suit,value;
};


void bubbleSort(card a[],int n)
{
    bool flag = true;
    while(flag)
    {
        flag = false;
        
        for(int j = n-1; j > 0; j--)
        {
            if(a[j].value<a[j-1].value)
            {
                swap(a[j],a[j-1]);
                flag = true;
            }
        }
    }
}

void SelectionSort(card a[],int n)
{
    int swpcnt=0;
    for(int i = 0; i < n; i++)
    {
        int minj=i;
        
        for(int j = i; j < n; j++)
        {
            if(a[j].value<a[minj].value)
            {
                minj=j;
            }
        }
        if(i!=minj)
        {
            swap(a[i],a[minj]);
        }
    }    
}

int main()
{
    int n;
    card c1[40],c2[40];
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        cin>>c1[i].suit>>c1[i].value;
        c2[i]=c1[i];

    }
    bubbleSort(c1,n);
    SelectionSort(c2,n);
    
    for(int i = 0; i < n; i++)
    {
        cout<<c1[i].suit<<c1[i].value;
        if(i<n-1) cout<<" ";
        else cout<<endl;
    }
    cout<<"Stable"<<endl;
    bool isStable=true;
    
    for(int i = 0; i < n; i++)
    {
        cout<<c2[i].suit<<c2[i].value;
        if(i<n-1) cout<<" ";
        else cout<<endl;
        if(c1[i].suit!=c2[i].suit) isStable=false;
    }
    
    if(isStable)cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;

    return 0;
}