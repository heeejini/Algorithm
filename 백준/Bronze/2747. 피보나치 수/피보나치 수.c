#include <stdio.h>
#pragma warning(disable:4996)

double dp[1][1000];

int main() {
	int N;
	scanf("%d",&N);
	dp[0][0] = 1;
	dp[0][1] = 1;

	for (int i = 2; i < N; i++) {
		dp[0][i] = dp[0][i-2] + dp[0][i-1];
	}
	printf("%.0lf ", dp[0][N-1]);
	return 0;
}