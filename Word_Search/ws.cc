class Solution {
public:

    bool bt(vector<vector<char>>& board, int row, int col, string word, int idx)
    {
        if(idx == word.size()-1) 
            return true;

        const char c = word[idx];
        board[row][col] = '\0';
        
        if(row > 0 && board[row-1][col]==word[idx+1] && bt(board,row-1,col,word,idx+1))
            return true;
        if(row < board.size()-1 && board[row+1][col]==word[idx+1] && bt(board,row+1,col,word,idx+1))
            return true;
        if(col > 0 && board[row][col-1]==word[idx+1] && bt(board,row,col-1,word,idx+1))
            return true;
        if(col < board[0].size()-1 && board[row][col+1]==word[idx+1] && bt(board,row,col+1,word,idx+1))
            return true;
        
        board[row][col] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())        
            return true;

        unsigned nRows = board.size();
        if(nRows==0) return false;
        unsigned nCols = board[0].size();
        if(nCols==0) return false;

        for(int i = 0; i < nRows; i++)
            for(int j = 0; j < nCols; j++)
                if(board[i][j] == word[0] && bt(board,i,j,word,0))
                    return true;
                
        return false;
    }
};
