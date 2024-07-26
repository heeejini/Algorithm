#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
#define INF 1e9

struct Edge {
    int from, to, weight;
};

void solve() {
    int n, m, w; // 지점의 수, 도로의 개수, 웜홀의 개수 
    cin >> n >> m >> w;
    
    vector<Edge> edges;
    vector<ll> distance(n + 1, INF);

    // 도로 정보 입력 받기, 양방향 그래프
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
        edges.push_back({to, from, weight}); // 양방향 도로 처리
    }

    // 웜홀 정보 입력 받기, 방향 그래프
    for (int i = 0; i < w; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, -weight});
    }

    // 벨만-포드 알고리즘
    distance[1] = 0; // 시작점은 1번 노드로 가정
    for (int i = 1; i <= n - 1; i++) {
        for (const auto& edge : edges) {
            if ( distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    // 음수 사이클 체크
    bool cycle = false;
    for (const auto& edge : edges) {
        if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
            cycle = true;
            break;
        }
    }

    if (cycle == true) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        solve();
    }

    return 0;
}
