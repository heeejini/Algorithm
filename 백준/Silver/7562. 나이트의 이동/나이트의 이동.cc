#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int board[501][501] = {0,};
int vis[501][501] = {0,};
pii start, to;
int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};
int l;

void bfs() {
    queue<pii> Q;
    Q.push(start);
    vis[start.first][start.second] = 1;

    while (!Q.empty()) {
        pii cur = Q.front(); Q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if (nx == to.first && ny == to.second) {
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                return;
            }

            if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
            if (vis[nx][ny] == 0) {
                Q.push({nx, ny});
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t_case; // 테스트 케이스 

    cin >> t_case;

    while (t_case--) {
        cin >> l;
        cin >> start.first >> start.second;
        cin >> to.first >> to.second;

        memset(vis, 0, sizeof(vis)); 

        if (start == to) {
            cout << 0 << "\n";
        } else {
            bfs();
            cout << vis[to.first][to.second] - 1 << "\n";
        }
    }

    return 0;
}
