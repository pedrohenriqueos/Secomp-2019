#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ii pair<int,int>

vector<pair<int,int>> G[100020];
vector<int> visto;
int cor[100002];
int n,m;
bool check(int time){
	memset(cor,0,sizeof cor);
	for(int val=1;val<=n;val++)
		if(!cor[val] and visto[val]<=time and visto[val]!=-1){
			queue<int> q;
			cor[val]=1;
			q.push(val);
			while(!q.empty()){
				int u = q.front();
				//cout << u << " " << '\n';
				q.pop();
				for(auto w:G[u])
					if(w.s<=time){
						if(!cor[w.f]){
							cor[w.f] = 3-cor[u];
							q.push(w.f);
						}else if(cor[w.f]==cor[u])
							return false;
					}
			}
		}
	return true;
}
int main(){
	scanf("%d %d",&n,&m);
	int tempo = 0,tam=m;
	visto = vector<int> (n+1,-1);
	while(m--){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back({v,tempo});
		G[v].push_back({u,tempo});
		if(visto[u]==-1) visto[u]=tempo;
		if(visto[v]==-1) visto[v]=tempo;
		tempo++;
	}
	int l = 0,r = tempo;
	while(r-l>1){
		int mid = l+ (r-l)/2;
		if(check(mid)){
			l=mid;
		}else
			r=mid;
	}
	for(int i=0;i<=l;i++)
		puts("Sim");
	for(int i=r;i<tam;i++)
		puts("Nao");
		
#ifdef LOCAL_DEFINE
	cerr << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

