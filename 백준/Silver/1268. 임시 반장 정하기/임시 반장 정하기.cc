#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int num;
    cin >> num;
    vector<vector<int>> vec(num, vector<int>(5, 0));  // 각 학생의 1~5학년 반 정보를 저장

    // 입력 받기
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < 5; j++) {  // 1학년부터 5학년까지
            cin >> vec[i][j];
        }
    }

    vector<int> student(num, 0); // 학생별로 같은 반이었던 학생 수를 저장하는 벡터

    for(int i = 0; i < num; i++){  // 각 학생을 순회
        set<int> visited;  // 이미 체크한 학생을 기록하는 집합
        for(int j = 0; j < 5; j++){  // 각 학년을 순회
            for(int k = 0; k < num; k++){  // 다른 모든 학생들과 비교
                if(i != k && vec[i][j] == vec[k][j] && visited.find(k) == visited.end()){
                    student[i]++;
                    visited.insert(k);  // 중복 체크 방지
                }
            }
        }
    }
    // 가장 많은 같은 반 학생을 가진 학생 찾기
    int max_count = -1;
    int candidate = 0;
    for (int i = 0; i < num; i++) {
        if (student[i] > max_count) {
            max_count = student[i];
            candidate = i + 1;  // 학생 번호는 1부터 시작
        }
    }

    cout << candidate << endl;  // 임시 반장 후보 출력

    return 0;
}
