#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define ll long long

using namespace std;

void solve() {
    int num; // Number of clothing items
    cin >> num;

    unordered_map<string, int> clothes;

    for(int i=0; i<num; i++){
        string _name, _types;

        cin >> _name >> _types;
        clothes[_types] ++;
    }

    int result =1;

    for(const auto &ele : clothes){
        result *= (ele.second +1 );//  해당 옷을 입거나 입지 않는 경우 
        // ex . 종류 1 : 모자 2개 -> 모자 2개 + 모자를 쓰지 않는경우 (1)
    }
    cout << result -1 <<"\n"; //-1 해주는 이유 : 모든 옷을 입지 않는 경우(공집합 제거)
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc; // Number of test cases
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        solve();
    }

    return 0;
}
