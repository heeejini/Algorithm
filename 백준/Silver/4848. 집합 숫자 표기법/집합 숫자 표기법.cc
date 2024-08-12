#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

void solve(string s_set[]) {
    string s1, s2;
    
    cin >> s1 >> s2;

    int idx1, idx2;
    for(int i=0; i<16; i++){
        if(s1 == s_set[i]){
            idx1 = i;
        }
        if (s2 == s_set[i]){
            idx2 = i;
        }
    }

    cout << s_set[idx1+idx2] <<"\n";
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s_set[16];
    s_set[0] = "{}";
    s_set[1] = "{{}}";
    s_set[2] = "{{},{{}}}";

    // 0~15까지 생성해주기 
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    for(int i=3; i<16; i++){
        s_set[i] += "{";

        for(int j = 0; j<i ; j++){
            if(j==i-1) s_set[i]+=s_set[j];
            else s_set[i] += s_set[j] + ",";
            //s_set[i] +=",";
        }
        s_set[i] += "}";
    }


    int tc;
    cin >> tc;

    while(tc--) {
        solve(s_set);
    }

    return 0;
}
