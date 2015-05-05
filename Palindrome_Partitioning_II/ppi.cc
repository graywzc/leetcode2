class Solution {
public:
    int minCut(string s) {
        if(s.size()<=1) return 0;
        int n = s.size();
        vector<vector<bool>> isPalin(n,vector<bool>(n,false));
        int i=0,j=0;
        while(i<n)
        {
            isPalin[i][i]=true;
            i++;
        }
        for(i=n-2;i>=0;i--)
            for(j=i+1;j<n;j++)  
                isPalin[i][j] = (s[i]==s[j])&&((j>i+1)?isPalin[i+1][j-1]:true);
        
        vector<int> mincut(n,INT_MAX);
        mincut[0] = 0;
        for(i=1;i<n;i++) 
        {
            for(j=i;j>0;j--)  
                if(isPalin[j][i])
                    mincut[i] = min(mincut[j-1]+1,mincut[i]);  
            if(isPalin[0][i])
                mincut[i] = 0;
        }

        return mincut[n-1];
    }
};
