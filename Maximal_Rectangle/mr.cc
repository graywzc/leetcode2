//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;

        int nRows = matrix.size();
        int nCols = matrix[0].size();

        int mr = 0;
        for(int row = 0; row < nRows; row++)        
        {
            for(int col = 0; col < nCols; col++)
            {
                int i = row; 
                int local_mr = 0;
                int bound = nCols;
                while(i<nRows && matrix[i][col]=='1')
                {
                    int j = col+1;
                    while(j<bound && matrix[i][j]=='1')
                        j++;
                    
                    bound = min(bound,j); 
                    local_mr = max(local_mr,(i-row+1)*(bound-col));
                    
                    i++; 
                }
                mr = max(mr,local_mr);
            }
        }

        return mr;
    }
};
