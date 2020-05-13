#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m, q;
vector<vector<unordered_map<int, int>>> v;

void dfs(vector<int>& cur, int score, int& res) {
	if ((int)cur.size() == n) {
		res = max(res, score);
		return;
	}
	int i = cur.empty() ? 1 : cur.back();
	for (; i <= m; i++) {
		cur.push_back(i);
		int ns = score;
		for (int j = 0; j < (int)cur.size() - 1; j++) {
			ns += v[cur.size()][j + 1][i - cur[j]];
		}
		dfs(cur, ns, res);
		cur.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	v = vector<vector<unordered_map<int, int>>>(n + 1, vector<unordered_map<int, int>>(n + 1, unordered_map<int, int>()));
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[b][a][c] = d;
	}

	int res = 0;
	vector<int> cur;
	dfs(cur, 0, res);
	cout << res << endl;
	return 0;
}
