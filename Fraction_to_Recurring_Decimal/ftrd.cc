#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    void div_lcd(long& a, long& b)
    {
        // get lcd
        long a1 = a;
        long b1 = b;
        assert(a1<b1);
        while(a1!=0) 
        {
            long tmp = b1%a1; 
            b1 = a1;
            a1 = tmp;
        }
        a/=b1;
        b/=b1;
    }

    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0)            
            return string("NAN");
        if(numerator == 0)
            return string("0");
        bool neg = true;
        if((denominator>0 && numerator>0)||(denominator<0 && numerator<0))
            neg = false;
        
        long numer = abs((long)numerator);
        long denom = abs((long)denominator);

        string result;
        if(neg) result+='-';
        result += to_string(numer/denom);

        long res = numer%denom;

        if(res!=0)
        {
            result += '.';
            string decimal;
            unordered_map<int,int> r2d; 
            div_lcd(res,denom);
            while(res!=0 && r2d.find(res)==r2d.end())
            {
                r2d[res] = decimal.size();      
                decimal += to_string(res*10/denom);
                res = (res*10)%denom;
            }
            
            if(res==0)
            {
                result += decimal; 
            }
            else
            {
                result += decimal.substr(0,r2d[res]);
                result += '(';
                result += decimal.substr(r2d[res]);
                result += ')';
            }
        }
        return result;
    }
};

int main()
{
    Solution ftd;    
    string res = ftd.fractionToDecimal(-1,INT_MIN);
    cout<<res<<endl;
}
