/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a")  false
isMatch("aa","aa")  true
isMatch("aaa","aa")  false
isMatch("aa", "*")  true
isMatch("aa", "a*")  true
isMatch("ab", "?*")  true
isMatch("aab", "c*a*b")  false
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
   
        const char *s_anchor=NULL;
        const char *p_anchor=NULL;
        while(*s)
        {
            if(*p == '?' || *p == *s)
            {
                s++; p++; 
            }
            else if(*p == '*')
            {
                s_anchor = s;     
                p++;
                p_anchor = p;
            }
            else if(s_anchor)
            {
                s = ++s_anchor;              
                p = p_anchor;
            }
            else
                return false;
        }

        while(*p)
        {
            if(*p!='*') return false;    
            p++;
        }

        return true;
    }
};
