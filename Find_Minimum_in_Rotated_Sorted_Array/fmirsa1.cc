class Solution {
public:
    int findMin(vector<int>& nums) {
        assert(!nums.empty());

        int l = 0;
        int r = nums.size()-1;

        while(l<r)
        {
            int m = (l+r)/2;     

            if(nums[l] < nums[r])
                return nums[l];
            
            if(nums[m]>=nums[l])
                l = m+1;
            else
            {
                r = m;
                l++; // nums[l] cannot be minimum
            }
        }

        return nums[l];
    }
};
