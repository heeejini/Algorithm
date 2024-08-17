#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> alpha(27, 0);
vector<string> road;
map<char, bool> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int row, col;
int max_len = 0; // 최대 경로 길이를 저장하는 변수

void dfs(int x, int y, int cnt) {
    // 현재 위치의 알파벳을 방문 처리
    visited[road[x][y]] = true;
    max_len = max(max_len, cnt); // 최대 경로 길이 갱신

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;

        // 다음 위치의 알파벳이 방문되지 않았다면 DFS로 탐색
        if (!visited[road[nx][ny]]) {
            dfs(nx, ny, cnt + 1);
        }
    }

    // 탐색이 끝나면 현재 위치의 알파벳을 방문 해제 (backtracking)
    visited[road[x][y]] = false;
}

void solve() {
    // 좌측 상단에서 DFS 시작
    dfs(0, 0, 1);
    cout << max_len << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    road.resize(row);

    for (int i = 0; i < row; i++) {
        cin >> road[i];
    }

    // 모든 알파벳을 false로 초기화
    for (char c = 'A'; c <= 'Z'; ++c) {
        visited[c] = false;
    }

    solve();

    return 0;
}
