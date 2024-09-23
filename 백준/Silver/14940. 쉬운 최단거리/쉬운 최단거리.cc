#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> dist; // 거리 계산해서 저장할 2차원 벡터 
pii loc;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

void bfs() {
    queue<pii> Q;
    dist[loc.first][loc.second] = 0; // 시작 지점은 0 
    Q.push(loc);

    while (!Q.empty()) {
        pii cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

            // 갈 수 있는 땅이며 아직 방문하지 않았다면
            if (board[nx][ny] == 1 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 0) {
                cout << "0 "; 
            } else if (dist[i][j] == -1) {
                cout << "-1 "; 
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m; 
    board.resize(n + 1, vector<int>(m + 1));
    dist.resize(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                loc = {i, j}; 
            }
        }
    }
    
    bfs();
    return 0;
}
