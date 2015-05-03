class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        assert(m>=0);                     
        assert(m<=n);
        assert(n<=INT_MAX);

        int count = 0;
        int res;
        while(m>0)
        {
            if(m==n)  
            {
                res = m;   
                break;
            }
            else
            {
                m = m>>1;         
                n = n>>1;
                count++;
            }
        }

        if(m==0) 
            return 0;
        else
        {
            while(count>0)  
            {
                res = res<<1; 
                count--;
            }
            return res;
        }
    }
};
