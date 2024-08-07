#include <iostream>
#include <vector>

using namespace std;

string create_bingo_grid(int n, int k) {
    if (k > n * n) {
        return "NO";
    }
    
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    
    int count = 0;
    for (int i = 0; i < n && count < k; ++i) {
        for (int j = 0; j < n && count < k; ++j) {
            if ((i + j) % 2 == 0) {
                grid[i][j] = '#';
                count++;
            }
        }
    }
    
    if (count < k) {
        return "NO";
    }
    
    string result = "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result += grid[i][j];
        }
        result += '\n';
    }
    
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << create_bingo_grid(n, k);
    return 0;
}
