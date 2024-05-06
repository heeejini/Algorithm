#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 1차원 토마토
int board[1001][1001]={0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int m,n;
int dist[1001][1001]={0,};
queue<pii> Q;

void bfs(){

    while(!Q.empty()){
        pii current = Q.front(); Q.pop();

        for(int i=0; i<4; i++){
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(dist[nx][ny] >=0) continue;
            dist[nx][ny]=dist[current.first][current.second]+1;
            Q.push({nx,ny});
        }
    }

    return ;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j]==1) Q.push({i,j});
            if(board[i][j]==0) dist[i][j]=-1;
        }
    }

    bfs();
    
    int result=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j]==-1) {
                cout << "-1";
                return 0;
            }
            result = max(result, dist[i][j]);
        }
    }
    cout << result <<"\n";
    return 0;
}