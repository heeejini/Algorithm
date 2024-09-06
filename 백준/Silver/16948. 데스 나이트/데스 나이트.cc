#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first
#define y second
using namespace std;
pii dir[8] = {{-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1}};
vector<vector<int>> board;
vector<vector<int>> dist;
int n;

void solve(pii p1, pii p2){
    queue<pii> Q;
    Q.push(p1);
    int min_cnt = 1e9;
    
    while(!Q.empty()){
        pii cur = Q.front();
        Q.pop();

        if(cur.x == p2.x && cur.y == p2.y) break;

        for(int i=0; i<8; i++){
            int nx = cur.x + dir[i].x;
            int ny = cur.y +dir[i].y;
            if(nx <0 || ny <0 || nx >=n || ny >= n) continue;

            if(dist[nx][ny] == -1 ){  
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.x][cur.y] + 1;  
            }

        }
    }
    if(dist[p2.x][p2.y]!=-1) cout << dist[p2.x][p2.y] <<endl;
    else cout << -1 <<endl;
                
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n ;//체스판의 크기 
    board.resize(n+1, vector<int> (n+1,0));
    dist.resize(n+1, vector<int> (n+1,-1));

    pii p1, p2;

    cin >> p1.x >> p1.y >> p2.x >> p2.y ;
    dist[p1.x][p1.y]=0;
    solve(p1, p2);
    return 0;
}