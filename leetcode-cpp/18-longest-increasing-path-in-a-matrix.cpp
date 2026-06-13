#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> dp;

    int dfs(std::vector<std::vector<int>>& matrix, int i, int j, int prevElement) {
        if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size() || prevElement >= matrix[i][j])
            return 0;
        if (dp[i][j])
            return dp[i][j];

        std::pair<int, int> directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0} };

        int left = dfs(matrix, i + directions[0].first, j + directions[0].second, matrix[i][j]);
        int right = dfs(matrix, i + directions[1].first, j + directions[1].second, matrix[i][j]);
        int up = dfs(matrix, i + directions[2].first, j + directions[2].second, matrix[i][j]);
        int down = dfs(matrix, i + directions[3].first, j + directions[3].second, matrix[i][j]);

        return dp[i][j] = std::max({ left, right, up, down }) + 1;
    }

    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        dp = std::vector<std::vector<int>>(matrix.size(), std::vector<int>(matrix[0].size(), 0));

        int maxValue = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                maxValue = std::max(maxValue, dfs(matrix, i, j, -1));
            }
        }
        return maxValue;
    }
};

int main() {
    Solution sl;
    std::vector<std::vector<int>> matrix = { {9,9,4}, {6,6,8}, {2,1,1} };
    int path = sl.longestIncreasingPath(matrix);

    return 0;
}

//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//
//From each cell, you can either move in four directions : left, right, up, or down. You may not move diagonally or move outside the boundary(i.e., wrap - around is not allowed).
//
//Example 1:
//
//Input: matrix = [[9, 9, 4], [6, 6, 8], [2, 1, 1]]
//Output: 4
//Explanation: The longest increasing path is[1, 2, 6, 9].
//
//Example 2:
//
//Input: matrix = [[3, 4, 5], [3, 2, 6], [2, 2, 1]]
//Output: 4
//Explanation: The longest increasing path is[3, 4, 5, 6].Moving diagonally is not allowed.
//
//Example 3:
//
//Input: matrix = [[1]]
//Output: 1
//
//Constraints :
//
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 200
//0 <= matrix[i][j] <= 2^31 - 1