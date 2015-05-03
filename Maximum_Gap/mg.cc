class Solution {
public:

    void counting_sort(vector<int> &num, int nbit, int shift)
    {
        int size = 1<<nbit;
        vector<int> count(size, 0);  
        vector<int> copy(num.size());
        for(const int& n: num)
        {
            int key = (n>>shift)&15;     
            count[key]++;
        }
        int i=1;
        while(i < size)
        {
            count[i] += count[i-1]; 
            i++; 
        }
        i = num.size()-1; 
        while(i>=0)
        {
            int key = (num[i]>>shift)&15;
            count[key]--;
            copy[count[key]] = num[i];
            i--; 
        }
        num = copy;
    }

    int maximumGap(vector<int> &num) {
        
        if(num.size()<=1) return 0;

        int bit_size = 32;    
        int nbit = 4;
        int shift = 0;
        while(shift < bit_size) 
        {
            counting_sort(num, nbit, shift);
            shift+=nbit; 
        }

        int mg = 0;
        int i = 1;
        while(i < num.size())
        {
            if(mg < (num[i] - num[i-1]))
                mg = num[i] - num[i-1];
            i++; 
        }
        return mg;
    }
};
