class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;            
        while(i>=0 && !isalpha(s[i]))
            i--;

        if(i<0)
            return 0;
        int j = i-1;
        while(j>=0 && isalpha(s[j]))
            j--;

        return i-j;
    }
};
