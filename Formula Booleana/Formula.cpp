// Os vertices pares indicam as proposicoes falsas
// Os vertices impares indicam as proposicoes verdadeiras
// Achar qual proposicao relativa a cada vertice, eh so dividiar vertice/2
// tamG = quantidade_proposicoes*2

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3;

int n, tamG;
vector<int> G[MAX], G_t[MAX];
stack<int> sta;
bool cor[MAX];
int componente[MAX], comp;

void preenche(int v)
{
	cor[v] = true;
	for(const int &u : G_t[v])
		if(!cor[u])
			preenche(u);
	sta.push(v);
}

void dfs(int v, int comp)
{
	componente[v] = comp;
	for(const int &u : G[v])
		if(!componente[u])
			dfs(u, comp);
}

void kosaraju()
{
	memset(cor, false, sizeof(cor));
	for(int i = 0; i < tamG; i++)
		if(!cor[i])
			preenche(i);
	memset(cor, false, sizeof(cor));
	comp = 1;
	while(!sta.empty())
	{
		int u = sta.top();
		sta.pop();
		if(componente[u]) continue;
		dfs(u, comp);
		comp++;
	}
}

// Id no grafo que representa a proposicao de número P como verdadeira.
int idTrue(int p)
{
	return (p << 1) + 1;
}

// Id no grafo que representa a proposicao de número P como falsa.
int idFalse(int p)
{
	return (p << 1);
}

bool twoSat()
{
	kosaraju();
	for(int i = 0; i < tamG; i += 2)
		if(componente[i] == componente[i + 1])
			return false;
	return true;
}

void add_edge(int x, int y)
{
	//cout << x << ' ' << y << '\n';
	int xx = abs(x) - 1, yy = abs(y) - 1;
	//cout << (x < 0 ? idTrue(xx) : idFalse(xx)) << ' ' << (y < 0 ? idFalse(yy) : idTrue(yy)) << '\n';
	//cout << (y < 0 ?  idTrue(yy) : idFalse(yy)) << ' ' << (x < 0 ? idFalse(xx) : idTrue(xx)) << '\n';
	//puts("");
	G[x < 0 ? idTrue(xx) : idFalse(xx)].push_back(y < 0 ? idFalse(yy) : idTrue(yy));
	G[y < 0 ?  idTrue(yy) : idFalse(yy)].push_back(x < 0 ? idFalse(xx) : idTrue(xx));
	
	G_t[y < 0 ? idFalse(yy) : idTrue(yy)].push_back(x < 0 ? idTrue(xx) : idFalse(xx));
	G_t[x < 0 ? idFalse(xx) : idTrue(xx)].push_back(y < 0 ?  idTrue(yy) : idFalse(yy));
}

void add(vector<int> e)//ajeitar
{
	if(e.empty()) return;
	if(e.size() == 1)
	{
		tamG += 2;
		n++;
		add_edge(e[0], n);
		add_edge(e[0], -n);
	}
	else
		add_edge(e[0], e[1]);
}

int main()
{
	cin >> n;
	cin.ignore();
	string s, a;
	getline(cin, s);
	vector<vector<int>> arr(1, vector<int>());
	int sng = 1, id = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(isdigit(s[i])) a += s[i];
		if(s[i] == '!') sng = -1;
		if(s[i] == 'v' or s[i] == '^' or i == s.size() - 1)
		{
			int x = stoi(a);
			x *= sng;
			arr[id].push_back(x);
			a = "";
			sng = 1;
		}
		if(s[i] == '^')
		{
			id++; 
			arr.push_back(vector<int>());
		}
	}
	tamG = 2 * n;
	for(int i = 0; i < arr.size(); i++)
		add(arr[i]);
	cout << (twoSat() ? "satisfativel" : "insatisfativel") << '\n';

	return 0;
}

