#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < k; i++) {
		int d;
		cin >> d;
		for (int j = 0; j < d; j++) {
			int t;
			cin >> t;
			v[t - 1]++;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += (v[i] == 0);
	}
	cout << res << endl;
	return 0;
}
