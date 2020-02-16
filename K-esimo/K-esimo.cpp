	#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;

int normalize(int x)
{
	x = x % MOD;
	if(x < 0) x += MOD;
	return x;
}

int add(int a, int b)
{
	return normalize(normalize(a) + normalize(b));
}

int prod(int a, int b)
{
	return normalize(normalize(a) * normalize(b));
}

int sub(int a, int b)
{
	return normalize(normalize(a) - normalize(b));
}

int expMod(int x, int e)
{
	int ans = 1;
	while(e > 0)
	{
		if(e & 1LL) ans = prod(ans, x), e--;
		else x = prod(x, x), e /= 2;
	}
	return normalize(ans);
}

int32_t main()
{
	int t, x, y, n, a;
	
	scanf(" %lld", &t);
	while(t--)
	{
		scanf(" %lld %lld %lld %lld", &a, &x, &y, &n);
		printf("%lld\n", prod(prod(expMod(a, 2 * n - 1), (x % MOD)), (y % MOD)));
	}

	return 0;
}

