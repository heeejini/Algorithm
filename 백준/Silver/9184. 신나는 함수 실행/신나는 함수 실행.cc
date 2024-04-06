#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
//신나는 함수 실행
int dp[50][50][50];

int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return solve(20, 20, 20);
  
    if (dp[a][b][c] != -1) return dp[a][b][c];

    if (a < b && b < c) {
        dp[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
    } else {
        dp[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
    }

    return dp[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(dp, -1, sizeof(dp)); // dp 배열을 -1로 초기화

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
    }

    return 0;
}
