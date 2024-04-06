#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
// 1로 만들기 
using namespace std;
vector<int> result;

void solve(int n){
    result.resize(n+1);
    result[0]=0;

    for(int i=2; i<=n; i++){
        result[i] = result[i-1]+1; //-1 하는 경우 이전 저장값에서 +1
        if(i%2==0){ 
            result[i] = min(result[i], result[i/2]+1); //result[i/2]+1 -> i를 i/2로 나눠서 1로 만드는 경우때뭉에 +1
        }
        if(i%3==0){
            result[i] = min(result[i], result[i/3]+1);
        }

    }
    cout << result[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    solve(n);
    
    return 0;
}