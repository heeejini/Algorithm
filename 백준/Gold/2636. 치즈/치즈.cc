#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define X first 
#define Y second

using namespace std;

int board[101][101]={0,};
int vis[101][101]={0,};
int time_cheese =0; // 몇번만에 치즈가 녹아 없어지는 지 
int tot_cheese=0;
int n,m ;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(pii start){
    queue<pii> Q;
    Q.push(start);
    vis[start.X][start.Y] = 1;

    while(!Q.empty()){
        pii cur = Q.front(); Q.pop();

        for(int i=0; i<4; i++){
            int nx = dx[i]+cur.X;
            int ny = dy[i]+cur.Y;

            if(nx<0|| nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny]==1 && vis[nx][ny]==0){
                // 치즈 발견 
                board[nx][ny] = 0;
                vis[nx][ny]=1;
                tot_cheese--;
            }
            else if(board[nx][ny]==0&& vis[nx][ny]==0){
                vis[nx][ny]=1;
                Q.push({nx,ny});
            }
        }
    }
    return ;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j]==1) tot_cheese++;
        }
    }

    int cnt =0;
    while(tot_cheese>0){
        time_cheese++;
        memset(vis, 0, sizeof(vis));
        cnt = tot_cheese;
        bfs({0,0});
        
    }
    cout << time_cheese <<"\n" << cnt <<"\n";    
    return 0;
}