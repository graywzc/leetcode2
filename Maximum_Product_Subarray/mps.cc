// 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mp = INT_MIN;
        int max_pos = 0;
        int max_neg = 0;
        assert(!nums.empty());
        if(nums.size()==1) return nums[0];
        for(const int &n: nums)        
        {
            if(n == 0)     
            {
                max_pos = 0;
                max_neg = 0;
                mp=max(mp,max_pos);
            }
            else if(n>0)
            {
                max_pos = max(n*max_pos,n); 
                max_neg = n*max_neg;
                mp=max(mp,max_pos);
            }
            else if(n<0)
            {
                int tmp = max_pos;
                max_pos = n*max_neg; 
                max_neg = min(n*tmp,n);
                mp=max(mp,max_pos);
            }
        }
        return mp;
    }
};
