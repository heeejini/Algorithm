#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int dp[1001] = { 0, };

	dp[0] = 1, dp[1] = 2, dp[2] = 4;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		for (int i = 3; i < t; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[t-1] <<endl;
	}

	return 0;
}