#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define MAX_NODE 5000
using namespace std;
// 6번 간선 이어나가기2 -> 다익스트라 (최단경로구하기)
vector<pii> adj[MAX_NODE]; // 
vector<int> dist(MAX_NODE, 1e9); 

void dijkstra(int start_node, int end_node){
    priority_queue<pii> pq;
    dist[start_node]=0;
    pq.push({0,start_node});

    while(!pq.empty()){
        int dst = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dst > dist[cur]) continue;

        if(cur == end_node) { // 시작 노드에서 끝 노드에 도착했을 때 가중치 출력하고 종료 
            cout << dist[cur] << endl;
            return;
        }

        for(pii e : adj[cur]){
            int next = e.first;
            int cost = e.second;

            if(dist[next]>dist[cur] + cost ){
                dist[next] = dist[cur] + cost;
                pq.push({-dist[next], next});
            }

        }
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int start, end;
    cin >> start >> end;
    dijkstra(start, end);
    
    return 0;
}