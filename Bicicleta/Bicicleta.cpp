#include<bits/stdc++.h>
using namespace std;


/*
	Exemplo de input:
		1#10I01
		011#10#
		F010001
	I  -> ponto inicial
	F  -> ponto final
	#  -> barreira
	0-1-> custo para chegar naquele ponto
*/
#define f first
#define s second
#define inf 0x3f3f3f3f

const int MAXN = 1000;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int n,m;
string Mat[MAXN+10];
pair<int,int> ini,fim;
int dist[MAXN+10][MAXN+10];

int bfs(){
	memset(dist,63,sizeof dist);
	dist[ini.f][ini.s] = 0;
	deque<pair<int,int>> dq;
	dq.push_back(ini);
	while(!dq.empty()){
		pair<int,int> u = dq.front();
		dq.pop_front();
		for(int i=0;i<4;i++){
			pair<int,int> w = {u.f+dx[i],u.s+dy[i]};
			if(w.f<0 or w.f>=n or w.s<0 or w.s>=m) continue;
			if(Mat[w.f][w.s]=='#') continue;
			int d;
			if(Mat[w.f][w.s]=='I' or Mat[w.f][w.s]=='F' or Mat[w.f][w.s]=='1' or Mat[w.f][w.s]=='0')
				d = 0;
			else
				d = 1;
			if(dist[w.f][w.s]>dist[u.f][u.s]+d){
				dist[w.f][w.s]=dist[u.f][u.s]+d;
				if(!d) dq.push_front(w);
				else dq.push_back(w);
			}
		}
	}
	return dist[fim.f][fim.s];
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> Mat[i];
		for(int j=0;j<m;j++){
			if(Mat[i][j]=='I')
				ini={i,j};	
			else if(Mat[i][j]=='F')
				fim={i,j};	
		}
	}
	int ans = bfs();
	if(ans==inf)
		cout << "-1\n";
	else
		cout << ans << '\n';
#ifdef LOCAL_DEFINE
	cerr << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
