#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;
vector<string> ingredients;
vector<string> temp;

void check_ingredient(){
    string answer = "";
    sort(ingredients.begin(), ingredients.end());
    sort(temp.begin(), temp.end());

    for(int i=0; i<temp.size(); i++){
        if(ingredients[i]!=temp[i]){
            answer = ingredients[i];
            break;
        }
    }
    if(answer==""){
        answer = ingredients[ingredients.size()-1];
    }
    cout << answer;
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; 
    cin >> n;
    ingredients.resize(n);
    for(int i=0; i<n; i++){

        cin >> ingredients[i];
    }    
    temp.resize(n-1);
    for(int i=0; i<n-1; i++){
        cin >> temp[i];
    }
    
    check_ingredient();
    return 0;
}