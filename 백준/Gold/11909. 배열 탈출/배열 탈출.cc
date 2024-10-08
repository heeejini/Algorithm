#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ppi pair<pii, int> 
// 좌표 저장 & 거리 저장하기 위해서 새롭게 선언

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> dist;
int dx[2]={1,0}; // 오른쪽, 아래로만 이동 
int dy[2]={0,1};

int dijikstra(){
    dist[0][0] = 0; // 시작 노드 초기화 
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    pq.push({{0, 0}, 0});

    while(!pq.empty()){
        pii cur = pq.top().first;
        int dst = pq.top().second;
        pq.pop();

        if(dst >  dist[cur.first][cur.second]) continue;

        for(int i=0; i<2; i++){
            // 오른쪽, 아래 탐색 
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx <0 || ny <0 || nx >=n || ny >=n) continue;

            int new_cost = max(0, board[nx][ny] - board[cur.first][cur.second] + 1);

            if(dist[nx][ny] > dist[cur.first][cur.second] + new_cost){
                dist[nx][ny] = dist[cur.first][cur.second] + new_cost;
                pq.push({{nx, ny}, new_cost});
            }

        }

    }
    return dist[n-1][n-1] ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    board.resize(n, vector<int> (n));
    dist.resize(n, vector<int> (n, 1e9));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    int result = dijikstra();
    cout << result ;
    
    return 0;
}