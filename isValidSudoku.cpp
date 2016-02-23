bool isValidSudoku(vector<vector<char>>& board) {
        
        const int cnt = 9;
        bool row_mask[cnt][cnt] = {false};
        bool col_mask[cnt][cnt] = {false};
        bool box_mask[cnt][cnt] = {false};
        
        //check each rows and cols
        for(int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[r].size(); c++){
                if (!isdigit(board[r][c])) continue;  // if board[r][c] is not one of '0' ... '9', i.e., is blank '.', stop                                          current iteration, forward to next iteration, i.e. c++
                
                int idx =  board[r][c] - '0' - 1;   // idx can only be 0 to 8 for a 9-9 matrix
                
                //check the rows
                if (row_mask[r][idx] == true){   // if row r has two 5's
                    return false;
                }
                row_mask[r][idx] = true;
                
                //check the cols
                if (col_mask[c][idx] == true) {  // if column c has two 5's
                    return false;
                }
                col_mask[c][idx] = true;
                
                //check the areas
                int box = (r/3) * 3 + (c/3);  // the box where board[r][c] is located, e.g., board[4][5] is in box 4 (box is                                 from 0 to 8) 
                if (box_mask[box][idx] == true) {
                    return false;
                }
                box_mask[box][idx] = true;
            }
        }
        
        return true;
        
    }
