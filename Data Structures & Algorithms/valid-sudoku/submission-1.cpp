class Solution {
public:
//LOGIC: use coolean arrays to check if a number is a duplicate or not
//[10] to make indexing easier as each number will be in its corresponding clock
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c] == '.') continue;
                //use -'0' to convert string into integer
                int num = board[r][c] - '0';
                //use this formula to reduce coordinates like (2,4) into its repective box number
                int boxIndex = (r/3) * 3 + (c/3);
                if(rows[r][num] || cols[c][num] || boxes[boxIndex][num]) return false;
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }
        return true;
    }
};
