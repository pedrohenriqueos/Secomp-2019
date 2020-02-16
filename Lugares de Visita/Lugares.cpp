#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if(a<(b+c) and abs(b-c)<a and b<(a+c) and abs(a-c)<b and c<(b+a) and abs(b-a)<c)
		cout << "Sim\n";
	else
		cout << "Nao\n";
}

