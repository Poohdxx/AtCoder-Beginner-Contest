#include <iostream>
typedef long long ll;

using namespace std;

ll a, b, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> a >> b >> n;
	ll res;
	if (n < b) {
		res = a * n / b;
	}
	else {
		res = a * (b - 1) / b;
	}
	cout << res << endl;
	return 0;
}
