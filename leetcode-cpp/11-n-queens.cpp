#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> res;

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(std::vector<std::string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(std::vector<std::string>& board, int row, int col) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;
        for (int i = 1; i <= std::min(row, col); i++)
            if (board[row - i][col - i] == 'Q')
                return false;
        for (int i = 1; i <= std::min(row, (int)board.size() - 1 - col); i++)
            if (board[row - i][col + i] == 'Q')
                return false;
        return true;
    }
};

int main() {
    Solution sl;
    sl.solveNQueens(5);

    return 0;
}

//The n - queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//
//Given an integer n, return all distinct solutions to the n - queens puzzle.You may return the answer in any order.
//
//Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
//
//Example 1:
//
//Input: n = 4
//Output : [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
//Explanation : There exist two distinct solutions to the 4 - queens puzzle as shown above
//
//Example 2:
//
//Input : n = 1
//Output : [["Q"]]
