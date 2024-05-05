#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int max_width = 0; // 최대 그림 넓이
    int cnt = 0; // 그림의 개수

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            cnt++;
            vis[i][j] = 1;
            queue<pii> Q;
            Q.push({i, j});
            int area = 0; // 이 그림의 넓이를 계산

            while (!Q.empty()) {
                area++;
                pii current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = current.X + dx[dir];
                    int ny = current.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            max_width = max(max_width, area);
        }
    }

    cout << cnt << "\n" << max_width << "\n";
}
