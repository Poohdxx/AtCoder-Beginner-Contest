#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> G;
vector<int> node;
vector<int> vis;

void dfs(int cur, vector<int>& dp, vector<int>& res) {
	res[cur] = dp.size();
	for (auto next : G[cur]) {
		if (vis[next] == 0) {
			vis[next] = 1;
			int index = lower_bound(dp.begin(), dp.end(), node[next]) - dp.begin();
			if (index == dp.size()) {
				dp.push_back(node[next]);
				dfs(next, dp, res);
				dp.pop_back();
			}
			else
			{
				int temp = dp[index];
				dp[index] = node[next];
				dfs(next, dp, res);
				dp[index] = temp;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	node = vector<int>(n);
	G = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) {
		cin >> node[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		G[v - 1].push_back(u - 1);
		G[u - 1].push_back(v - 1);
	}

	vis = vector<int>(n, 0);
	vector<int> res(n, 0);
	vector<int> dp;
	dp.push_back(node[0]);
	vis[0] = 1;
	dfs(0, dp, res);
	for (auto i : res) {
		cout << i << endl;
	}
	return 0;
}
