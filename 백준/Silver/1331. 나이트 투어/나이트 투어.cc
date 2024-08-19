#include <iostream>
#include <vector>
#include <string>

using namespace std;

int map[6][6];
int drc[8][2] = {{2,-1}, {2,1}, {-2,-1}, {-2,1}, {1,-2}, {-1,-2}, {1,2}, {-1,2}};
string result = "Valid";

void move(int row, int col, int num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> firstLocation(2);
    
    for(int i = 1; i <= 36; i++) {
        string cmd;
        cin >> cmd;
        int row = cmd[1] - '0' - 1;
        int col = cmd[0] - 'A';

        if(map[row][col] != 0) {
            result = "Invalid";
            break;
        }
        map[row][col] = i;

        // 1번 위치 저장
        if(i == 1) {
            firstLocation[0] = row;
            firstLocation[1] = col;
        }
    }

    if(result == "Valid") {
        move(firstLocation[0], firstLocation[1], 1);
    }

    cout << result << endl;

    return 0;
}

void move(int row, int col, int num) {
    for(int d = 0; d < 8; d++) {
        int nextR = row + drc[d][0];
        int nextC = col + drc[d][1];

        if(nextR < 0 || nextR >= 6 || nextC < 0 || nextC >= 6) continue;

        if(num == 36 && map[nextR][nextC] == 1) return;

        else if(map[nextR][nextC] == num + 1) {
            move(nextR, nextC, num + 1);
            return;
        }
    }

    result = "Invalid";
}
