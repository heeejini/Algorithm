#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
ll n, k;

bool is_possible(ll mid){
    ll result = k * (mid+1) * mid / 2; // mid 번째까지의 합을 등차 수열로 표현 
    return result <= n-1; // mid 번까지 뛰었을 때 합이 n-1을 넘으면 안됨
}

void solve(){
    char dir ; // 방향 나타내기
    ll loc; // 위치

    ll lo=0;
    ll hi = sqrt(2 * (n - 1) / k) + 1; 
    ll result; // 몇번까지 갈건지 
    while(lo <= hi){
        ll mid = (lo+hi)/2;

        if(is_possible(mid)){
            result = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }

    }
    ll tot_dist = k * result * (result+1) /2;
    ll remain_dist = (n-1) -tot_dist;
   // cout << result << " " << tot_dist << "  " << remain_dist << endl;
    if(result%2){
        // 홀수일 때, (오른쪽으로 이동)
        dir = 'L';
        loc=(result+1)/2*k-remain_dist;
    
    }else{ // 짝수일 때, 왼쪽으로 이동 
        dir = 'R';
        loc = (result)/2*-k+remain_dist;

    }
    cout << loc << " " << dir <<"\n";

    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int tc ; 
    cin >> tc ;

    for(int i=0; i<tc; i++){
        cin >> n >> k;
        solve();
    }
    
    return 0;
}