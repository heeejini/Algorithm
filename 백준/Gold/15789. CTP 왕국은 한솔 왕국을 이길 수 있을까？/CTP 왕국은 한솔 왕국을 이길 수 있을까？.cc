#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
//CTP 왕국은 한솔 왕국을 이길 수 있을까? 
using namespace std;
vector<int> root;

int find(int a){
    if(root[a]==a) {
        return a;
    }
    else {
        return root[a]=find(root[a]);
    }
}
void unionNodes(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if(rootA!=rootB){
        root[rootA] = rootB;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; // 왕국의 수 , 동맹 관계 수 
    // 최대 k개의 동맹, gtp 왕국은 한솔 왕국과 동맹인 왕국과는 동맹을 맺을 수 없음 (아무리 최장이여도 한솔왕국이 포함되어있다면 안됨), 
    // 최대 k번 동맹을 맺을 수 있지만, k번을 다 안해도 됨
    cin >> n >> m;
    
    root.resize(n+1,0);

    // 초기화 
    for(int i=1; i<=n; i++){
        root[i]=i; 
    }

    int a,b;
    // 동맹 입력 받기 
    for(int i=0; i<m; i++){
        cin >> a >> b;
        unionNodes(a,b);
    }
    vector<pii> temp;
    int CTP, hansol, k ;
    cin >> CTP >> hansol >> k;

   
    int ctp_root = find(CTP);
    int hansol_root = find(hansol);

    vector<int> arr(n+1,0);

    for(int i=1; i<=n; i++){
        int idx = find(i);
        arr[idx]++;
    }
    

    
    // ctp와 연결된 집합들의 크기 
    int ctp_power = arr[ctp_root];
  //  cout << ctp_power << "\n";
    arr[ctp_root]=0; arr[hansol_root]=0;


    sort(arr.begin(), arr.end(), greater<int>());
    // for(int i=0; i<=n; i++){
    //    // cout << arr[i] << " ";
    // }

    for(int i=0; i< k; i++){
        ctp_power += arr[i];
    }
    cout << ctp_power<<"\n";

    return 0;
}