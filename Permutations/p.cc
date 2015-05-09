class Solution {
public:
    void permute(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& res)
    {
        if(i == nums.size()-1)     
        {
            temp.push_back(nums[i]);
            res.push_back(temp); 
            temp.pop_back();
        }
        else
        {
            for(int j = i; j < nums.size(); j++) 
            {
                swap(nums[i],nums[j]); 
                temp.push_back(nums[i]);
                permute(nums, i+1, temp, res);
                swap(nums[i],nums[j]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())        
            return vector<vector<int>>();

        vector<vector<int>> res;
        vector<int> temp;

        permute(nums, 0, temp, res);
        return res;
    }
};
