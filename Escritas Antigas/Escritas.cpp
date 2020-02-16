#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
int arr[MAXN];
string text,p;

void build(){
	int i=0,j=1;
	while(j<p.size()){
		if(p[i]==p[j])
			arr[j]= ++i;
		else{
			i=0;
			if(p[i]==p[j])
				arr[j]=++i;
		}
		j++;
	}
}
int s;
int matching(){
	int i=0,j=0,out=-1;
	while(j<(int)text.size()){
		if(p[i]==text[j])i++,j++;
		else if(i)i=arr[i-1];
		else j++;
		if(i==p.size()){
			out=max(j-1,out);
			i=0;
		}
	}
	return out;
}

int main(){
	int n, m;
	cin >> n >> m;
	cin >> text >> p;
	if(m>n)
		return cout << "Impossivel\n",0;
	s = text.size();
	text=text+text;
	build();
	int ans = matching();
	if(ans==-1)
		cout << "Impossivel\n";
	else{
		string out="";		
		for(int i=ans;s--;i--)
			out+=text[i];
		reverse(out.begin(),out.end());
		cout << out << '\n';
	}
}

