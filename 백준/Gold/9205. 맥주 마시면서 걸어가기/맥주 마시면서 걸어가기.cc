#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first 
#define y second
using namespace std;
int t, n;//테스트 케이스, 편의점 갯수 
bool vis[101];
pii mart[101];
pii home;
pii festival;


bool bfs(int n){
    queue<pii> Q;
    Q.push({home.x, home.y});

    while(!Q.empty()){
        pii cur = Q.front(); Q.pop();
        if(abs(festival.x-cur.x)+abs(festival.y-cur.y)<=1000) return true;
        for(int i=0; i<n; i++){
            if(vis[i]==1) continue; //방문한 편의점은 스킵
            if(abs(mart[i].x - cur.x) + abs(mart[i].y-cur.y)<=1000){
                vis[i]=1;
                Q.push({mart[i].x, mart[i].y});
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n; //편의점 갯수 입력 받기 
        cin >> home.x>> home.y;

        for(int i=0; i< n; i++){
            cin >> mart[i].x >> mart[i].y;
        }

        cin >> festival.x >> festival.y;

        bool result = bfs(n);
        if(result==true) cout << "happy\n";
        else cout<<"sad\n";
        memset(vis, false, sizeof(vis));
    }
    
    
    return 0;
}