#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 2번 부등호 - boj2529번
vector<string> results;// 결과를 저장할 문자열 vector
char signs[9]; // 부등호
bool checked[10];
int _len;

void solve(int idx, string result){ // 현재 k까지 택한 상태, 
    if(idx == _len+1){
        results.push_back(result);
        return;
    }
    for(int i=0; i<=9; i++){
        if(!checked[i]){
            // idx가 0이면 맨 처음 수는 넣어줘야됨 / 이전 부등호가 < 면 현재 값이 i보다 커야됨 / 이전 부등호가 > 면 현재 값이 i 보다 작아야됨 
            if(idx==0 || signs[idx-1]=='<' && result[idx-1]-'0'<i || signs[idx-1]=='>' && result[idx-1]-'0'> i ){
                checked[i]=true;
                solve(idx+1, result+to_string(i));
                checked[i]=false;
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> _len;

    for(int i=0; i<_len; i++){
        cin >> signs[i];
    }

    solve(0, "");
    
    sort(results.begin(), results.end());
    
    cout << results.back() << endl;
    cout << results.front() <<endl;
    
    return 0;
}