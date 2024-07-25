#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define INF 1e9
using namespace std;

struct Edge {
    int from, to, weight;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m; // 도시의 갯수(n), 버스 노선의 갯수 (m)

    vector<Edge> edges;
    vector<ll> distance(n + 1, INF);
    
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
    }
    
    distance[1] = 0; // 1번 도시에서 출발

    // 벨만-포드 알고리즘
    for (int i = 1; i <= n - 1; i++) {
        for (const auto& edge : edges) {
            if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
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

    if (cycle) {
        cout << -1 << "\n"; // 만약에 음의 사이클이 존재하면 -1 출력해주기 
    } else {
        for (int i = 2; i <= n; i++) {
            if (distance[i] == INF) {
                cout << -1 << "\n";
            } else {
                cout << distance[i] <<"\n";
            }
        }
    }

    return 0;
}
