#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
ll n, m;
vector<ll> t;
ll min_v = 1e5;
ll max_v = -1;

ll is_possible(ll mid) {
    ll cnt = 0;

    for (int i=0; i<n; i++){
        cnt += mid / t[i];
        if (cnt > m) {
            break;
        }
    }

    return cnt >= m;
}


void solve(){
    ll answer = -1; 
    ll lo = min_v, hi = max_v * m;

    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if (is_possible(mid)){ // mid 시간으로 가능한 지 check 
            answer = mid;
            hi = mid -1 ;
        }else {
            lo = mid + 1;
        }

    }
    cout << answer;

    return ;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    t.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> t[i];
        min_v = min(t[i], min_v);
        max_v = max(t[i], max_v);
    }

    solve();
    
    return 0;
}