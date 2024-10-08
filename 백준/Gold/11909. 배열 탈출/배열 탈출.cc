#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ppi pair<int, pii> // 비용, 좌표 저장

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> dist;
int dx[2] = {1, 0}; // 오른쪽, 아래로만 이동
int dy[2] = {0, 1};

int dijkstra() {
    dist[0][0] = 0; // 시작점의 초기 비용은 0
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq; // 최소 힙 사용
    pq.push({0, {0, 0}}); // {비용, {x, y}}

    while (!pq.empty()) {
        int dst = pq.top().first;
        pii cur = pq.top().second;
        pq.pop();

        // 이미 더 적은 비용으로 처리된 경우 패스
        if (dst > dist[cur.first][cur.second]) continue;

        // 두 방향(오른쪽, 아래)으로 이동
        for (int i = 0; i < 2; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            // 버튼을 눌러 이동할 수 있는 최소 비용 계산
            int new_cost = max(0, board[nx][ny] - board[cur.first][cur.second] + 1);

            // 기존의 dist 값보다 더 적은 비용으로 갈 수 있으면 갱신
            if (dist[nx][ny] > dist[cur.first][cur.second] + new_cost) {
                dist[nx][ny] = dist[cur.first][cur.second] + new_cost;
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }
    return dist[n-1][n-1]; // 최종 최소 비용 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    board.resize(n, vector<int>(n));
    dist.resize(n, vector<int>(n, 1e9)); // 초기 값을 무한대로 설정
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int result = dijkstra(); // 최소 비용 계산
    cout << result; // 결과 출력

    return 0;
}
