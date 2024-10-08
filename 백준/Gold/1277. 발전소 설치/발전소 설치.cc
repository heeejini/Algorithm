#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define dpii pair<double, double> 
#define node pair<int, double> // 좌표, 거리 저장 하는 pair 선언
using namespace std;

vector<node> adj[1001];
int n, w; // n은 발전소의 수, w는 현재 남아있는 전선의 수 
double m; // 제한 길이

// 유클리드 거리
double euclidean_distance(dpii a, dpii b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

vector<double> dijkstra(int start_node) {
    vector<double> dist(n, 1e9);
    dist[start_node] = 0;

    priority_queue<node, vector<node>, greater<node>> pq; // 최소 힙
    pq.push({0, start_node}); 

    while(!pq.empty()) {
        double dst = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dst > dist[cur]) continue; // 이미 최단 경로 일 때

        for(node n : adj[cur]) {
            int next = n.first;
            double cost = n.second;

            if(dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> w >> m;
    
    vector<dpii> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second; // 발전소의 위치 저장
    }

    int a, b;
    for(int i = 0; i < w; i++) {
        cin >> a >> b;
        a--; b--; 
        adj[a].push_back({b, 0});
        adj[b].push_back({a, 0});
    }

    double dist;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                dist = euclidean_distance(points[i], points[j]);

                if(dist <= m) {
                    adj[i].push_back({j, dist}); 
                    adj[j].push_back({i, dist}); 
                }
            }
        }
    }

    vector<double> result = dijkstra(0);
    cout << (int)(result[n - 1] * 1000); 

    return 0;
}
