class Solution {
public:
    int numTrees(int n) {
        if(n<=0)
            return 0;

        vector<int> nt(n+1,0);
        nt[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= i-1; j++)
            {
                nt[i] += nt[j]*nt[i-1-j]; 
            }
        }
        return nt[n];
    }
};
