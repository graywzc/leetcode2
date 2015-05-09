class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1==0) return n2;
        if(n2==0) return n1;

        vector<vector<int>> md(1+n1,vector<int>(1+n2,0));        
        for(int i = 1; i <= n2; i++)
            md[0][i] = i;
        for(int i = 1; i <= n1; i++)
            md[i][0] = i;

        for(int i = 1; i <= n1; i++)
            for(int j = 1; j <= n2; j++)
            {
                if(word1[i-1]==word2[j-1])     
                    md[i][j] = md[i-1][j-1]; 
                else
                    md[i][j] = 1+min(min(md[i-1][j],md[i][j-1]),md[i-1][j-1]); 
            }
      
        return md[n1][n2];
    }
};
