class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.empty())
            return 0;

        vector<int> nc(ratings.size(), 1);
        int i = 1;
        while(i<ratings.size())
        {
            if(ratings[i] > ratings[i-1])
                nc[i] = nc[i-1] + 1;
            i++; 
        }

        i = ratings.size() - 2;
        while(i >= 0)
        {
            if(ratings[i] > ratings[i+1] && nc[i] <= nc[i+1])
                nc[i] = nc[i+1] + 1;
            i--; 
        }

        int count = 0;
        for(const int& n: nc)
            count += n;

        return count;
    }
};
