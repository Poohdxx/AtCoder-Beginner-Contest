#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct Comp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		if (a.first - a.second <= 0 && b.first - b.second <= 0) {
			return a.first < b.first;
		}
		else if (a.first - a.second > 0 && b.first - b.second > 0) {
			return a.second > b.second;
		}
		return a.first - a.second <= 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int left = 0, right = 0;
	vector<pair<int, int>> mid;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		int a = 0;
		int c = 0;
		for (int j = 0; j < t.size(); j++) {
			if (t[j] == '(') {
				c++;
			}
			else {
				c--;
				if (c < 0) {
					a++;
					c = 0;
				}
			}
		}
		if (a == 0) {
			left += c;
		}
		else if (c == 0) {
			right += a;
		}
		else {
			mid.push_back({ a, c });
		}
	}

	sort(mid.begin(), mid.end(), Comp());

	int cur = left;
	for (int i = 0; i < mid.size(); i++) {
		cur -= mid[i].first;
		if (cur < 0) {
			cout << "No" << endl;
			return 0;
		}
		cur += mid[i].second;
	}

	if (cur != right) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}

