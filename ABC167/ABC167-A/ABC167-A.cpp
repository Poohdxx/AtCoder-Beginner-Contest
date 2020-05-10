#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
