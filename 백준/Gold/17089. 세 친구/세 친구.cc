// 세친구 
#include <bits/stdc++.h>
using namespace std;


int friends[4001];
bool is_friend[4001][4001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >>m;// n은 사람 수 , m은 친구 관계 수 

    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y ;
        friends[x]++;
        friends[y]++;
        is_friend[x][y] = true;
        is_friend[y][x] = true;
    }

    int min_friend=9999; // 세 사람을 고를 수 없는 경우는 -1 출력 
    bool checked = false;
    int sum=0;
    for(int a = 1; a<=n; a++){
        for(int b=a+1; b<=n; b++){
            if(is_friend[a][b]==true) {
                // a와 b가 친구 
                for(int c = b+1; c<=n; c++){
                    // 셋이 친구인 거 찾기 
                    if(is_friend[c][a]==true && is_friend[c][b]== true){
                        sum = friends[a]+friends[b]+friends[c]-6;
                        min_friend= min(min_friend, sum);
                        checked=true;
                    }
                }
            }
        }
    }
    if(!checked)cout << -1 <<"\n";
    else cout << min_friend <<"\n";
    return 0;
}