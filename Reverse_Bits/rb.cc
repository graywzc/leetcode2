class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t flag = 1;
        while(flag)
        {
            res = res<<1;
            if(n&flag)
                res += 1;
            flag = flag<<1;
        }
        return res;
    }
};
