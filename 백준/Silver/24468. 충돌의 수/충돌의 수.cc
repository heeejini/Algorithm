#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, N, T;
    cin >> L >> N >> T;

    vector<int> positions(N);
    vector<int> directions(N); // 1 for 'R', -1 for 'L'

    for (int i = 0; i < N; ++i) {
        int S;
        char C;
        cin >> S >> C;
        positions[i] = S;
        directions[i] = (C == 'R' ? 1 : -1);
    }

    int collision_count = 0;

    // 시뮬레이션
    for (int t = 0; t < T; ++t) {
        // 모든 공의 위치 업데이트
        for (int i = 0; i < N; ++i) {
            positions[i] += directions[i];

            // 벽에 부딪히는 경우 방향을 바꾼다
            if (positions[i] == 0 || positions[i] == L) {
                directions[i] *= -1;
            }
        }

        // 충돌 체크
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (positions[i] == positions[j]) {
                    collision_count++;
                    swap(directions[i], directions[j]); // 방향을 서로 교환
                }
            }
        }
    }

    cout << collision_count << endl;

    return 0;
}
