#include<bits/stdc++.h>
using namespace std;


int phi[1000002],prime[1000002];
void crivo(){
	prime[1]=1;
	for(int i=2;i<1000001;i++)
		if(!prime[i])
			for(int j=i;j<1000001;j+=i)
				prime[j]=i,phi[j]-=(phi[j]/i);
}
int main(){
	for(int i=1;i<1000001;i++)
		phi[i]=i;
	crivo();
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << n-phi[n] << '\n';
	}
		
#ifdef LOCAL_DEFINE
	cerr << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

