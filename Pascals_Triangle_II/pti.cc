class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;        
        if(rowIndex<0) return res;

        res.push_back(1);
        int i = 1;
        while(i<=rowIndex)
        {
            vector<int> temp(1,1);
            int j = 0;
            while(j<i-1)
            {
                temp.push_back(res[j]+res[j+1]); 
                j++;
            }
            temp.push_back(1);
            res = temp;
            i++; 
        }
        return res;
    }
};
