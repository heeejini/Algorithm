#include <bits/stdc++.h>
using namespace std;
int n,s;
int cnt =0;
int arr[30];


void recursive(int idx, int sum){
    // base condition 설정
    if(n==idx){
        if(s == sum) cnt ++;
        return ;
    }
    // 재귀 
    recursive(idx+1, sum); //현재 수를 더하지 않는다
    recursive(idx+1, sum+arr[idx]);// 현재 수를 더한다

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    if(s==0) cnt -=1; //공집합 제거 
    
    recursive(0,0);
    cout << cnt << "\n";
    

}