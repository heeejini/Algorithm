#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 단지 번호 붙이기
int board[26][26] = {0,};
int vis[26][26] = {0,};
int n;
int cnt = 0; // 단지 수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    
    vector<int> house_size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            cnt++; // bfs 시작 지점이 몇개인지 
            vis[i][j] = 1;
            queue<pii> Q;
            Q.push({i, j});
            int area = 0;

            while (!Q.empty()) {
                pii cur = Q.front(); Q.pop();
                area++; // 시작된 지점으로부터 연결된 노드가 몇개 있는 지 

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] == 0) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            house_size.push_back(area);
        }
    }
    cout << cnt << "\n";

    sort(house_size.begin(), house_size.end());

    for (int i = 0; i < house_size.size(); i++) {
        cout << house_size[i] << "\n";
    }
    return 0;
}
