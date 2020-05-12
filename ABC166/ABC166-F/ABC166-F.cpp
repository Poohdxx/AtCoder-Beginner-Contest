#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<char> res;
	for (int i = 0; i < n; i++) {
		string t = v[i];
		if (t == "AB") {
			if (a == 0 && b == 0) {
				break;
			}
			if (a == 1 && b == 1 && c == 0 && i < n-1) {
				if (v[i + 1] == "AC") {
					a++;
					b--;
					res.push_back('A');
				}
				else {
					a--;
					b++;
					res.push_back('B');
				}
			}
			else if (a <= b) {
				a++;
				b--;
				res.push_back('A');
			}
			else {
				a--;
				b++;
				res.push_back('B');
			}
		}
		else if (t == "AC") {
			if (a == 0 && c == 0) {
				break;
			}
			if (a == 1 && c == 1 && b == 0 && i < n - 1) {
				if (v[i + 1] == "AB") {
					a++;
					c--;
					res.push_back('A');
				}
				else {
					a--;
					c++;
					res.push_back('C');
				}
			}
			else if (a <= c) {
				a++;
				c--;
				res.push_back('A');
			}
			else {
				a--;
				c++;
				res.push_back('C');
			}
		}
		else {
			if (b == 0 && c == 0) {
				break;
			}
			if (b == 1 && c == 1 && a == 0 && i < n - 1) {
				if (v[i + 1] == "AB") {
					b++;
					c--;
					res.push_back('B');
				}
				else {
					b--;
					c++;
					res.push_back('C');
				}
			}
			else if (b <= c) {
				b++;
				c--;
				res.push_back('B');
			}
			else {
				b--;
				c++;
				res.push_back('C');
			}
		}
	}

	if (res.size() == n) {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			cout << res[i] << endl;
		}
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
