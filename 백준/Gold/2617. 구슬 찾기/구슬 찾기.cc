#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;


int m,n; //m은 구슬의 갯수 , n은 저울에 올려본 쌍의 갯수 
vector<vector<int>> small;
vector<vector<int>> big;
vector<bool> visited;

int solve(vector<vector<int>> v, int i){
    fill(visited.begin(), visited.end(), false);


    queue<int> Q;
    Q.push(i);
    visited[i] =true;

    int cnt =0;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        for(int next : v[cur]){
            if(!visited[next]){
                visited[next] = true;
                Q.push(next);
                cnt ++ ;
            }
        }
    }

    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m ;

    small.resize(n+1);
    big.resize(n+1);
    visited.resize(n+1);

    // 앞 번호의 구슬이 뒤 번호의 구슬보다 무겁다는 것을 의미
    for(int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;
        small[b].push_back(a); // 작은 관계를 나타내는 인접리스트
        big[a].push_back(b); // 큰 관계를 나타내는 인접리스트 
    }

    int cnt =0; // 무게가 중간인 구슬이 될 수 없는 구슬의 갯수를 저장하기 위한 변수 

    for(int i=1; i<=n; i++){
        int s_cnt = solve(small,i);
        int b_cnt = solve(big, i);

        if(s_cnt >= (n+1)/2 || b_cnt >= (n+1)/2) cnt ++;

    }

    cout << cnt ;
    return 0;
}