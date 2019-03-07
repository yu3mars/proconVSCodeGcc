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
	int n, x, mi, ans;
	cin >> n >> x;
	vector<int> v;
	v.push_back(x);
	mi = x;
	for (int i = 0; i < n; i++)
	{
		int ii;
		cin >> ii;
		v.push_back(ii);
		mi = min(mi, ii);
	}
	for (int i = 0; i < n; i++)
	{
		v[i] -= mi;
		if (v[i] == 0)
		{
			v.erase(v.begin() + i);
			i--;
		}
	}
	ans = v[0];
	for (int i = 1; i < n; i++)
	{
		ans = __gcd(ans, v[i]);
	}
	cout << ans << endl;
	return 0;
}