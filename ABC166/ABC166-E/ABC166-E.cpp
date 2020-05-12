#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	unordered_map<int, int> a, b;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		a[i + t]++;
		if (i - t > 0) b[i - t]++;
	}
	long long res = 0;
	for (auto& i : a) {
		int c = i.second;
		int d = b[i.first];
		res += (long long)c * (long long)d;
	}
	cout << res << endl;
	return 0;
}