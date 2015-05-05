class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));       

        int i;
        int s;
        int count = 1;
        for(i=0,s=n;s>1;i++,s-=2)
        {
            for(int j=i;j<i+s-1;j++)     
                res[i][j] = count++;
            for(int j=i;j<i+s-1;j++)
                res[j][i+s-1] = count++;
            for(int j=i+s-1;j>i;j--)
                res[i+s-1][j] = count++;
            for(int j=i+s-1;j>i;j--)
                res[j][i] = count++;
        }

        if(s==1) res[i][i] = count++;
        return res;
    }
};
