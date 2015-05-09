class Solution {
public:
    void permute(vector<int>& nums, int i, vector<vector<int>>& res)
    {
        if(i == nums.size()-1) 
        {
            res.push_back(nums); 
        }
        else
        {
            permute(nums,i+1,res);
            int j = i+1;
            while(1) 
            {
                while(j<nums.size() && nums[j]==nums[i]) 
                    j++;

                if(j==nums.size())
                    break;

                swap(nums[i],nums[j]);
                permute(nums, i+1, res);
                j++;
            }
            int tmp = nums[i];
            j = i+1;
            while(j<nums.size())
            {
                nums[j-1] = nums[j]; 
                j++;
            }
            nums[j-1] = tmp;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        if(nums.empty())
            return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
    }
};
