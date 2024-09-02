#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

int arr[8];
bool isused[8]; // 현재 상태, 어떤 게 쓰였는 지 체크하는 변수 
int n, m;
string result; // 결과를 저장할 문자열

void func(int k){ // 현재 k까지 택한 상태,
    if(k == m){
        for(int i = 0; i < m; i++)
            result += to_string(arr[i]) + " ";
        result += "\n";
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    func(0); // 맨 처음에는 수를 하나도 택하지 않았으니 0에서 시작 
    
    cout << result; // 한 번에 출력
    
    return 0;
}
