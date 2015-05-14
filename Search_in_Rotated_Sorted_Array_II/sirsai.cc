class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())        
            return -1;

        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r)
        {
            int m = (l+r)/2; 
            if(target == nums[m])
                return true;
            
            if(nums[l] == nums[r])
            {
                l++;
                continue;
            }

            if(nums[m]>=nums[l])
            {
                if(nums[l]<=target && target<nums[m]) 
                    r = m-1;
                else
                    l = m+1;
            }
            else
            {
                if(nums[m] < target && target <= nums[r])
                    l = m+1;
                else
                    r = m-1;
            }
            
        }
        return false;
    }
};
