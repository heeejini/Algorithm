#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
// 이상한 술집
using namespace std;

ll solve(ll mid, vector<ll> &num){
    ll result =0;

    for(ll &s:num){
        result += s/mid;
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k; cin >> n >> k;
    vector<ll> num(n);
    ll max_value = 0;
    for(ll &s:num) {
        cin >> s;
        max_value = max(max_value, s);
    }

    ll lo = 1;
    ll hi = max_value;
    ll result = lo;

    while(lo<=hi){
        ll mid = (lo+hi)/2;

        ll sum = solve(mid, num);

        if(sum >= k){
            lo = mid+1;
            result = mid;
        }else hi = mid -1;

    }
    cout << result << "\n";
    
    return 0;
}