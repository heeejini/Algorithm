#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
char board[101][101]={0,};
int vis[101][101]= {0,};
int w_power=0;
int b_power=0;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int bfs(pii start, char color) {
    queue<pii> Q;
    Q.push({start.first, start.second});
    vis[start.first][start.second] = 1;

    int cnt = 0;
    while (!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == color && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'W' && !vis[i][j]) {
                int cnt = bfs({i, j}, 'W');
                w_power += (cnt * cnt);
            } else if (board[i][j] == 'B' && !vis[i][j]) {
                int cnt = bfs({i, j}, 'B');
                b_power += (cnt * cnt);
            }
        }
    }
    cout << w_power << " " << b_power << "\n";
    return 0;
}
