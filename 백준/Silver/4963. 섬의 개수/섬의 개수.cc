#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 섬의 개수 

int board[51][51]={0,};
int vis[51][51]={0,};
int w,h; // 크기 저장 
int island = 0 ; // 섬개수 저장 
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1}; // 대각선 이동도 고려 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    while(1){
        cin >> h >> w ;
        if(w==0 && h==0) break; // 문제 종료 조건 
  
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                cin >> board[i][j];
            }
        }

        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                if(vis[i][j]==1 || board[i][j]==0) continue;

                vis[i][j]=1;
                queue<pii> Q;
                Q.push({i,j});
                island++;

                while(!Q.empty()){
                    pii cur = Q.front(); Q.pop();
                    for(int i=0; i<8; i++){
                        int nx = dx[i] + cur.first;
                        int ny = dy[i] + cur.second;

                        if(nx <0 || nx>= w || ny < 0 || ny >= h) continue;
                        if(board[nx][ny]!=1 || vis[nx][ny]) continue;
                        vis[nx][ny] =1;
                        Q.push({nx, ny});
                    }
                }

            }
        }
        cout << island << "\n";
        memset(board, 0, sizeof(board));
        memset(vis, 0, sizeof(vis));
        island=0;
    }
    
    
    
    return 0;
}