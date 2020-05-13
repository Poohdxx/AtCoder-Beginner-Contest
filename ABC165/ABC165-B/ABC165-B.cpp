#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	ll x;
	cin >> x;
	ll s = 100;
	int res = 0;
	while (s < x) {
		s += s / 100;
		res++;
	}
	cout << res << endl;
	return 0;
}
