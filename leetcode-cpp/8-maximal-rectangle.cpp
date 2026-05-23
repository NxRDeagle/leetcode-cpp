#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        std::vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = std::max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

#ifdef ACTIVE_MAIN
int main()
{
    Solution sl;
    std::vector<std::vector<char>> matrix = { {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
    sl.maximalRectangle(matrix);

    return 0;
}
#endif

//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//Example 1:
//Input: matrix = [["1", "0", "1", "0", "0"], ["1", "0", "1", "1", "1"], ["1", "1", "1", "1", "1"], ["1", "0", "0", "1", "0"]]
//Output : 6
//
//Example 2:
//
//Input: matrix = [["0"]]
//Output : 0
// 
//Example 3 :
//Input : matrix = [["1"]]
//Output : 1
//
//Constraints:
//rows == matrix.length
//cols == matrix[i].length
//1 <= rows, cols <= 200
//matrix[i][j] is '0' or '1'.
