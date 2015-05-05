class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msa = nums[0];        
        int local_max = nums[0];
        int i = 1;
        while(i<nums.size())
        {
            local_max = local_max>0?(local_max + nums[i]):nums[i];
            msa = max(msa,local_max);
            i++; 
        }
        return msa;
    }
};
