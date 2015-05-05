class Solution {
public:
    bool isValid(const string&  s)
    {
        if(s.size()>=1 && s.size()<=3 && (s[0]!='0' || s.size()==1) && stoi(s)>=0 && stoi(s) <=255)
            return true;
        else
            return false;
    }

    void ria(const string& s, string& temp, int i, int n, vector<string>& res)
    {
        if(i>=s.size())
            return;
        if(n==0)     
        {
            if(isValid(s.substr(i))) 
            {
                res.push_back(temp+s.substr(i));    
            }
        }
        else
        {
            if(i==s.size()-1) return;

            int j = i;
            while(j<min((int)s.size()-1,i+3))
            {
                if(isValid(s.substr(i,j-i+1)))
                {
                    temp += s.substr(i,j-i+1); 
                    temp += '.';
                    ria(s,temp,j+1,n-1,res);
                    temp.pop_back();
                    while(!temp.empty() && temp.back()!='.')
                        temp.pop_back();
                }
                j++; 
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        
        string temp;
        if(n>=4 && n<= 12)
            ria(s,temp,0,3,res);

        return res;
    }
};
