class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;

        int n = nums.size();        
        int i = 0;
        while(i<n)
        {
            if(nums[i]<=0)
                nums[i] = n+1;
            i++; 
        }
        i = 0;
        while(i<n)
        {
            if(abs(nums[i])<=n && nums[abs(nums[i])-1]>0) 
                nums[abs(nums[i])-1] *= -1;
            i++;
        }
        i = 0;
        while(i<n)
        {
            if(nums[i]>0) return i+1;
            i++;
        }

        return n+1;
    }
};
