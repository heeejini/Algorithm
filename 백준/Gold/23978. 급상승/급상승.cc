#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
ll n, k;
vector<ll> date;

ll total_money(ll mid){
    ll result = 0;
    ll interval ;
    for(int i=0; i<n; i++){
        if(i<n-1){ // time 배열 안에서 간격을 파악할 수 있으면
            interval = min(date[i+1]-date[i], mid);
        }else interval = mid; 

        ll first = mid;
        ll last = mid - (interval-1); // x=3일 때 interval이 2면 마지막 가격은
        // 3 2 1 

        ll sum = (first+last)*interval /2 ; // 등차 수열의 합
        result +=sum;

        if(result >= k) break;
    }

    return result;
}

void solve(){

    ll lo=0, hi=1e10;
    ll answer=-1;

    while(lo<=hi){
        ll mid = (lo+hi)/2;

        if(total_money(mid)>=k){
            answer = mid;
            hi = mid -1;

        }else lo = mid+1;
    }
    cout << answer << "\n";
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    date.resize(n);

    for(int i=0; i<n; i++){
        cin >> date[i];
    }

    solve();
    
    
    return 0;
}