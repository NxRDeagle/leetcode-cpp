#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    //  Без ДП - это получится медленное решение скорость O(m × n × min(m,n)^2), т.е. O(n^4) !!!
    //  При 300+ строках не проходят часть тесткейсов по времени на LeetCode.
    
    //int maximalSquare(std::vector<std::vector<char>>& matrix) {
    //    int m = matrix.size();
    //    int n = matrix[0].size();
    //    int side = 0, currentSide = 0;
    //
    //    for (int i = 0; i < m; i++)
    //        for (int j = 0; j < n; j++)
    //            if (matrix[i][j] == '1')
    //            {
    //                currentSide = dfs(matrix, i, j, m, n, 1);
    //                side = currentSide > side ? currentSide : side;
    //            }
    //    return side * side;
    //}
    //int dfs(std::vector<std::vector<char>>& matrix, int startI, int startJ, int m, int n, int side) {
    //    for (int i = 0; i < side; i++)
    //        for (int j = 0; j < side; j++) {
    //            int newI = startI + i;
    //            int newJ = startJ + j;
    //            if (newI >= m || newJ >= n || matrix[newI][newJ] == '0') {
    //                return side - 1;
    //            }
    //        }
    //
    //    return dfs(matrix, startI, startJ, m, n, ++side);
    //}

    //  Динамич. программирование - дает линейную скорость выполнения отн. кол-ва ячеек:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int maxSide = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) 
                        dp[i][j] = 1;
                    else 
                        dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                    maxSide = std::max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }

};

#ifdef ACTIVE_MAIN
int main()
{
    Solution sl;
    std::vector<std::vector<char>> matrix = { {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
    sl.maximalSquare(matrix);

    return 0;
}
#endif

//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//Example 1:
//Input: matrix = [["1", "0", "1", "0", "0"], ["1", "0", "1", "1", "1"], ["1", "1", "1", "1", "1"], ["1", "0", "0", "1", "0"]]
//Output : 4
//
//Example 2:
//Input: matrix = [["0", "1"], ["1", "0"]]
//Output : 1
//
//Example 3:
//Input: matrix = [["0"]]
//Output : 0
//
//Constraints:
//
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 300
//matrix[i][j] is '0' or '1'.