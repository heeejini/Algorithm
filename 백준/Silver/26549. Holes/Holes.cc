#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long

using namespace std;

// 전역 변수
int board[51][51];
bool vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 전역으로 a, b 선언
int a, b;
int cnt = 0, star = 0; // 연결 요소 개수 등을 세는 변수

// BFS 함수: 연결 요소 개수 계산 및 출력
void bfs() {
    cnt = 0; // 연결 요소 카운팅 초기화

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            // 이미 방문했거나(board[i][j] == 0) 벽이면 건너뛰기
            if (vis[i][j] || board[i][j] == 0) continue;

            // 새로운 구역 발견 -> cnt 하나 증가
            cnt++;
            vis[i][j] = true;
            queue<pii> Q;
            Q.push({i, j});

            // BFS로 연결된 모든 칸 방문 처리
            while (!Q.empty()) {
                pii cur = Q.front();
                Q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    // 범위 체크
                    if (nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
                    // 이미 방문했거나, 벽이면 스킵
                    if (vis[nx][ny] || board[nx][ny] == 0) continue;

                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    }

    // 단수/복수 조건에 따른 출력 문자열 처리
    string sec = (cnt == 1) ? " section, " : " sections, ";
    string spa = (star == 1) ? " space" : " spaces";

    // 결과 출력
    cout << cnt << sec << star << spa << "\n";
}

// 맵을 숫자로 변환하는 함수:
void convert_map(const vector<string> &map) {
    star = 0; // 비어 있는 공간(길)의 수 초기화
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (map[i][j] == '#') {
                board[i][j] = 0; // 벽
            } else {
                board[i][j] = 1; // 길
                star++;          // 길 개수 증가
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> a >> b;

        // 문자열로 맵을 입력받아 저장
        vector<string> mp(a);
        for (int i = 0; i < a; i++) {
            cin >> mp[i];
        }

        // board, vis 초기화
        memset(board, 0, sizeof(board));
        memset(vis, false, sizeof(vis));

        // 문자 맵 -> 숫자 맵(0, 1) 변환
        convert_map(mp);

        // BFS로 연결 요소(혹은 원하는 로직) 수행
        bfs();
    }

    return 0;
}
