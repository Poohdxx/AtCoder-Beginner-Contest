#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long x;
	cin >> x;
	for (long long a = 1; a <= 120; a++) {
		long long aa = a*a*a*a*a;
		long long bb = abs(aa - x);
		int s = aa - x >= 0 ? 1 : -1;
		long long tb = pow(bb, 1.0/5.0);
		if (tb * tb * tb * tb * tb == bb) {
			cout << a << " " << s * tb << endl;
			return 0;
		}
	}
	return 0;
}