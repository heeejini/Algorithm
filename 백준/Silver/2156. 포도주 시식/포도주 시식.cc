#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
//포도주 마시기
using namespace std;

vector<int> arr;
vector<int> dp;

int solve(int num){
    if(num<0) return 0;
    if(num==0 ||  num==1) return dp[num];

    //memorization
    if(dp[num] != -1) return dp[num];

// 연속 3잔 마실 수 없음 -> 1. num에 해당하는 거 안마시고 넘어감 / 2. 2개 전 / 3. 연속 2잔 
    return dp[num] = max( max(solve(num-1), solve(num-2) + arr[num]), solve(num-3) + arr[num] + arr[num-1]);
 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >>  n;

    arr.resize(n);
    dp.resize(n,-1);


    for(int &s:arr) cin >> s;

    dp[0] = arr[0];
    dp[1] = arr[1]+arr[0];

    cout << solve(n-1) << "\n";

    return 0;
}