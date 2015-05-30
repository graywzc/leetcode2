class Solution {
public:
    combinationSum3(vector<vector<int>>& res, vector<int>& tmp, int n, int i, int k)
    {
        if(k>0 && i<=9)
        {
            int count = 0;
            while(n>=0 && (k-count)>=0)            
            {
                if(n==0)
                {
                    res.push_back(tmp); 
                    break;
                }
                else if(n>i)
                {
                    combinationSum3(res,tmp,n,i+1,k-count); 
                    tmp.push_back(i);
                    n-=i;
                    count++;
                }
                else
                    break;
            }

            while(count>0)
            {
                tmp.pop_back();
                count--; 
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if(k<=0 || n>k*9 || n<k*1) 
            return vector<vector<int>>();

        vector<vector<int>> res;
        vector<int> tmp;
        combinationSum3(res, tmp, n, 1, k);
    }
};
