#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
vector<vector<int>> board;    
vector<vector<int>> dist;  
int n,m;

void floydWarshall(){

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(board[i][j] > board[i][k] + board[k][j]){
                    board[i][j] = board[i][k] + board[k][j];
                    // cout << dist[i][k];
                    dist[i][j] = dist[i][k];
                }
            }
        }
    }

    return;
}

void solve(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) 
                cout << "- ";
            else 
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    board.resize(n+1, vector<int>(n+1,1e9));
    dist.resize(n+1, vector<int>(n+1,1e9));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) board[i][j]=0; // 자기 자신에서는 0
        }
    }

    int _to,_from, w;
    for(int i=1; i<=m;i++){
        cin >> _to >> _from >> w;
        board[_to][_from] = w;
        board[_from][_to] =w;
        dist[_to][_from] = _from;
        dist[_from][_to] = _to; 
    }

    floydWarshall();
    solve();
    return 0;
}
