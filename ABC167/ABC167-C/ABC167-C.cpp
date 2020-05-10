#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, x;
vector<int> c;
vector<vector<int>> a;

bool check(const vector<int>& s) {
	for (int i = 0; i < m; i++) {
		if (s[i] < x) return false;
	}
	return true;
}

void dfs(int i, int v, vector<int> s, int& res) {
	if (i == n) {
		if (check(s)) {
			res = min(res, v);
		}
		return;
	}
	dfs(i + 1, v, s, res);
	for (int j = 0; j < m; j++) {
		s[j] += a[i][j];
	}
	dfs(i + 1, v + c[i], s, res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> x;
	c = vector<int>(n, 0);
	a = vector<vector<int>>(n, vector<int>(m, 0));

	vector<int> X(m, 0);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			X[j] += a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		if (X[i] < x) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> s(m, 0);
	int res = INT_MAX;
	dfs(0, 0, s, res);
	cout << res << endl;
	return 0;
}

