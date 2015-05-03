class Solution {
public:
    int numDistinct(string S, string T) {
        typedef vector<int> IntVec;
        typedef vector<IntVec> IntVecVec;

        int ns = S.size();
        int nt = T.size();

        if(nt > ns) return 0;
        if(nt == 0) return 1;

        IntVecVec nd(nt, IntVec(ns+1, 0));
        nd.push_back(IntVec(ns+1, 1));
        int i = nt - 1;
        while(i >= 0)
        {
            int j = ns-nt+i;
            while(j >= 0) 
            {
                nd[i][j] = nd[i][j+1] + (S[j]==T[i]?nd[i+1][j+1]:0);
                j--; 
            }
            
            i--; 
        }

        return nd[0][0];
    }
};
