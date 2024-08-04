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
    vector<vector<int>> week(num, vector<int>(5));

    for(int i=0; i<num; i++){
        for(int j=0; j<5; j++){
            cin >> week[i][j];
        }
    }

    // 5C2로 찾아주기 

    int _max = -1000;
    vector<int> result(5,0);
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            int cnt=0;

            for(int k = 0; k<num; k++){ 
                if(week[k][i] == 1 && week[k][j]==1){ // 2일 다 돼야 강의를 모두 듣는 것으로 인정 
                    cnt ++;
                }
            }

            if(_max < cnt){
                _max = cnt ;
                fill(result.begin(), result.end(),0); // 0으로 초기화해주기
                result[i] =1 ;
                result[j]=1;
            }
        }
    }

    cout << _max << "\n";
    for(const int e : result){
        cout << e << " ";
    }
    return 0;
}
