class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // bool arrays default to false. Size 9x9 handles digits 1-9 (mapped to 0-8)
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        
        // A 3D array for the boxes: [box_row][box_col][digit]
        bool boxes[3][3][9] = {false};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                
                // Convert char '1'-'9' into integer index 0-8
                int curr = board[r][c] - '1';
                
                // 1. Check if we have seen it before
                if (rows[r][curr] || cols[c][curr] || boxes[r/3][c/3][curr]) {
                    return false; // Duplicate found!
                }
                
                // 2. Mark it as seen
                rows[r][curr] = true;
                cols[c][curr] = true;
                boxes[r/3][c/3][curr] = true;
            }
        }
        
        return true;
    }
};