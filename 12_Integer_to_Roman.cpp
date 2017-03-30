/*
1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

1000~3000: {"M", "MM", "MMM"}.
*/
class Solution {
public:
    string intToRoman(int num) {
            string sym[4][10]={
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
                {"", "M", "MM", "MMM"} 
            },str="";
            int cnt=0;
            while(num){
                str=sym[cnt++][num%10]+str;
                num/=10;
            }
            return str;
    }
};