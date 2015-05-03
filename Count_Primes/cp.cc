// time exceeded limit when n = 1500000
class Solution {
public:
    int countPrimes(int n) {
        assert(n>=0);            
        if(n<2) return 0;
        if(n==2) return 1;
        int count = 1;
        int i = 3;
        while(i < n)
        {
            int j = 3;
            bool flag = true;
            while(j <= sqrt(i) )
            {
                if(i%j==0)
                {
                    flag = false; 
                    break;
                }
                j+=2;
            }
            if(flag)
                count++;
            i+=2;
        }

        return count;
    }
};
