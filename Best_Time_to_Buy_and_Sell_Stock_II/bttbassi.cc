class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i = 1;        
        int mp = 0;
        while(i < prices.size())
        {
            if(prices[i] > prices[i-1])
                mp += (prices[i] - prices[i-1]);
            i++; 
        }
        return mp;
    }
};
