#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 4번 여행가자 
vector<int> root;


int find(int x){
    if(root[x]==x) return x;
    else return root[x]=find(root[x]);
}


void unionNodes(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if(rootA!=rootB){
        root[rootA] = rootB;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    int n,m;  // 도시 수 , 여행 계획 도시수 
    cin >> n >> m;
    root.resize(n+1);

    for(int i=1; i<=n; i++){
        root[i] = i;
    }


    vector<vector<int>> matrix(n+1, vector<int>(n+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> matrix[i][j];
            if(matrix[i][j]==1){
                unionNodes(i,j);
            }
        }
    }

    vector<int> travelCity(m+1,0);

    for(int i=1; i<=m; i++){
        cin >> travelCity[i];
    }
    
    int flag = 1;
    for(int i=1; i<m; i++){
       // cout << find(i) << " ";
        if(find(travelCity[i])!=find(travelCity[i+1])) {
            flag=0; break;
        }
    }

    if(!flag) cout << "NO";
    else cout << "YES";
    
    return 0;
}