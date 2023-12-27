#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isNumber(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    int myAtoi(string s) {
        int res = 0; // stores the result 
        int op = 0;  //number of '-' and '+' if ther is 2 then return 0 
        int pos = 1; // check if it is positive 
        int size = s.size(); // size of string
        int index = 0;// index 


        // to skip whitespace  ' '
        while (index < size && s[index] == ' ')
        {
            ++index;
        }

        // if first item after skip whitespace is '-'
        if (s[index] == '-')
        {
            op++;
            pos *= -1;
            index++;
        }

        // if first item after skip whitespace is '+'
        if (s[index] == '+')
        {
            op++;
            index++;
        }

        // insert number in res
        while (index < size && isNumber(s[index])) //this loop will break if s[i]!=int
        {
            int num = s[index] - 48; // to convert string into number:-----------------> // STRING IN ASCII: '0' = 48 , '1' = 49 , '2' = 50....'9' = 57
            //or int num =s[index] - '0';                                                                             
                                                                                               // NUMBER IN ASCII: 1 = 1 , 2 = 2 , 3 = 3......9 = 9      

                                                                                               // then to covert string to number:   [string]-'0'

                                                                                               //  '2' - '0' = 2 [int]                                                                 
                                                                                               //   48 - 46  = 2 [int]


            if (res > (INT_MAX - num) / 10)  // check if res is out of range [-2 pow(31) , 2 pow(31) - 1]
            {
                return (pos == 1) ? INT_MAX : INT_MIN;  // if Number is positive '+' return INT_MAX         
                // and if Number is negative '-' return INT_MIN
            }
            //NOTE: INT_MIN = -2 pow(31) - 1  =-2147483648
            //      INT_MAX =  2 pow(31)      = 2147483648


            res = (res * 10) + num;       // to add the num to res
            ++index;
        }

        // if there is two operator of '+' or '-'
        if (op == 2)
        {
            return 0;
        }
        // return res and multiply by pos (1 or -1)
        return static_cast<int>(res) * pos;
    }
};
int main()
{
Solution a;
cout<<a.myAtoi("4568hd5");

}