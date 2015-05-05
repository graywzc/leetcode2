class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0)
        {
            n = -n; 
            x = 1/x;
        }
        double res = 1;            
        double factor = x;
        int flag = 1;
        while(flag)
        {
            if(n&flag) 
            {
                res *= factor;      
            }
            flag = flag<<1;
            factor *= factor;
        }
        return res;
    }
};
