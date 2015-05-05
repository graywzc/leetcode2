class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty())
            return -1;
        int neg = 0;
        int idx = -1;
        int pos = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            int gain = gas[i] - cost[i];
            if(idx == -1)
            {
                if(gain<0)
                    neg+=gain;
                else
                {
                    pos+=gain;
                    idx = i;
                }
            }
            else
            {
                pos+=gain; 
                if(pos<0)
                {
                    idx = -1; 
                    neg += pos;
                    pos = 0;
                }
            }
        }

        return ((pos+neg)>=0)?idx:-1;
    }
};
