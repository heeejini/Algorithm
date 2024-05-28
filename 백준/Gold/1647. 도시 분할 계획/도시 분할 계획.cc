#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> root;

int find(int x){
    if(root[x]==x) return x;
    else return root[x]=find(root[x]);
}

void unionNodes(int x, int y){
    int rootX = find(x);
    int rootY = find(y);

    if(rootX!=rootY){
        root[rootX]= rootY;
    }
}
// 도시 분할 계획 
// MST 구현 후 최대 가중치 간선 제거 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int v,e;

    cin >> v >> e;

    vector<pair <int, pii>> edges;

    for(int i=0; i<e; i++){
        int from, to, cost;
        cin >> from >> to >> cost;

        edges.push_back({cost , {from, to}});
    }

    sort(edges.begin(), edges.end());

    root.resize(v+1);

    for(int i=1; i<=v; i++){
        root[i]=i; // 초기 루트는 자기 자신 
    }
    
    int result = 0;
    int max_edge = -1;
    for(int i=0; i<edges.size(); i++){
        int cost = edges[i].first;
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        //만약 어떤 간선을 선택했을 때, 그 간선의 두 정점이 같은 최상위 Parent를 갖는다면 (즉, 같은 그룹에 속했다면) 스패닝 트리에 추가했을 때 사이클이 발생함을 의미한다.
        if(find(x)!=find(y)){
            unionNodes(x,y);
            result += cost;
            max_edge = max(max_edge, cost); 
            /*
            마을을 두개로 분리 -> MST 구현 후에 가장 큰 가중치를 갖는 간선을 제거하면 2개의 마을로 분리할 수 잇다
            */
        }
    }

    cout << result-max_edge << "\n";
    return 0;
}