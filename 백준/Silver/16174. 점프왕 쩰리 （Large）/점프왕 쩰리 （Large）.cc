#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};
int n;
vector<vector<int>> arr;
vector<vector<int>> dist;

void solve() {
    queue<pii> Q;
    Q.push({1, 1});
    dist[1][1] = 0; // 시작 지점은 0으로 표시 

    while (!Q.empty()) {
        pii cur = Q.front();
        Q.pop();

        for (int i = 0; i < 2; i++) {
            int nx = cur.first + (dx[i] * arr[cur.first][cur.second]);
            int ny = cur.second + (dy[i] * arr[cur.first][cur.second]);

            // 범위 밖이면 넘어감
            if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;

            if (dist[nx][ny] == -1) {
                Q.push({nx, ny});
                dist[nx][ny] = 0;
            }

            // 목표 지점에 도달하면 종료
            if (nx == n && ny == n) {
                cout << "HaruHaru" << endl;
                return;
            }
        }
    }
    cout << "Hing";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    arr.resize(n + 1, vector<int>(n + 1));
    dist.resize(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    solve();

    return 0;
}
