#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int sum=0;
    vector<int> small_people; 
    int num;

    for (int i = 0; i < 9; i++) {
        cin >> num;
        small_people.push_back(num); 
        sum += num;
    }

    sort(small_people.begin(), small_people.end());
    for(int i = 0; i < small_people.size(); i++){
        for(int j = i + 1; j < small_people.size(); j++){
            if(sum - (small_people[i] + small_people[j]) == 100){
                // 먼저 j 삭제, i 삭제 순으로 변경
                small_people.erase(small_people.begin() + j); // 먼저 j 삭제
                small_people.erase(small_people.begin() + i); // 다음 i 삭제
                goto END; // 모든 루프를 탈출 -> goto : 특정 위치로 직접 이동 
            }
        }
    }
    END:

    for(const auto &sp : small_people){
        cout << sp << "\n";
    }

    return 0;
}
