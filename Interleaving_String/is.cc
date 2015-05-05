class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size())!=s3.size())        
            return false;

        int s1s = s1.size();
        int s2s = s2.size();
        int s3s = s3.size();

        vector<vector<bool>> il(s1s+1,vector<bool>(s2s+1,false));

        il[0][0] = true;
        for(int i = 1; i <= s1s; i++)
            il[i][0] = il[i-1][0]&&s1[i-1]==s3[i-1]; 
        for(int i = 1; i <= s2s; i++)
            il[0][i] = il[0][i-1]&&s2[i-1]==s3[i-1];

        for(int i = 1; i <= s1s; i++)
            for(int j = 1; j <= s2s; j++)
                il[i][j] = (s3[i+j-1]==s1[i-1]&&il[i-1][j])||(s3[i+j-1]==s2[j-1]&&il[i][j-1]); 
        
        return il[s1s][s2s];
    }
};
