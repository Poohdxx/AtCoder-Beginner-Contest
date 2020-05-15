#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int i = 1, j = n;
	bool ch = false;
	for (int k = 0; k < m; k++) {
		int a = i + n - j;
		int b = j - i;
		if (ch == false && (a + b) % 2 == 0 && a >= b) {
			j--;
			ch = true;
		}
		cout << i++ << " " << j-- << endl;
	}
	return 0;
}