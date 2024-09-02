#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
// 숫자 야구 - boj2503


set<string> candidates; // 후보군들 저장 
void solve(string num, int strike, int ball) {

    set<string> new_candidates;

    for(const auto& candidate : candidates ){

        int s_cnt=0, b_cnt=0;

        for(int i =0; i<3; i++){
            if(num[i]==candidate[i]){
                s_cnt++;
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i!=j && num[i] == candidate[j]){
                    b_cnt++;
                }
            }
        }
        if(strike == s_cnt && ball == b_cnt){
            new_candidates.insert(candidate);
        }
    }

    candidates = new_candidates;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int tc;
    cin >> tc;
    int ball, strike;
    string num;

    string candidate;

    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(i==j)continue;
            for(int k=1; k<=9; k++){
                if(i==k || k==j) continue;

                string candidate = "";
                candidate += to_string(i);
                candidate += to_string(j);
                candidate += to_string(k);

                candidates.insert(candidate);
            }
        }
    }

    for(int i=0; i<tc; i++){
        cin >> num >> strike >> ball;
        solve(num, strike, ball); 
    }
    // for (const auto& candidate : candidates) {
    //     cout << candidate << endl;
    // }

    cout << candidates.size() <<endl;
    return 0;
}