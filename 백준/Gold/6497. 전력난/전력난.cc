#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define ll long long

using namespace std;

vector<int> root;

ll find(ll x){
    if(root[x] == x) return x;
    else return root[x] = find(root[x]);
}

void unionNodes(ll x, ll y){
    ll rootX = find(x);
    ll rootY = find(y);

    if(rootX != rootY){
        root[rootX] = rootY;
    }
}
// 절약할 수 있는 최대 액수 -> MST를 만들어서 그 가중치들만 키게 함
// 전체 - MST 가중치 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int v, e;
        cin >> v >> e;
        if (v == 0 && e == 0) break;

        vector<pair<ll, pii>> edges;
        ll sum = 0;
        for (int i = 0; i < e; i++) {
            ll from, to, cost;
            cin >> from >> to >> cost;
            edges.push_back({cost, {from, to}});
            sum += cost;
        }

        sort(edges.begin(), edges.end());

        root.resize(v); // 벡터 크기를 v로 조정
        for (int i = 0; i < v; i++) {
            root[i] = i; // 초기 루트는 자기 자신
        }

        ll mst_cost = 0;
        for (const auto& edge : edges) {
            ll cost = edge.first;
            ll x = edge.second.first;
            ll y = edge.second.second;

            if (find(x) != find(y)) { // 같은 parent 소유시 사이클 발생
                unionNodes(x, y);
                mst_cost += cost;
            }
        }

        cout << sum - mst_cost << "\n";
    }

    return 0;
}
