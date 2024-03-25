#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tot_case;
    cin >> tot_case;

    cin.ignore();

    for(int i=0; i<tot_case; i++){
        int num ; cin >> num;
        cin.ignore();

        map<int, int> deleted;
        for(int j=0; j<num; j++){
            char c;
            int n;
            cin >> c>> n;

            if(c=='I') deleted[n]++; // 만약에 input이면 value값으 ㄹ ++
            else {
                 // C++ 에서 map은 key를 기준으로 정렬되어 들어감! 
                if(n == -1) { // 최소값 삭제
                    if(!deleted.empty()) { // map이 비어있지 않은 경우에만
                        auto it = deleted.begin(); // 가장 작은 거 
                        it->second--; // 지워졌음을 표시 
                        if(it->second == 0) {
                            deleted.erase(it); // 개수가 0이 되면 요소 삭제
                        }
                    }
                }
                else if(n== 1 ){
                    //최댓값 삭제 
                    if(!deleted.empty()){
                        auto it = --deleted.end();
                        it->second--;
                        if(it->second == 0) {
                            deleted.erase(it); // 개수가 0이 되면 요소 삭제
                        }
                    }
                }
            }
        }
        if(!deleted.empty()) {
             auto minIt = deleted.begin(); // 최소값
            auto maxIt = --deleted.end(); // 최대값

            // 최소값과 최대값 출력
            cout << maxIt->first << ' ' << minIt->first << '\n';
        } else {
                cout << "EMPTY" << '\n';
        }

    }

    return 0;
}