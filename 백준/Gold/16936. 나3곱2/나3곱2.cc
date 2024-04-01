#include <bits/stdc++.h>
using namespace std;

vector<long long> find_arr(long long num,int cnt, vector<long long> &arr, vector<long long> &result ){
    if(cnt == arr.size())
        return result;

//2의 배수가 존재하는 지 확인, 3으로 나눠지는 지 확인,(a/3 && a&3==0)
    if(find(arr.begin(), arr.end(),num*2)!=arr.end()){
        // 2곱이 존재할 때
        result.push_back(num*2);
        return find_arr(num*2, cnt+1, arr, result);

    }else if((find(arr.begin(), arr.end(), num/3)!=arr.end() && (num%3==0)) ){
        //나3이 존재할 때 
        result.push_back(num/3);
        return find_arr(num/3, cnt+1, arr, result);
    }else{ //값이 없으면 result를 비우고 리턴
        result.clear();
        return result;        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> arr(n);

    for(long long &s: arr) cin >> s;

    bool flag= false;
    vector<long long> result ;

    for(int i=0; i<n; i++){
        result.push_back(arr[i]);// 원소 하나씩 넣어봐서 check
        result = find_arr(arr[i], 1, arr, result);

        if(result.size() == n){
            flag = true;
            break;
        }
    }
    if(flag){ //결과 출력 
        for(long long &num:result)
            cout << num << " ";
    }
    return 0;
}