#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
vector<int> order;
int n, m, start;
// 알고리즘 수업 - 너비 우선 탐색 1
void bfs(vector<vector<int>> &v, vector<int> &visited, int start) {
    queue<int> Q;
    Q.push(start);
    visited[start]=1;
    int cnt =1; 

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        for(int next : v[cur]){
            // 인접 리스트에서 인접한 원소들을 for 문을 통해 순회 
            if(!visited[next]){
                visited[next]=1;
                order[next] = ++cnt;
                Q.push(next);
            }
        }
        
    }

    for(int i=1; i<=n; i++){
        cout << order[i] << "\n";
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> start;

   // vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> v(n+1); // 인접 행렬 메모리 초과 -> 인접 리스트로 풀기 
    vector<int> visited(n+1, 0);
    order.resize(n+1,0);
    order[start]=1;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); 
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }

    bfs(v, visited, start);
    return 0;
}
