/*
189 ms
Your runtime beats 38.11% of cpp submissions.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0&&x%10==0)) return false;
        int rx=0;
        while(x/10>rx){
            rx=rx*10+x%10;
            x/=10;
        }
        if(x==rx||x/10==rx)return true;
        else return false;
    }
};