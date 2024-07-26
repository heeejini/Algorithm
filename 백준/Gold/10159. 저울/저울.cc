#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int dist[101][101];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dist[i][j]=INF;
        }
    }

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1; // u > v
    }

    // Floyd-Warshall 알고리즘
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j]=1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int count = 0;
        for (int j = 1; j <= N; j++) { 
            if (i != j && dist[i][j] == INF && dist[j][i] == INF) {
                count++; // i에서 j로 가는 길 x, j에서 i로 가는 길도 x
            }
        }
        cout << count << "\n";
    }

    return 0;
}
