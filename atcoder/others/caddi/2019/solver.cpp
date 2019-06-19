#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx6[6] = {1, 0,-1, 0, 0, 0}, 
	dy6[6] = {0, 1, 0,-1, 0, 0},
	dz6[6] = {0, 0, 0, 0, 1,-1} ;


vector<int> R, P, A, B, C, D, X,Y,Z;
vector<int> used;
int L, N, M;

bool addAble(int u,int x, int y, int z)
{
	bool ok = true;
	if(x-R[u]<0 || x+R[u]>L ||y-R[u]<0 || y+R[u]>L ||y-R[u]<0 || y+R[u]>L)
	{
		ok = false;
	}
	else
	{
		for(int i = 0; i < used.size(); i++)
		{
			if(pow(x-X[used[i]],2)+
				pow(y-Y[used[i]],2)+
				pow(z-Z[used[i]],2)>
				pow(R[u]+R[used[i]],2))
			{
				ok=false;
				break;
			}
		}		
	}
	
	return ok;
}


int main() {
	
	//入力処理
	cin >> L >> N >> M;
	R=vector<int>(N);
	P=vector<int>(N);
	A=vector<int>(M);
	B=vector<int>(M);
	C=vector<int>(M);
	D=vector<int>(M);

	X=vector<int>(N, -1);
	Y=vector<int>(N, -1);
	Z=vector<int>(N, -1);

	for (int i = 0; i < N; i++)
	{
		cin >> R[i] >> P[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		A[i]--; B[i]--; C[i]--; D[i]--;
	}

	//2つの球+組み合わせポイントで最大のものを探す。
	priority_queue<pii> pq; //point, id
	//long long bestPoint = 0;
	for (int i = 0; i < N; i++)
	{
		int pt = P[A[i]] + P[B[i]] + D[i];
		pq.push(make_pair(pt,i));
	}
	for(int i = 0; i < pq.size(); i++)
	{
		pii pi = pq.top();
		pq.pop();
		int id=pi.second;
		int a = A[id];
		int b = B[id];
		if(R[a]<R[b]) 
		{
			swap(a,b);
		}
		//aの設置
		if(used.size()==0)
		{
			X[a]=R[a];
			Y[a]=R[a];
			Z[a]=R[a];
			used.push_back(a);
		}
		else
		{
			if(X[b]==-1)//bが設置されていない
			{
				for(int d6 = 0; d6 < 6; d6++)
				{
					if(addAble(a,X[b]+R[a]*dx6[i],Y[b]+R[a]*dy6[i],Z[b]+R[a]*dz6[i]))
					{
						X[a]=X[b]+R[a]*dx6[i];
						Y[a]=Y[b]+R[a]*dy6[i];
						Z[a]=Z[b]+R[a]*dz6[i];
						used.push_back(a);
						break;
					}
				}
			}
			else
			{
				for(int ci = used.size() - 1; ci >= 0; ci--)
				{
					bool done=false;
					int c = used[ci];
					for(int d6 = 0; d6 < 6; d6++)
					{
						if(addAble(a,X[c]+R[a]*dx6[i],Y[c]+R[a]*dy6[i],Z[c]+R[a]*dz6[i]))
						{
							X[a]=X[c]+R[a]*dx6[i];
							Y[a]=Y[c]+R[a]*dy6[i];
							Z[a]=Z[c]+R[a]*dz6[i];
							used.push_back(c);
							done=true;
							break;
						}
					}
					if(done) break;
				}
				
				

			}
			
		}
		if(X[b]==-1)//bが設置されていない
			{
				for(int d6 = 0; d6 < 6; d6++)
				{
					if(addAble(b,X[a]+R[b]*dx6[i],Y[a]+R[b]*dy6[i],Z[a]+R[b]*dz6[i]))
					{
						X[b]=X[a]+R[b]*dx6[i];
						Y[b]=Y[a]+R[b]*dy6[i];
						Z[b]=Z[a]+R[b]*dz6[i];
						used.push_back(b);
						break;
					}
				}
			}
	}
	

	//全球を出力する
	for (int i = 0; i < N; i++)
	{
		cout << X[i] << " " << Y[i] << " " << Z[i] << endl;
	}

	return 0;
}

