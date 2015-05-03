class Solution {
public:
    int findMin(const vector<int>& nums, int left, int right)
    {
        if(left==right)
            return nums[left];
        if(nums[left] < nums[right])     
            return nums[left];
        else if(nums[left]>nums[right])
        {
            int mid = (left+right)/2;

            if(nums[mid]<=nums[right])
                return findMin(nums,left+1,mid);
            else
                return findMin(nums,mid+1,right);
        }
        else
        {
            int mid = (left+right)/2;
            if(nums[mid]<nums[right])
                return findMin(nums,left+1,mid);
            else if(nums[mid]>nums[left])
                return findMin(nums,mid+1,right);
            else
                return findMin(nums,left+1,right);
        }
    }

    int findMin(vector<int>& nums) {
        assert(!nums.empty());
        return findMin(nums,0,nums.size()-1);        
    }
};
