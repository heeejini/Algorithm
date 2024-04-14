#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
ll sum_money(ll mid, vector<ll> &arr){
    ll result=0;

    for(ll &m: arr){
        result += min(m, mid);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n; // 지방의 수 
    vector<ll> arr(n);
    ll max_money = 0 ;
    for(ll &s : arr) { 
        cin >> s;
        max_money = max(s, max_money);
    }

    ll sum ; cin >> sum;

    ll lo = 0;
    ll hi = max_money;
    ll result = lo;
    while(lo<=hi){
        ll mid = (lo+hi)/2;

        ll s = sum_money(mid, arr);    

        if(s <= sum){
            lo = mid+1;
            result = mid;
        }else hi = mid-1;

    }
    cout << result <<"\n";
    
    return 0;
}