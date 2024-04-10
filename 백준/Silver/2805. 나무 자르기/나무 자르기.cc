#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
ll tree_sum(ll mid, vector<ll> &trees){
    ll sum_tree=0;

    for(ll &t: trees){
        sum_tree += max(t-mid, 0LL);// 안잘리는 나무는 0을 리턴해주기
    }
    return sum_tree;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll tree_num; cin >> tree_num;
    ll min_height; cin >> min_height;
    
    vector<ll> trees(tree_num);

    for(ll &n:trees)cin >> n;

    ll lo =0;
    ll hi=1e9;
    ll mid;

    ll result = lo;
    while(lo<=hi){
        mid = (lo+hi)/2;

        ll sum = tree_sum(mid, trees);

        if(sum >= min_height){
            lo =mid+1;
            result = mid;
        }else{
            hi = mid -1;
        }
    }
    cout << result <<"\n";
    return 0;
}