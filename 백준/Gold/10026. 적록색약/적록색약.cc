#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<string> rgb;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool vis[100][100];
int n;

void bfs(int i, int j){
    queue<pii> Q;
    Q.push({i,j});
    vis[i][j]=true;

    while(!Q.empty()){
        pii cur = Q.front(); Q.pop();

        for(int i=0; i<4; i++){
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx <0 || ny <0 || nx >= n || ny >=n)continue;

            if(rgb[nx][ny]==rgb[cur.first][cur.second] && vis[nx][ny]!=1){
                vis[nx][ny] =true;
                Q.push({nx, ny});
            }
        }

    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    rgb.resize(n);

    for(int i=0; i<n;i++){
        string temp;
        cin >> temp;
        rgb[i] = temp;
    }

    int cnt =0;
    // 적록색약이 아닌 사람이 보는 갯수 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!vis[i][j]) 
            {
                bfs(i,j);
                cnt ++; // bfs 가 끝나면 한 구역을 다 돈것이기 때문에 ++ 을 해준다. 
            }
        }
    }

    cout << cnt << " ";
    
    memset(vis, false,sizeof(vis)); // 방문 배열 초기화 
    cnt =0;
    // 적록 색약인 사람

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(rgb[i][j]=='G') {
                rgb[i][j]='R';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!vis[i][j]) 
            {
                bfs(i,j);
                cnt ++; // bfs 가 끝나면 한 구역을 다 돈것이기 때문에 ++ 을 해준다. 
            }
        }
    }

    cout << cnt << " ";
    return 0;
}