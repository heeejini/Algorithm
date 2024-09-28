#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define INF 1e9
using namespace std;
int n;
vector<vector<int>> student;


void solve(){

    int cnt = 0;
    int _min = INF;
    int _max = 0;
    vector<pii> temp;
    vector<int> candidates;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(student[i][j] > student[i][k] + student[k][j]){
                    student[i][j] = student[i][k] + student[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        _max = 0;
        for(int j=1; j<=n; j++){
            if(i!=j){
                _max = max(_max, student[i][j]);
            }
        }
        temp.push_back({i, _max});
        _min = min(_min, _max);
    }
    
    for(int i=0; i<n; i++){
        if(_min == temp[i].second){
            cnt++; 
            candidates.push_back(temp[i].first);
        }
    }
    cout << _min << " "  << cnt << "\n";
    for(int i = 0; i < candidates.size(); i++){
        cout << candidates[i] << " ";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    student.resize(n+1, vector<int>(n+1, INF));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) student[i][j] = 0;
        }
    }

    int a,b;

    while(1){
        cin >> a>>b;
        if(a==-1 && b==-1) break;
        student[a][b]=student[b][a]=1;
    }

    solve();
    
    return 0;
}