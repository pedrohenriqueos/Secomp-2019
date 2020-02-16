#include<bits/stdc++.h>
using namespace std;

/*ideia do input:
	n,m : quantidade de elementos e quantidade de querys
	arr[i] : vetor inicial
	query:
		S : Substituir um número - (posição valor)
		C : Consultar a frequência de primos (left right)
	exemplo: (1-idexado)
		5 7
		1 2 3 4 5
		C 2 3
		S 1 7
		C 4 5
		S 3 6
		C 1 5
*/
	
const int MAXN = 100002;

/* ------ Crivo ------ */

int prime[MAXN*10];
inline void crivo(){
	prime[0]=prime[1]=1;
	for(int i=2;i<=1000000;i++)
		if(!prime[i])
			for(int j=i*2;j<=1000000;j+=i)
				prime[j]=1;
}

/* -----  Segment Tree ----- */

int arr[MAXN],tree[4*MAXN];
void build(int node,int left,int right){
	if(left==right){
		tree[node] = !prime[arr[left]];
		return ;
	}
	int mid = (left+right) >> 1;
	build((node << 1),left,mid);
	build((node << 1)+1,mid+1,right);
	tree[node]=tree[(node << 1)] + tree[(node << 1)+1];
}

int query(int node,int l,int r,int left,int right){
	if(left>r or right<l)
		return 0;
	if(left>=l and r>=right)
		return tree[node];
	int mid = (left+right) >> 1;
	return query((node << 1),l,r,left,mid) + query((node << 1)+1,l,r,mid+1,right);
}

void update(int node,int left,int right,int id,int val){
	if(left==right){
		tree[node]  = !prime[val];
		return ;
	}
	int mid = (left+right) >> 1;
	if(left<=id and id<=mid)
		update((node << 1),left,mid,id,val);
	else
		update((node << 1)+1,mid+1,right,id,val);
	tree[node] = tree[(node << 1)]+ tree[(node << 1)+1];
}

/* Main */
int main(){
	crivo();
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	build(1,0,n-1);
	while(m--){
		char c; 
		scanf(" %c",&c);
		if(c=='S'){
			int x,y;
			scanf("%d %d",&x,&y);
			x--;
			update(1,0,n-1,x,y);
		}else{
			int l,r;
			scanf("%d %d",&l,&r);
			l--,r--;
			printf("%d\n",query(1,l,r,0,n-1));
		}
	}
}
