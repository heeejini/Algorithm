#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int MAX_NODE = 801;
vector<pii> adj[MAX_NODE]; // 인접 리스트 

int v;

// 다익스트라 함수 
vector<int> dijkstra(int start_node) {
    vector<int> dist(v + 1, 1e9);
    dist[start_node] = 0; // 시작 노드 0으로 초기화
    
    priority_queue<pii> pq;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int dst = -pq.top().first;
        pq.pop();
        
        if (dst > dist[cur]) continue; // 이미 최단 경로이면 continue

        for (pii e : adj[cur]) {
            int next = e.first;
            int weight = e.second;

            if (dist[next] > dist[cur] + weight) {
                dist[next] = dist[cur] + weight;
                pq.push({-dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int _from, _to, _weight;
        cin >> _from >> _to >> _weight;
        adj[_from].push_back({_to, _weight});
        adj[_to].push_back({_from, _weight});
    }

    pii p;
    cin >> p.first >> p.second;
    
    vector<int> result = dijkstra(1); // 1 에서 다른 지점의 최단 경로
    vector<int> first = dijkstra(p.first); // p.first에서 다른 지점까지의 최단 경로
    vector<int> second = dijkstra(p.second); //p.second에서 다른 지점까지의 최단 경로 
    
    // 1-> N까지 가는 경우 
    // 1. 1-> p.first -> p.second -> N
    // 2. 1-> p.second -> p.first -> N

    // (ll)이거때문에 계속 틀렸음 -> result, first, second 를 int로 저장했으니 더해줄 때 ll로 형변환 후 더해주기 
    ll result1 = (ll)result[p.first] + first[p.second] + second[v];
    ll result2 = (ll)result[p.second] + second[p.first] + first[v];

    ll fin = min(result1, result2);

    if(fin >= 1e9) cout << "-1\n";
    else cout << fin << "\n";

    return 0;
}
