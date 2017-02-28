
/*
除回去来判断是否溢出
22ms
Your runtime beats 31.24% of cpp submissions.
*/
class Solution {
public:
    int reverse(int x) {
        int rs=0,tmp;
        while(x){
            tmp=rs*10+x%10;
            if(tmp/10!=rs)return 0;
            rs=tmp;
            x/=10;
        }
        return rs;
    }
};