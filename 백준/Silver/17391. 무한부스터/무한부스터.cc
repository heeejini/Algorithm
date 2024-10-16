#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first
#define y second 
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> dist;
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void solve() {
    queue<pii> Q;
    Q.push({1, 1});
    dist[1][1] = 0; // 시작 지점은  dist 0 으로 
    int cnt = 0;

    while (!Q.empty()) {
        pii cur = Q.front(); Q.pop();

        for (int i = 0; i < 2; i++) {
            int item = arr[cur.x][cur.y];
            for (int j = 1; j <= item; j++) {
                int nx = cur.x + (j * dx[i]);
                int ny = cur.y + (j * dy[i]);

                if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;

                if (dist[nx][ny] == -1) {
                    Q.push({nx, ny});
                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                }

                if (nx == n && ny == m) {
                    cout << dist[nx][ny] ;
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    arr.resize(n + 1, vector<int>(m + 1));
    dist.resize(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    solve();

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
