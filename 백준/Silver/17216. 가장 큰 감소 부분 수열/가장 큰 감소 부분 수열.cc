#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
int n;
int dp[1001] = {0,};
int arr[1001] ={0,};

void solve(){

	int sum = 0;

	for(int i=0; i<n; i++){
		//dp[i] = arr[i];
		dp[i] = arr[i];
		for(int j=0; j<i; j++){
			if(arr[i]<arr[j]){
				//dp[i] = max(dp[i], dp[j]+1);
				dp[i] = max(dp[i], dp[j] + arr[i]);
			//	cout << arr[i] <<  " " << arr[j] << endl;
			}
		}
	}

	cout << *max_element(dp,dp+n+1);
	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;

	for(int i=0; i<n; i++) cin >> arr[i];

	solve();
	
	return 0;
}