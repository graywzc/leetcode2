// memory limit exceeded
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows < 1)
            return res;
        res.push_back(vector<int>(1,1));
        int i = 2;
        while(i<=numRows)
        {
            vector<int> temp(1,1);
            int j = 0;
            while(j<i-2)
            {
                temp.push_back(res.back()[j] + res.back()[j+1]);
                j++;
            }
            temp.push_back(1);
            res.push_back(temp);
            i++;  
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.generate(5);
    for(const vector<int>& v: res)
    {
        for(const int n: v)
            cout<<n<<" ";
        cout<<endl;
    }
}
