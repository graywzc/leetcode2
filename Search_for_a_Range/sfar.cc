class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())        
            return vector<int>(2,-1);

        int l = -1;
        int r = nums.size()-1;
        while((l+1)<r)
        {
            int m = (l+r)/2; 
            if(target <= nums[m])
                r = m;   
            else
                l = m;
        }
        if(target != nums[r])
            return vector<int>(2,-1);

        vector<int> res(1,r);

        l = 0;
        r = nums.size();
        while((l+1)<r)
        {
            int m = (l+r)/2; 
            if(target>=nums[m])
                l = m;
            else
                r = m;
        }
        assert(target == nums[l]);
        res.push_back(l);

        return res;
            
    }
};
