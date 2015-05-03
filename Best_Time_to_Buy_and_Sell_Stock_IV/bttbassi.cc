#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    static int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();            
        if(n<=1 || k<1) return 0;

        vector<int> mps(n,0);
        vector<int> mpb(n-1,0);
        
        int mp = INT_MIN;
        k = min(k,n-1);
        for(int l = 1; l <= k; l++)
        {
            int temp_max = INT_MIN;
            for(int i = l-1; i < n-1; i++) 
            {
                temp_max = max(temp_max,mps[i]);
                mpb[i] = temp_max - prices[i];
            }

            temp_max = INT_MIN;
            for(int i = l; i < n; i++)
            {
                temp_max = max(temp_max, mpb[i-1]); 
                mps[i] = temp_max + prices[i];
            }
            
            mp = max(mp,mps[n-1]);
        }
        
        return mp;
    }
};

int main()
{
    int p[] = {1,3,2,4,1,6,7};
    int k = 4;
    vector<int> prices(p, p + sizeof(p)/sizeof(int));
    cout<<Solution::maxProfit(k,prices)<<endl;
}
