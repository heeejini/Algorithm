#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> arr;
vector<int> dp;

int solve(int n){
    // base condition
    if(n<0) return 0; 
    if(dp[n]!=-1) return dp[n];
    if(n==0) return dp[n]=arr[0]; 
    if(n==1) return dp[n]=arr[1]+arr[0];


    return dp[n] = max(solve(n-2) + arr[n], solve(n-3) + arr[n-1] + arr[n]);

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    arr.resize(n);
    dp.resize(n,-1);

    for(int &s : arr) cin >> s;

    cout << solve(n-1) <<"\n";
    
    return 0;
}