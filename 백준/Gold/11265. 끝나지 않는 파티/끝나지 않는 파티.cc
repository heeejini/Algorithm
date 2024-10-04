#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define INF 1e9
using namespace std;
vector<vector<int>> board;
void floydwarshall(int n){

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] > board[i][k]+board[k][j]){
                    board[i][j] = board[i][k]+board[k][j];
                }
            }
        }
    } 
    return ;
}

void solve(int n, int m){
    int a, b, time;

    for(int i=0; i<m; i++){
        cin >> a >> b >> time;
        if(board[a-1][b-1] <= time){
            cout << "Enjoy other party\n";
        } else cout << "Stay here\n";
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    board.resize(n, vector<int> (n, INF));
    // 파티장의 크기 n, 서비스를 요청한 손님의 수 m 
    // N개의 줄에 걸쳐 각각의 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }    
    }
    

    floydwarshall(n);
    solve(n,m);

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << board[i][j] << " ";
    //     }    
    //     cout << endl;
    // }
    
    return 0;
}