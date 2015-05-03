class Solution {
public:
    void reverseWords(string &s) {
        int offset = 0; 
        int i, j=-1;
        while(1)
        {
            i = j+1;
            while(i<s.size() && isspace(s[i])) 
                i++;

            if(i>=s.size()) break;

            j = i+1;
            while(j<s.size() && !isspace(s[j]))
                j++;

            reverse(s.begin()+i,s.begin()+j);
            copy(s.begin()+i,s.begin()+j,s.begin()+offset);
            offset += j-i;
            s[offset] = ' ';
            offset++;
        }
        s.resize((offset==0)?0:offset-1);
        reverse(s.begin(),s.end());
    }
};
