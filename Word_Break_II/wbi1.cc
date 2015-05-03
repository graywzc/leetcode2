
class Solution {
public:

    void build_solution(const string& s, const vector<vector<int> >& wb_vec, int size, int i, string& temp, vector<string>& res)
    {
        if(i == size) 
        {
            temp.pop_back();
            res.push_back(temp); 
        }
        else
        {
            int temp_size = temp.size();
            for(const int& n: wb_vec[i]) 
            {
                temp = temp+s.substr(i,n-i)+' ';       
                build_solution(s, wb_vec, size, n, temp, res);
                temp = temp.substr(0, temp_size);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {   
        if(s.empty()) return vector<string>();
        int size = s.size();
        vector<vector<int> > wb_vec(size+1);            
        vector<int> wb;
        wb.push_back(size);

        int i = size-1;
        while(i>=0)
        {
            int wb_size = wb.size();
            for(int j = 0; j < wb_size; j++) 
            {
                int n = wb[j];
                if(dict.find(s.substr(i,n-i))!=dict.end())
                {
                    if(wb_vec[i].empty()) 
                    {
                        wb.push_back(i); 
                        wb_vec[i].push_back(n);
                    }
                    else
                    {
                        wb_vec[i].push_back(n); 
                    }
                }
            }
            i--;
        }

        string temp;
        vector<string> res;
        build_solution(s, wb_vec, size, 0, temp, res);
        return res;
    }
};
