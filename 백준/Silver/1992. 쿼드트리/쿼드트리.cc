#include <bits/stdc++.h>
using namespace std;

int n;
char video[65][65];
string result;

bool is_equal(int x, int y, int size){ 
    // 모든 값이 똑같은 지 check 하는 함수 is_equal 
    char first = video[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(video[i][j]!=first){
                return false; //
            }
        }
    }
    return true;
}

void quad_tree(int x, int y, int size){
    // 모두 0,1로 같을 때
    bool checked = is_equal(x,y,size);
    if(checked){
        result+= video[x][y]; return; 
    }

    //1사,2사,3사,4사분면 나눠서 check 
    int div_2 = size/2;

    result +='(';

    quad_tree(x,y,div_2); 
    quad_tree(x, y+div_2, div_2);
    quad_tree(x+div_2, y, div_2);
    quad_tree(x+div_2, y+div_2, div_2);

    result +=')';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    // 문자열로 입력 받아 처리
    for (int i = 0; i<n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            video[i][j] = row[j];
        }
    }

    quad_tree(0,0,n);
    cout <<result <<'\n';
    return 0;
}
