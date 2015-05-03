class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;        

        int size = prices.size();
        vector<int> lmp(size, 0);

        int i = 1;
        int lp = prices[0];
        while(i < size)
        {
            if(prices[i] < lp) 
            {
                lp = prices[i];
                lmp[i] = lmp[i-1];
            }
            else
            {
                lmp[i] = max(lmp[i-1], prices[i]-lp); 
            }
                
            i++;
        }

        i = size - 2;
        lp = prices[size-1];
        int mp = lmp[size-1];
        lmp[size-1] = 0;
        while(i >= 0)
        {
            if(prices[i] > lp) 
            {
                lp = prices[i]; 
                mp = max(mp, lmp[i] + lmp[i+1]);
                lmp[i] = lmp[i+1];
            }
            else
            {
                mp = max(max(lmp[i+1], lp - prices[i]) + lmp[i], mp);
                lmp[i] = max(lmp[i+1], lp - prices[i]);
            }

            i--; 
        }

        return mp;
    }
};
