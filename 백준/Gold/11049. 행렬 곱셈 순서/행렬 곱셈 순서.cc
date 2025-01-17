#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
#pragma warning(disable:4996)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> s(n);
	vector <int> e(n);
	int idx;

	for (idx = 0; idx < n; idx++) {
		cin >> s[idx] >> e[idx];
	}
	vector <vector <int>> m(503, vector <int>(503, 0));
	for (int i = 0; i < n; i++) {
		m[i][i] = 0;
	}

	int j;
	int res;
	for (int len = 1; len < n; len++) {
		for (int i = 0; i < n; i++) {
			int j = i + len;
			if (j >= n) break;
			int res = INF;
			for (int k = i; k < j; k++) {
				res = min(res, m[i][k] + m[k + 1][j] + s[i] * e[k] * e[j]);
			}
			m[i][j] = res;
		}
	}
	cout << m[0][n - 1];

	return 0;
}