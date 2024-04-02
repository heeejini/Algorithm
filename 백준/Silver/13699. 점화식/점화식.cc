#include <bits/stdc++.h>
using namespace std;

long long dp[36];
int main(void){
	int n;
    cin >> n;
    dp[0]=1;
    for (int i = 1; i <=n; i++){
        for (int j = 0; j <= i - 1; j++){
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    cout << dp[n] ;
}