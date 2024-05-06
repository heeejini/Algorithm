#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int board[101][101][101]={0,};
int dx[6] = {1, -1, 0, 0, 0, 0}; // x 축 이동 (우, 좌)
int dy[6] = {0, 0, 1, -1, 0, 0}; // y 축 이동 (상, 하)
int dz[6] = {0, 0, 0, 0, 1, -1}; // z 축 이동 (위, 아래) // 상하좌우 네 방향을 의미
int m,n,h;

int dist[101][101][101]={0,};
queue<tuple<int, int, int>> Q;

void bfs(){

    while(!Q.empty()){
        tuple<int, int, int> current = Q.front(); Q.pop();

        int cur_x = get<0>(current);
        int cur_y = get<1>(current);
        int cur_z = get<2>(current);

        for(int i=0; i<6; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            int nz = cur_z + dz[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue; // 범위 밖일 경우 넘어감
            if(dist[nx][ny][nz] >=0) continue;
            dist[nx][ny][nz]=dist[cur_x][cur_y][cur_z]+1;
            Q.push(make_tuple(nx, ny, nz));
        }
    }

    return ;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n >> h;

    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> board[i][j][k];
                if(board[i][j][k]==1) Q.push(make_tuple(i, j, k));
                if(board[i][j][k]==0) dist[i][j][k]=-1;
            }
        }
    }

    bfs();
    
    int result=0;

    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dist[i][j][k]==-1) {
                    cout << "-1";
                    return 0;
                }
                result = max(result, dist[i][j][k]);
            }
        }
    }
    cout << result <<"\n";
    return 0;
}
