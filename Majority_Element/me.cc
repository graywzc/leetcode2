class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counts;        
        for(const int& n: nums)
        {
            counts[n]++; 
            if(counts[n]>(nums.size()/2))
                return n;
        }
    }
};
