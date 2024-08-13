#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<string> img;

void solve(int n1, int n2) {
    int min_row = n1; // 행에서 최소 반복 배율
    int min_col = n2; // 열에서 최소 반복 배율
    
    int row_cnt = 1; // 현재 반복 중인 행의 개수
    int col_cnt = 1; // 현재 반복 중인 열의 개수

    // 행 단위로 비교하여 최소 배율 찾기
    for (int i = 1; i < n1; i++) {
        if (img[i] == img[i - 1]) {
            row_cnt++;
        } else {
            min_row = min(min_row, row_cnt);
            row_cnt = 1; // 새로운 행이 시작되면 초기화
        }
    }
    min_row = min(min_row, row_cnt); // 마지막 반복 그룹 고려

    // 열 단위로 비교하여 최소 배율 찾기
    for (int j = 1; j < n2; j++) {
        bool is_same = true;
        for (int i = 0; i < n1; i++) {
            if (img[i][j] != img[i][j - 1]) {
                is_same = false;
                break;
            }
        }
        if (is_same) {
            col_cnt++;
        } else {
            min_col = min(min_col, col_cnt);
            col_cnt = 1; // 새로운 열이 시작되면 초기화
        }
    }
    min_col = min(min_col, col_cnt); // 마지막 반복 그룹 고려

    // 결과 출력
    cout << n1 / min_row << " " << n2 / min_col << endl;

    for (int i = 0; i < n1; i += min_row) {
        for (int j = 0; j < n2; j += min_col) {
            cout << img[i][j];
        }
        cout << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n1, n2;
    cin >> n1 >> n2; 
    
    img.resize(n1);

    // 이미지 입력
    for(int i = 0; i < n1; i++) {
        cin >> img[i];
    }

    solve(n1, n2);
    
    return 0;
}
