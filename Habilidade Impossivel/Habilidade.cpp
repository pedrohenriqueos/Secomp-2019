#include <bits/stdc++.h>

using namespace std;

typedef complex<double> ftype;
const double pi = acos(-1);
const int maxn = 1 << 22;
ftype w[maxn];

void init()
{
	for(int i = 0; i < maxn; i++)
		w[i] = polar(1., 2 * pi / maxn * i);
}

template<typename T>
void fft(T *in, ftype *out, int n, int k = 1)
{
	if(n == 1)
	{
		*out = *in;
		return;
	}
	int t = maxn / n;
	n >>= 1;
	fft(in, out, n, 2 * k);
	fft(in + k, out + n, n, 2 * k);
	for(int i = 0, j = 0; i < n; i++, j += t)
	{
		ftype t = w[j] * out[i + n];
		out[i + n] = out[i] - t;
		out[i] += t;
	}
}

vector<ftype> evaluate(vector<int> p)
{
	while(__builtin_popcount(p.size()) != 1)
		p.push_back(0);
	vector<ftype> res(p.size());
	fft(p.data(), res.data(), p.size());
	return res;
}

vector<int> interpolate(vector<ftype> p)
{
	int n = p.size();
	vector<ftype> inv(n);
	fft(p.data(), inv.data(), n);
	vector<int> res(n);
	for(int i = 0; i < n; i++)
		res[i] = round(real(inv[i]) / n);
	reverse(begin(res) + 1, end(res));
	return res;
}

void align(vector<int> &a, vector<int> &b)
{
	int n = a.size() + b.size() - 1;
	while(a.size() < n)
		a.push_back(0);
	while(b.size() < n)
		b.push_back(0);
}

vector<int> poly_multiply(vector<int> a, vector<int> b)
{
	align(a, b);
	auto A = evaluate(a);
	auto B = evaluate(b);
	for(int i = 0; i < A.size(); i++)
		A[i] *= B[i];
	return interpolate(A);
}

int main()
{
	init();

	int n, m, q;

	vector<int> A, B, Q; 

	cin >> n >> m >> q;

	A.resize(n);
	B.resize(m);
	Q.resize(q);

	int maxia = 0, maxib = 0;
	for(int &v : A) scanf(" %d", &v), maxia = max(maxia, v);
	for(int &v : B) scanf(" %d", &v), maxib = max(maxib, v);
	for(int &v : Q) scanf(" %d", &v);

	vector<int> a(maxia + 2, 0), b(maxib + 2, 0);

	for(int &v : A)
		a[v]++;
	for(int &v : B)
		b[v]++;

	//for(int &v : a) cout << v << ' '; puts("");
	//for(int &v : b) cout << v << ' '; puts("");

	auto C = poly_multiply(a, b);
	int k = int(a.size() + b.size()) - 1;    
	//for(int i = 0; i < k; i++)
	//    cout << C[i] << ' ';
	//puts("");

	vector<bool> cnt(k + 10, false);

	for(int i = 0; i < k; i++)
		if(C[i] > 0)
			cnt[i] = true;

	for(int &v : Q)
		if(v > k) puts("NAO");
		else puts(cnt[v]? "SIM" : "NAO");

	/*
	3 3 5
	1 2 3
	4 5 6
	9 10 4 6 8
	YES
	NO
	NO
	YES
	YES
	*/

	return 0;
}


