#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

// 최소 스패닝 트리 
vector<int> root;

// find 함수 (경로 압축 적용)
int find(int x) {
    if (root[x] == x) {
        return x; // 같은 부모라고 판단되면 간선 추가x, 사이클이 발생하기 떄문에 
    } else {
        return root[x] = find(root[x]); 
    }
}

// kruskal -> union-find 사용 
void unionNodes(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        root[rootX] = rootY;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    vector<pair<int, pii>> edges;

    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({ cost, { from, to } });
    }

    sort(edges.begin(), edges.end());

    root.resize(v + 1);
    for (int i = 1; i <= v; i++) {
        root[i] = i;
    }

    int result = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int from = edges[i].second.first;
        int to = edges[i].second.second;

        if (find(from) != find(to)) {
            unionNodes(from, to);
            result += cost;
        }
    }

    cout << result << endl;

    return 0;
}
