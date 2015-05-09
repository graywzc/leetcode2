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
            for(int j = i; j < nums.size(); j++) 
            {
                swap(nums[i],nums[j]); 
                permute(nums, i+1, res);
                swap(nums[i],nums[j]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())        
            return vector<vector<int>>();

        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
    }
};
