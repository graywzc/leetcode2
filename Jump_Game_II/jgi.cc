class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)        
            return 0;

        int i = 0;
        int range = 0;
        int jumps = 0;
        
        while(i <= range)
        {
            int new_range = range;
            while(i <= range)
            {
                new_range = max(new_range,i + nums[i]);
                i++;      
            }
            jumps++;
            if(new_range>=nums.size()-1)
                return jumps;

            range = new_range;
        }

        return -1;
    }
};
