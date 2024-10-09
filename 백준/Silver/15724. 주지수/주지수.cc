#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first 
#define y second
using namespace std;

int n,m, k, cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int> (m+1));
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    // 누적 합 배열 계산
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
            dp[i][j] = board[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    cin >> k; // 직사각형 범위 수
    int a, b, c, d;
    
    // 직사각형 범위에 대한 구간 합 계산
    for(int i=0; i<k; i++){
        cin >> a >> b >> c >> d;
        int result = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1];
        cout << result << "\n";
    }

    return 0;
}
