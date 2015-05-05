class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0;
        int twice = 0;
        int thrice = 0;

        for(const int n: nums)
        {
            int on = once;
            int tw = twice;
            int th = thrice;
            once += ((~(on|tw|th))&n) + (n&th) - (n&on);
            twice += (n&on) - (n&tw);
            thrice += (n&tw) - (n&th);
        }

        return once;

    }
};
