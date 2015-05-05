class Solution {
public:
    void rs(const vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& res)
    {
        if(i==nums.size())
        {
            res.push_back(temp); 
        }
        else
        {
            rs(nums, i+1, temp, res); 
            temp.push_back(nums[i]);
            rs(nums, i+1, temp, res);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        if(nums.empty())
            return vector<vector<int>>(1,vector<int>());

        vector<vector<int>> res;
        sort(nums.begin(),nums.end());        

        vector<int> temp;
        rs(nums, 0, temp, res);
        return res;
    }
};
