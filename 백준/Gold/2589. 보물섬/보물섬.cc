#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 보물섬 2589
int n,m;
char board[51][51]={0,};
int vis[51][51]={0,};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int cnt=0;
int min_len=0;
int num=0;
int max_distance = 0;
void bfs(pii start){
    
    memset(vis, -1, sizeof(vis));
    queue<pii> Q;
    vis[start.first][start.second]=0;
    Q.push({start.first, start.second});

    while(!Q.empty()){
        pii cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = dx[i]+cur.first;
            int ny = dy[i]+cur.second;

            if(nx<0 || nx >= n || ny <0 || ny>=m) continue;
            if(board[nx][ny]=='L' && vis[nx][ny] == -1){
                vis[nx][ny] = vis[cur.first][cur.second]+1;
                max_distance=max(max_distance, vis[nx][ny]);
                Q.push({nx,ny});
            }
        }
    }
   // cout << max_distance << "\n";
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m ;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='L'){
                bfs({i,j});
            }
        }
    }
    cout << max_distance <<"\n";
    return 0;
}