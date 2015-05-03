class Solution {
public:
    bool isOK(const vector<int>& pos, int row, int col)
    {
        int i = 0;      
        while(i<row)
        {
            if(pos[i] == col)
                return false;

            if(abs(col - pos[i]) == (row-i))
                return false;
            i++; 
        }
        return true;
    }
    void printSol(vector<vector<string> >& res, const vector<int>& pos)
    {
        vector<string> sol(pos.size(), string(pos.size(),'.'));
        int i = 0;
        while(i < pos.size())
        {
            sol[i][pos[i]] = 'Q';
            i++; 
        }
        res.push_back(sol);
    }
    int totalNQueens(int n) {
                
        if(n<1) return 0;
        int res = 0;

        vector<int> pos(n,0);
        
        int row = 0;
        int col = 0;
        while(row>=0)
        {
            if(col==n)
            {
                row--; 
                col = row>=0?(pos[row]+1):0;
            }
            else if(isOK(pos, row, col))     
            {
                pos[row] = col;         
                if(row == (n-1))
                {
                    res++;
                    row--;
                    col = row>=0?(pos[row]+1):0;
                }
                else
                {
                    row++; 
                    col = 0;
                }
                continue;
            }
            else
            {
                col++; 
            }
        }
        return res;                             
    }
};
