#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int k, a, b;
	cin >> k >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i % k == 0) {
			cout << "OK" << endl;
			return 0;
		}
	}
	cout << "NG" << endl;
	return 0;
}
