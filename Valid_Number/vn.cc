/*
 * Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/
// 1. space before and after string
// 2. "+","-", onece at beginning, once after "e", optional
// 3. ".", once before "e"
// 4. "e", once
// 5. "0-9", at least once before e
class Solution {
public:
    bool isNumber(const char *s) {
        if(s==NULL) return false;

        while(isspace(*s))
            s++;

        if(*s=='+' || *s=='-')
            s++;

        bool num_before_e=false;
        bool has_e=false;
        bool num_after_e=false;
        bool has_dot=false;
        while(*s!='\0' && !isspace(*s))
        {
            if(*s>='0' && *s<='9')     
            {
                if(!has_e)     
                    num_before_e=true;
                else
                    num_after_e=true;
            }
            else if(*s == '.')
            {
                if(has_dot || has_e) 
                    return false;     
                else
                    has_dot = true; 
            }
            else if(*s == 'e')
            {
                if(has_e) 
                    return false;
                else
                {
                    has_e=true;
                    if(*(s+1)=='+' || *(s+1)=='-')
                        s++;
                }
            }
            else
                return false;

            s++;
        }

        while(*s)
        {
            if(!isspace(*s)) return false;
            s++; 
        }

        return (num_before_e&&(!has_e||num_after_e));
    }
};
