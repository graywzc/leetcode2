class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int lp = INT_MAX;        
        int mp = 0;
        for(const int& p: prices)
        {
            if(p < lp)
                lp = p;
            else
                mp = max(mp, p-lp); 
        }
        return mp;
    }
};
