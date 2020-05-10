#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	long long k;
	cin >> n >> k;
	vector<int> a(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
	}

	vector<int> index(n + 1, -1);
	index[1] = 0;
	int cur = 1;
	int rest = 0;
	for (int i = 1; i <= k; i++) {
		cur = a[cur];
		if (index[cur] == -1) {
			index[cur] = i;
		}
		else {
			int loop = i - index[cur];
			rest = (k - index[cur]) % loop;
			break;
		}
	}

	int res = cur;
	for (int i = 0; i < rest; i++) {
		res = a[res];
	}
	cout << res << endl;
	return 0;
}

