#include <iostream>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int arr[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int _from, _to, _weight;

    // 초기화
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = INF;
            }
        }
    }

    // 간선 정보 입력
    for(int i = 1; i <= m; i++){
        cin >> _from >> _to >> _weight;
        // 더 작은 비용으로 업데이트
        if(arr[_from][_to] > _weight) {
            arr[_from][_to] = _weight;
        }
    }

    // Floyd-Warshall 알고리즘
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] != INF && arr[k][j] != INF && arr[i][k] + arr[k][j] < arr[i][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    // 결과 출력
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == INF)
                cout << "0 ";
            else
                cout << arr[i][j] << " ";
        }
        cout << "\n";
        
    }

    return 0;
}
