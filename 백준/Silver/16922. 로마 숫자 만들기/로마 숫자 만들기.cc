#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> v = {1, 5, 10, 50};
int n, cnt =0;
bool visited[1001]; 

void solve(int idx, int result, int N){

    if(N==n){
        if(!visited[result]){
            visited[result] = true;
            cnt ++;
        }
        return ;
    }

    for(int i=idx; i<4; i++){
        solve(i, result +v[i], N+1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    solve(0,0, 0);

    cout << cnt << endl;
    
    return 0;
}