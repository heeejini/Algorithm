#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int num;
vector<int> arr;
vector<bool> visited; // 방문 체크 배열

void bfs(int _start, int _end) {
    queue<pii> Q; // 큐에는 현재 위치와 점프 횟수를 함께 저장
    Q.push({_start - 1, 0});
    visited[_start - 1] = true;

    while (!Q.empty()) {
        int cur = Q.front().first;
        int time = Q.front().second;
        Q.pop();

        if (cur == _end - 1) {
            cout << time << "\n";
            return;
        }

        int jump = arr[cur];

        // 양수 방향(오른쪽)
        for (int next = cur + jump; next < num; next += jump) {
            if (!visited[next]) {
                visited[next] = true;
                Q.push({next, time + 1});
            }
        }

        // 음수 방향(왼쪽)
        for (int next = cur - jump; next >= 0; next -= jump) {
            if (!visited[next]) {
                visited[next] = true;
                Q.push({next, time + 1});
            }
        }
    }

    cout << -1 << endl; // 도달할 수 없는 경우
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> num;

    arr.resize(num);
    visited.resize(num, false);

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int _start, _end;
    cin >> _start >> _end;

    bfs(_start, _end);

    return 0;
}
