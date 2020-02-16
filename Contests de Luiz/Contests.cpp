#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define pi acos(-1)
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define int long long
template<class T> bool mmin(T &a,T b){return (a>b ?(a=b,true):false);};
template<class T> bool mmax(T &a,T b){return (a<b ?(a=b,true):false);};

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,q;
	cin >> n >> m >> q;
	vector<int> G[n];
	for(int i = 0;i<n;i++){
		G[i] = vector<int> (m);
		int sum=0;
		for(int j=0;j<m;j++)
			cin >> G[i][j],sum+=G[i][j];
		G[i].pb(sum);
		sort(all(G[i]));
		reverse(all(G[i]));
	}
	int ans =0;
	for(int i=0;i<n;i++)
		if(G[i][0]>0)
			ans+=G[i][0];
	cout << ans << '\n';	
	
#ifdef LOCAL_DEFINE
	cerr << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}




















