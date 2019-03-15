#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int n;
int s[500010];
int l[260000],r[260000];
int inf=INT_MAX;
int cnt;

void merge(int a[], int left, int mid, int right)
{
    int n1 = mid-left;
    int n2 = right-mid;
    for(int i = 0; i < n1; i++)
    {
        l[i]=a[left+i];
    }
    for(int i = 0; i < n2; i++)
    {
        r[i]=a[mid+i];
    }
    l[n1]=inf;
    r[n2]=inf;
    int i=0,j=0;
    for(int k = left; k < right; k++)
    {
        cnt++;
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
    }
}

void mergeSort(int a[], int left, int right)
{
    if(left+1<right)
    {
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int main(){
    cnt=0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    mergeSort(s,0,n);

    for(int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        cout<<s[i];
    }
    cout<<endl;
    cout<<cnt<<endl;    
    return 0;
}