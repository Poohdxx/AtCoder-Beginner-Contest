#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	cout << min(a, k) - max(0, k - a - b) << endl;
	return 0;
}
