class Solution {
public:


    void spiralOrder(const vector<vector<int>>& matrix,
                     int nRows,
                     int nCols,
                     int iRow,
                     int iCol,
                     vector<int> & res) 
    {
        if(nRows==0||nCols==0)
            return;
        else if(nRows == 1)
            for(int i = iCol; i < iCol+nCols; i++) 
                res.push_back(matrix[iRow][i]);
        else if(nCols == 1)
            for(int i = iRow; i < iRow+nRows; i++)
                res.push_back(matrix[i][iCol]);
        else
        {
            for(int i = iCol; i < iCol+nCols-1; i++) 
                res.push_back(matrix[iRow][i]);
            for(int i = iRow; i < iRow+nRows-1; i++)
                res.push_back(matrix[i][iCol+nCols-1]);
            for(int i = iCol+nCols-1; i>iCol; i--)
                res.push_back(matrix[iRow+nRows-1][i]);
            for(int i = iRow+nRows-1; i>iRow; i--)
                res.push_back(matrix[i][iCol]);
            spiralOrder(matrix, nRows-2, nCols-2, iRow+1, iCol+1, res);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty())
            return res;
        int nRows = matrix.size();
        int nCols = matrix[0].size();

        spiralOrder(matrix, nRows, nCols, 0, 0, res);
        return res;

    }
};
