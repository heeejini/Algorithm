#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
ll solve(ll mid, vector<ll> &arr){
    ll result =0;

    for(ll &s : arr){
        result += s/mid; 
    }

    return result ;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int k, n; cin >> k >> n;
    //이미 가지고 있는 랜선 k, 필요한 랜선 개수 n
    vector<ll> arr(k);
    ll max_lenght=0;
    for(ll &s:arr) {
        cin >> s;
        max_lenght = max(s, max_lenght);
    }
    ll lo =1; 
    ll hi = max_lenght;
    ll result = lo;

    while(lo<=hi){
        ll mid = (lo+hi)/2; //중간 값 

        ll tot = solve(mid, arr);

        if(tot >= n){
            lo = mid+1;
            result = mid;
        }else hi = mid -1;
    }
    cout << result << "\n";
    
    return 0;
}