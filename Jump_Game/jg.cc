class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int range = 0;
        int target = nums.size()-1;
        while(i<=range)
        {
            range = max(range, i+nums[i]);
            if(range>=target)
                return true;
            i++;     
        }
        return false;

    }
};
