#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ex_gcd(long long a, long long b, long long& x, long long& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long ans = ex_gcd(b, a % b, x, y);
	long long tmp = x;
	x = y;
	y = tmp - a / b * y;
	return ans;
}

long long mod_inverse(long long a, long long m)
{
	long long x, y;
	ex_gcd(a, m, x, y);
	return (x % m + m) % m;
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	const long long M = 998244353;
	long long res = 0;
	vector<long long> C(k + 1, 0);
	C[0] = 1;
	for (int i = 1; i <= k; i++) {
		long long vi = mod_inverse(i, M);
		C[i] = C[i - 1] * (n - i) %M * vi % M;
	}
	vector<long long> P(k + 1, 0);
	P[k] = 1;
	for (int i = 0; i < n - 1 - k; i++) {
		P[k] = (P[k] * (m - 1)) % M;
	}
	for (int i = k - 1; i >= 0; i--) {
		P[i] = (P[i + 1] * (m - 1)) % M;
	}

	for (int i = 0; i <= k; i++) {
		res = (res + C[i] * m % M * P[i] % M) % M;
	}

	cout << res << endl;
	return 0;
}

/* Fails when large input: 60522 114575 7559 
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	const int M = 998244353;
	vector<long long> dp(k + 1, 0);
	dp[0] = m;
	for (int i = 1; i < n; i++) {
		for (int j = min(i, k); j >= 0; j--) { 
			dp[j] = dp[j] * (m - 1) % M;
			if (j > 0) {
				dp[j] = (dp[j] + dp[j - 1]) % M;
			}
		}
	}
	
	long long res = 0;
	for (int i = 0; i <= k; i++) {
		res = (res + dp[i]) % M;
	}
	cout << res << endl;
	return 0;
}
*/


