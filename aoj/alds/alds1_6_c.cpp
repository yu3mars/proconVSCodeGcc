#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

pic l[100010],r[100010];

void merge(pic a[], int left, int mid, int right)
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
    l[n1]=make_pair(INT_MAX,'Z');
    r[n2]=make_pair(INT_MAX,'Z');
    int i=0,j=0;
    for(int k = left; k < right; k++)
    {
        if(l[i].first<=r[j].first)
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

void mergeSort(pic a[], int left, int right)
{
    if(left+1<right)
    {
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int partition(pic a[],int p,int r)
{
    int x = a[r].first;
    int i=p-1;
    for(int j = p; j < r; j++)
    {
        if(a[j].first<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quickSort(pic a[],int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}

void print(pic p)
{
    cout<<p.second<<" "<<p.first<<endl;
}

int main(){
    int n;
    cin>>n;
    pic aq[100010],am[100010];
    for(int i = 0; i < n; i++)
    {
        char cc;
        int nn;
        cin>>cc>>nn;
        aq[i]=make_pair(nn,cc);
        am[i]=make_pair(nn,cc);
    }
    quickSort(aq,0,n-1);
    mergeSort(am,0,n);
    bool stable=true;
    for(int i = 0; i < n; i++)
    {
        if(aq[i].second!=am[i].second)
        {
            stable=false;
            break;
        }
    }
    if(stable) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;

    for(int i = 0; i < n; i++)
    {
        print(aq[i]);
    }
    
    
    return 0;
}