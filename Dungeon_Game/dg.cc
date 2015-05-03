class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        assert(m>0);
        int n = dungeon[0].size();
        assert(n>0);


        dungeon[m-1][n-1] = (1-dungeon[m-1][n-1])>0?(1-dungeon[m-1][n-1]):1;
        
        int row = m-2;
        while(row >= 0)
        {
            dungeon[row][n-1] = dungeon[row+1][n-1] - dungeon[row][n-1];
            if(dungeon[row][n-1]<=0) dungeon[row][n-1] = 1;
            row--;     
        }
        int col = n-2;
        while(col >= 0)
        {
            dungeon[m-1][col] = dungeon[m-1][col+1] - dungeon[m-1][col];
            if(dungeon[m-1][col]<=0) dungeon[m-1][col] = 1;
            col--;
        }
        row = m-2;
        while(row >= 0)
        {
            col = n-2;
            while(col>=0)
            {
                dungeon[row][col] = min(dungeon[row+1][col], dungeon[row][col+1]) - dungeon[row][col];
                if(dungeon[row][col]<=0) dungeon[row][col] = 1;
                col--; 
            }
            row--; 
        }

        return dungeon[0][0];
    }
};
