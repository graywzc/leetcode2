class Solution {
public:
    typedef pair<int,int> INTP;
    typedef queue<INTP> PQ;
    void flip(vector<vector<char>> &grid, int row, int col)
    {
        assert(row < grid.size()); 
        assert(col < grid[0].size());
        assert(grid[row][col] == '1');
        grid[row][col] = '0';
        PQ pq;
        pq.push(INTP(row,col));
        while(!pq.empty())
        {
            INTP p = pq.front(); 
            pq.pop();
            int r = p.first;
            int c = p.second;
            if(r>0 && grid[r-1][c]=='1')
            {
                grid[r-1][c] = '0';
                pq.push(INTP(r-1,c));
            }    
            if(r<(grid.size()-1) && grid[r+1][c]=='1')
            {
                grid[r+1][c] = '0';
                pq.push(INTP(r+1,c));
            }
            if(c>0 && grid[r][c-1]=='1')
            {
                grid[r][c-1] = '0';
                pq.push(INTP(r,c-1));
            }
            if(c<(grid[0].size()-1) && grid[r][c+1]=='1')
            {
                grid[r][c+1] = '0';
                pq.push(INTP(r,c+1));
            }
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        
        if(grid.empty() || grid[0].empty())
            return 0;

        int nRows = grid.size();
        int nCols = grid[0].size();
        int count = 0;
        for(int row = 0; row < nRows; row++)
            for(int col = 0; col < nCols; col++)
            {
                if(grid[row][col]=='1') 
                {
                    flip(grid,row,col); 
                    count++;
                }
            }
        return count; 
    }
};
