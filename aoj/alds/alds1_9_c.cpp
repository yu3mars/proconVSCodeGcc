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

int a[2000010];
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


void heapIncreasekey(int i, int key)
{
    if(key<a[i]) return;
    a[i]=key;
    while(i>1 && a[i]>a[parent(i)])
    {
        swap(a[i],a[parent(i)]);
        i=parent(i);
    }
}
void insert(int key)
{
    h++;
    a[h]=INT_MIN;//error
    heapIncreasekey(h,key);
}

int extract()
{
    if(h<1) return INT_MIN;//error
    int ret=a[1];
    a[1]=a[h];
    h--;
    maxHeapify(1);
    return ret;
}

int main(){
    h=0;
    while(true){
        string cmd;
        cin>>cmd;
        if(cmd=="insert")
        {
            int k;
            cin>>k;
            insert(k);
        }
        else if(cmd=="extract")
        {
            cout<<extract()<<endl;
        }
        else//end
        {
            break;
        }
        
    }
    
    
    
    return 0;
}