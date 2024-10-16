#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first 
#define y second
using namespace std;
int n, m;
vector<vector<int>> arr;
vector<vector<int>> dp;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    arr.resize(n+1, vector<int>(n+1,0));
    dp.resize(n+1, vector<int> (n+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i-1][j]  + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    for(int i=0; i<m; i++){
        int a,b,c,d;
        cin >> a>>b>>c>>d;
        // a, b, c,d
        int result = dp[c][d] - dp[a-1][d] -dp[c][b-1] + dp[a-1][b-1]; 
        cout << result << "\n";
    }
    return 0;
}