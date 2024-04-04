#include <bits/stdc++.h>
using namespace std;

int num;
int max_num = -1;

void make_big_num(vector<int> &arr, int currentNum = 0) {
    if (currentNum > num) return; // If currentNum exceeds num, stop recursion
    max_num = max(max_num, currentNum); // Update max_num with the largest number seen so far
    
    for (int i = 0; i < arr.size(); i++) {
        int nextNum = currentNum * 10 + arr[i]; // Generate the next number
        make_big_num(arr, nextNum); // Recurse with the new number
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n_size;
    cin >> num >> n_size;
    vector<int> arr(n_size);
    
    for(int &s : arr) cin >> s;
    
    make_big_num(arr); // Initialize recursion with currentNum = 0 by default
    
    cout << max_num << endl; // Print the result
    
    return 0;
}
