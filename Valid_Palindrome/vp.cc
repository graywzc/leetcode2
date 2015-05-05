#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int i = 0, j = s.size()-1;        
        while(i<j)
        {
            while(i<j && !isalnum(s[i])) 
                i++;
            while(j>i && !isalnum(s[j]))
                j--;
            if(i==j)
                break;
            else if(tolower(s[i])!=tolower(s[j])) 
                return false;

            i++;j--;
        }

        return true;
    }
};

int main()
{
    string s("Bab");
    Solution so;
    cout<<so.isPalindrome(s)<<endl;

}
