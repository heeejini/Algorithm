#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

//유기농 배추 - bfs

int board[51][51]; // n ,m <=50
bool vis[51][51]; 
int m,n, k; //m가로,n세로,k심은 배추 갯수 
int test_case;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(){
    int cnt =0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j] || board[i][j]==0)continue;
            vis[i][j] =1;
            cnt++;
            queue<pii> Q;
            Q.push({i,j});

            while(!Q.empty()){
                pii current = Q.front(); Q.pop();
                for(int i=0; i<4; i++){
                    int nx = current.first + dx[i];
                    int ny = current.second + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << "\n"; 
    
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    //cin >> m >> n >> k ; 

    cin >> test_case;

    for(int i=0; i<test_case; i++){
        cin >> m >> n >>k;
        memset(board, 0, sizeof(board));
        memset(vis, 0, sizeof(vis));
        for(int i =0; i<k; i++){
            pii temp;
            cin >> temp.first >> temp.second; 
            board[temp.first][temp.second] = 1; 
        }

        bfs();
    }
    
    
    return 0;
}