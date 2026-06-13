#include <vector>
#include <queue>

class Solution {
public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) 
            return -1;

        std::queue<std::pair<std::pair<int, int>, int>> queue;
        queue.push({ {0, 0}, 1 });
        grid[0][0] = 1;

        int directions[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            int posX = current.first.first;
            int posY = current.first.second;
            int path = current.second;

            if (posX == n - 1 && posY == n - 1)
                return path;

            for (auto& direction : directions) {
                int movedPosX = posX + direction[0];
                int movedPosY = posY + direction[1];
                if (movedPosX >= 0 && movedPosX < n && movedPosY >= 0 && movedPosY < n && grid[movedPosX][movedPosY] == 0) {
                    grid[movedPosX][movedPosY] = 1;
                    queue.push({ {movedPosX, movedPosY}, path + 1 });
                }
            }
        }
        return -1;
    }
};

#ifdef ACTIVE_MAIN
int main() {
    Solution sl;

    std::vector<std::vector<int>> vec = { {0, 0, 0}, {1, 1, 0}, {1, 1, 0} };
    sl.shortestPathBinaryMatrix(vec);

    return 0;
}
#endif

//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix.If there is no clear path, return -1.
//
//A clear path in a binary matrix is a path from the top - left cell(i.e., (0, 0)) to the bottom - right cell(i.e., (n - 1, n - 1)) such that :
//
//All the visited cells of the path are 0.
//All the adjacent cells of the path are 8 - directionally connected(i.e., they are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
//
//Example 1:
//
//Input: grid = [[0, 1], [1, 0]]
//Output: 2
//
//Example 2:
//
//Input: grid = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
//Output: 4
//
//Example 3:
//
//Input: grid = [[1, 0, 0], [1, 1, 0], [1, 1, 0]]
//Output: -1
//
//Constraints:
//
//n == grid.length
//n == grid[i].length
//1 <= n <= 100
//grid[i][j] is 0 or 1