#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
	int h,w;
	cin >> h >> w;
	int a[510][510];
	for(int yy = 0; yy < h; yy++)
	{
		for(int xx = 0; xx < w; xx++)
		{
			cin>>a[yy][xx];
		}
	}
	int nowy=0,nowx=0,n=0;
	int nexty=0,nextx=0;
	vector<int> y1,y2,x1,x2;
	while(true){
		if(nowy%2==0) //1->2
		{
			if(nowx<w-1)
			{
				nextx=nowx+1;
			}
			else
			{
				nexty=nowy+1;
			}			
		}
		else
		{
			if(nowx>0)
			{
				nextx=nowx-1;
			}
			else
			{
				nexty=nowy+1;
			}	
		}
		if(nexty>=h) break;
		if(a[nowy][nowx]%2>0)
		{
			a[nexty][nextx]++;
			n++;
			y1.push_back(nowy);
			x1.push_back(nowx);
			y2.push_back(nexty);
			x2.push_back(nextx);
		}
		nowy=nexty;
		nowx=nextx;
	}
	cout<<n<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<y1[i]+1<<" "<<x1[i]+1<<" "<<y2[i]+1<<" "<<x2[i]+1<<endl;
	}
	return 0;
}