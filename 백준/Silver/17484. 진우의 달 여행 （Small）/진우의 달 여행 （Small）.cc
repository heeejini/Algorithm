#include <bits/stdc++.h>
using namespace std;
int n,m;
int direction[3] = {-1,0,1};

int cost_to_the_moon(int r, int c, int dir, vector<vector<int>> &cost){
  
    if(r==0) return cost[0][c];
    int temp = 9999999999;

    for(int i=0; i<3; i++){
        if(dir == i) continue; // 똑같은 방향 2번 가면안됨
        if(c+direction[i] < 0 || c+direction[i]>=m) continue;
        int sum = cost_to_the_moon(r-1, c+direction[i], i, cost) + cost[r][c];
        temp = min(sum, temp);
    }

    return temp;
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> n >> m ;

    vector<vector<int>> cost(n, vector<int>(m,0));

    for(int i=0;i<n; i++){ 
        for(int j=0; j<m; j++){
            cin >> cost[i][j];
        }
    }
    int answer=99999999;
    for(int i=0; i<m; i++){
        answer = min(answer,cost_to_the_moon(n-1, i,-1, cost));
    }
    cout<< answer ;
    return 0;
}