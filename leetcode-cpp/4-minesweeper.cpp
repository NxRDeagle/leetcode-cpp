#include <iostream>
#include <vector>

class Solution
{
private:
    int rows, cols;

    bool isValid(int row, int col)
    {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    int countMines(std::vector<std::vector<char>>& board, int row, int col)
    {
        int mines = 0;
        for (int dirRow = -1; dirRow <= 1; dirRow++)
            for (int dirCol = -1; dirCol <= 1; dirCol++)
            {
                if (dirRow == 0 && dirCol == 0) 
                    continue;
                int newRow = row + dirRow;
                int newCol = col + dirCol;
                if (isValid(newRow, newCol) && board[newRow][newCol] == 'M')
                    mines++;
            }
        return mines;
    }

    void clickBoard(std::vector<std::vector<char>>& board, int row, int col)
    {
        if (!isValid(row, col) || board[row][col] != 'E')
            return;

        int mines = countMines(board, row, col);

        if (mines > 0)
            board[row][col] = '0' + mines;
        else
        {
            board[row][col] = 'B';
            for (int dirRow = -1; dirRow <= 1; dirRow++)
                for (int dirCol = -1; dirCol <= 1; dirCol++)
                {
                    if (dirRow == 0 && dirCol == 0)
                        continue;
                    clickBoard(board, row + dirRow, col + dirCol);
                }
        }
    }

public:
    std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board,
        std::vector<int>& click)
    {
        rows = board.size();
        cols = board[0].size();

        int clickRow = click[0];
        int clickCol = click[1];

        if (board[clickRow][clickCol] == 'M')
        {
            board[clickRow][clickCol] = 'X';
            return board;
        }

        if (board[clickRow][clickCol] == 'E')
            clickBoard(board, clickRow, clickCol);

        return board;
    }
};

#ifdef ACTIVE_MAIN
int main()
{
    std::vector<std::vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };
    std::vector<int> click = { 3, 0 };

    Solution sl;
    auto result = sl.updateBoard(board, click);

	return 0;
}
#endif

//Let's play the minesweeper game!
//
//You are given an m x n char matrix board representing the game board where :
//
//'M' represents an unrevealed mine,
//'E' represents an unrevealed empty square,
//'B' represents a revealed blank square that has no adjacent mines(i.e., above, below, left, right, and all 4 diagonals),
//digit('1' to '8') represents how many mines are adjacent to this revealed square, and
//'X' represents a revealed mine.
//You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares('M' or 'E').
//
//Return the board after revealing this position according to the following rules :
//
//If a mine 'M' is revealed, then the game is over.You should change it to 'X'.
//If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
//If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit('1' to '8') representing the number of adjacent mines.
//Return the board when no more squares will be revealed.
//
//Example 1:
//Input: board = [["E", "E", "E", "E", "E"], ["E", "E", "M", "E", "E"], ["E", "E", "E", "E", "E"], ["E", "E", "E", "E", "E"]], click = [3, 0]
//Output : [["B", "1", "E", "1", "B"], ["B", "1", "M", "1", "B"], ["B", "1", "1", "1", "B"], ["B", "B", "B", "B", "B"]]
//
//Example 2:
//Input : board = [["B", "1", "E", "1", "B"], ["B", "1", "M", "1", "B"], ["B", "1", "1", "1", "B"], ["B", "B", "B", "B", "B"]], click = [1, 2]
//Output : [["B", "1", "E", "1", "B"], ["B", "1", "X", "1", "B"], ["B", "1", "1", "1", "B"], ["B", "B", "B", "B", "B"]]
//
//Constraints :
//
//    m == board.length
//    n == board[i].length
//    1 <= m, n <= 50
//    board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
//    click.length == 2
//    0 <= clickr < m
//    0 <= clickc < n
//    board[clickr][clickc] is either 'M' or 'E'.
