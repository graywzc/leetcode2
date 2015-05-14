class Solution {
public:

    int findMin(vector<int>& nums) {
        assert(!nums.empty());
        
        int l = 0;
        int r = nums.size()-1;

        whlie(l<r)
        {
            if(nums[l]<nums[r])     
                return nums[l];
            if(nums[l]==nums[r])
            {
                l++; 
                continue;
            }
            
            int mid = (l+r)/2;
            if(nums[mid]>=nums[l])
            {
                l = mid+1; 
            }
            else
            {
                r = mid; 
                l++;
            }
        }
        return nums[l];
    }
};
