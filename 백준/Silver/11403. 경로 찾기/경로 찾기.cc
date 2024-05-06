#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

// 플로이드 와샬 
int board[101][101]={0,};
void floyd_warshall(int n){

    for(int k=0; k<n; k++ ){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][k] && board[k][j] ){
                    board[i][j]=1; 
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    
    floyd_warshall(n);

    return 0;

}