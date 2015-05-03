class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> ht;        
        
        int lc = 0;
        for(const int n: nums)
        {
            if(ht.find(n)==ht.end())     
            {
                int upper = n;
                int lower = n;
                if(n!=INT_MAX && ht.find(n+1)!=ht.end())
                    upper = n+ht[n+1];
                if(n!=INT_MIN && ht.find(n-1)!=ht.end())
                    lower = n-ht[n-1];
                int nl = upper-lower+1;
                ht[upper] = nl;
                ht[lower] = nl;
                ht[n] = nl;
                lc = max(lc,nl);
            }
        }
        return lc;
    }
};
