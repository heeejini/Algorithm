#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int MAX_NODE = 20001; // 최대 노드 개수

vector<pii> adj[MAX_NODE]; // 인접 리스트, {목적지 노드, 비용} 형태의 벡터

vector<int> dijkstra(int start_node, int v) {
    vector<int> dist(v + 1, 1e9); // 모든 노드까지의 거리를 1e9로 초기화
    dist[start_node] = 0; // 시작 노드의 거리는 0으로 설정

    priority_queue<pii> pq; // 최대 힙, {거리, 노드} 형태의 우선순위 큐
    pq.push({0, start_node}); // 시작 노드를 큐에 추가

    while (!pq.empty()) {
        int dst = -pq.top().first; // 현재 노드까지의 거리 (음수로 저장했으므로 다시 양수로 변환)
        int cur = pq.top().second; // 현재 노드
        pq.pop();

        // 이미 최단 경로가 결정된 경우 패스
        if (dst > dist[cur]) continue;

        // 현재 노드와 인접한 모든 노드 확인
        for (pii e : adj[cur]) {
            int next = e.first; // 다음 노드
            int cost = e.second; // 현재 노드에서 다음 노드까지의 비용

            // 더 짧은 경로를 발견한 경우
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost; // 거리 갱신
                pq.push({-dist[next], next}); // 우선순위 큐에 추가 (최소 힙을 사용하기 위해 음수로 저장)
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, start_node;
    cin >> v >> e >> start_node;

    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); 
    }

    vector<int> result = dijkstra(start_node, v); // 다익스트라 알고리즘 실행

    for (int i = 1; i <= v; i++) {
        if (result[i] != 1e9) 
            cout << result[i] << '\n';
        else 
            cout << "INF\n";
    }

    return 0;
}
