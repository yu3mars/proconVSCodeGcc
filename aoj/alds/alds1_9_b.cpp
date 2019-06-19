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

int a[500010];
int h;

int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return i*2;
}
int right(int i)
{
    return i*2+1;
}
void maxHeapify(int i)
{
    int l=left(i);
    int r=right(i);
    int largest = i;
    if(l<=h && a[i]<a[l])
    {
        largest=l;
    }
    if(r<=h && a[largest]<a[r])
    {
        largest=r;
    }
    if(i!=largest)
    {
        swap(a[largest],a[i]);
        maxHeapify(largest);
    }
}

int main(){
    cin>>h;
    for(int i = 0; i < h; i++)
    {
        cin>>a[i+1];
    }
    for(int i = h/2; i >= 1; i--)
    {
        maxHeapify(i);
    }
    for(int i = 1; i <= h; i++)
    {
        cout<<" "<<a[i];
    }
    cout<<endl;
    
    return 0;
}