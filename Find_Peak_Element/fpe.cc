class Solution {
public:
    int fpe(const vector<int>& nums, int left, int right)
    {
        assert(left<=right);
        if(left==right) 
            return left;
        else
        {
            int mid = (left+right)/2; 
            if(mid==0 || nums[mid]>nums[mid-1])  
            {
                if(nums[mid]>nums[mid+1]) 
                    return mid;
                else
                    return fpe(nums,mid+1,right);
            }
            else
                return fpe(nums,left,mid-1);
                
        }
    }
    int findPeakElement(vector<int>& nums) {
        assert(!nums.empty());
        return fpe(nums, 0, nums.size()-1);        
    }
};
