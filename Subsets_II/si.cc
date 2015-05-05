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
            int j = i+1; 
            while(j<nums.size() && nums[j]==nums[i])
                j++;
            
            rs(nums,j,temp,res);
            int count = j-i;
            while(count>0)
            {
                temp.push_back(nums[i]); 
                rs(nums,j,temp,res);
                count--;
            }
            count = j-i;
            while(count>0)
            {
                temp.pop_back(); 
                count--;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty())        
            return vector<vector<int>>(1, vector<int>());

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        rs(nums,0,temp,res);
        return res;
    }
};
