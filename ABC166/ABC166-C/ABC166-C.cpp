#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	vector<int> h(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		h[a - 1] = max(h[a - 1], v[b - 1]);
		h[b - 1] = max(h[b - 1], v[a - 1]);
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += h[i] < v[i];
	}
	cout << res << endl;
	return 0;
}
