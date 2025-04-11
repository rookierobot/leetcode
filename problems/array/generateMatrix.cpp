#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        fullLayer(0, 1, matrix, n);
        return matrix;
    }

    void fullLayer(int k, int cnt, vector<vector<int>>& matrix, int n) {
        int layer = n / 2;
        int flag = n % 2;
        if (k == layer) {
            if (flag == 1) {
                matrix[k][k] = cnt++;
                return ;
            }
            else {
                return ;
            }
        }
        if (cnt == n * n + 1) return ;
        for (int j = k; j < n - 1 - k; j++) {
            matrix[k][j] = cnt++;
        }
        for (int i = k; i < n - 1 - k; i++) {
            matrix[i][n - 1 - k] = cnt++;
        }
        for (int j = n - 1 - k; j > k; j--) {
            matrix[n - 1 - k][j] = cnt++;
        }
        for (int i = n - 1 - k; i > k; i--) {
            matrix[i][k] = cnt++;
        }
        fullLayer(k + 1, cnt, matrix, n);
        return ;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = sol.generateMatrix(4);
    for (auto row : matrix) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << endl;   
    }
    return 0;   
}   
