#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<int> order;
int cnt = 1;

void dfs(int r){
    visited[r] = true; // 방문 처리 
    order[r] = cnt ++;

    for(int next : v[r]){
        if(!visited[next]){
            dfs(next);
        }
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, r;
    cin >> n >> m >> r;

    v.resize(n+1);
    visited.resize(n+1, false);
    order.resize(n+1,0);

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
    dfs(r);

    for(int i=1; i<=n; i++){
        cout << order[i] <<"\n";
    }

    
    return 0;
}