#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
vector<pii> input;
vector<int> dp;
int s;

int solve(int n){
    if(n>=s) return 0; // 기저 조건
    if(dp[n] != -1) return dp[n];  // 메모이제이션 확인

    int not_take = solve(n+1); // 일을 선택하지 않고 넘어감 
    int take=0;
    if( n + input[n].first <= s) {
        take = input[n].second + solve(n + input[n].first);
    }
    return dp[n]= max(not_take, take);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> s;
    input.resize(s);
    dp.resize(s, -1);

    for(int i = 0; i < s; i++){
        cin >> input[i].first >> input[i].second;
    } // input[i].first가 t, input[i].second가 p

    int result = solve(0);
    cout << result << "\n";  // 세미콜론 추가

    return 0;
}
